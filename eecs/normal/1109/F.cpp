#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, a[1010][1010];
pair<int, int> mp[maxn];
vector<int> G[maxn];

namespace LCT {
int fa[maxn], ch[maxn][2], tag[maxn];
bool get(int x, bool dir = 1) { return x == ch[fa[x]][dir]; }
bool is_root(int x) { return !get(x, 0) && !get(x); }

void rotate(int x) {
    int y = fa[x], z = fa[y], d = get(x);
    if (!is_root(y)) ch[z][get(y)] = x;
    fa[ch[y][d] = ch[x][!d]] = y, ch[x][!d] = y;
    fa[y] = x, fa[x] = z;
}

void pushdown(int x) {
    if (!tag[x]) return;
    tag[ch[x][0]] ^= 1, tag[ch[x][1]] ^= 1;
    swap(ch[x][0], ch[x][1]), tag[x] = 0;
}

void splay(int x) {
    static int tp, st[maxn];
    st[tp = 1] = x;
    for (int y = x; !is_root(y); st[++tp] = y = fa[y]);
    while (tp) pushdown(st[tp--]);
    for (; !is_root(x); rotate(x)) if (!is_root(fa[x])) {
        rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
    }
}

void access(int x) {
    for (int t = 0; x; t = x, x = fa[x]) {
        splay(x), ch[x][1] = t;
    }
}

void make_root(int x) { access(x), splay(x), tag[x] ^= 1; }
void link(int x, int y) { make_root(x), fa[x] = y; }
void split(int x, int y) { make_root(x), access(y), splay(y); }
void cut(int x, int y) { split(x, y), fa[x] = ch[y][0] = 0; }

bool test(int x, int y) {
    split(x, y);
    while (1) {
        pushdown(y);
        if (ch[y][0]) y = ch[y][0];
        else break;
    }
    splay(y); return x == y;
}
}  // namespace LCT

namespace SEG {
#define mid (l + r >> 1) 
#define ls (k << 1)
#define rs (k << 1 | 1)
int tag[maxn << 2];
struct node {
    int mn, cnt;
    node operator + (const node &o) const {
        node a; a.mn = min(mn, o.mn);
        a.cnt = (mn == a.mn) * cnt + (o.mn == a.mn) * o.cnt;
        return a;
    }
} t[maxn << 2];

void pushdown(int k) {
    t[ls].mn += tag[k], tag[ls] += tag[k];
    t[rs].mn += tag[k], tag[rs] += tag[k], tag[k] = 0;
}

void build(int k, int l, int r) {
    t[k].mn = 0, t[k].cnt = r - l + 1;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { t[k].mn += v, tag[k] += v; return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    t[k] = t[ls] + t[rs];
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (tag[k]) pushdown(k);
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
}
}  // namespace SEG

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]), mp[a[i][j]] = {i, j};
        }
    }
    SEG::build(1, 1, n * m);
    long long ans = 0;
    for (int i = 1, j = 1; i <= n * m; i++) {
        SEG::add(1, 1, n * m, 1, i, 1);
        int x = mp[i].first, y = mp[i].second;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] > i) continue;
            SEG::add(1, 1, n * m, 1, a[nx][ny], -1);
            for (; LCT::test(i, a[nx][ny]); j++) {
                for (int v : G[j]) LCT::cut(j, v);
            }
            if (a[nx][ny] >= j) G[a[nx][ny]].push_back(i), LCT::link(i, a[nx][ny]);
        }
        auto p = SEG::query(1, 1, n * m, j, i);
        if (p.mn == 1) ans += p.cnt;
    }
    printf("%lld\n", ans);
    return 0;
}