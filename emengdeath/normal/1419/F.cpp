#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e3 + 10;
const long long inf = 1e18;
int n;
long long a[N][2];
int fa[N];
int bz[N];
int c[N * 100];
struct node{
    bool v[1<<4];
    int tag[4];
    void clear() {
        memset(tag, 0, sizeof(tag));
        memset(v, 0, sizeof(v));
        v[0] = 1;
    }
}f[N * 1000];
long long dis(long long *a, long long *b) {
    if (a[0] != b[0] && a[1] != b[1]) return inf;
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
int getfa(int x) {
    return fa[x] == x?  x : fa[x] = getfa(fa[x]);
}
void upd(int l, int r, int s) {
    if (l == r) {
        memset(f[s].v, 0, sizeof(f[s].v));
        f[s].v[0] = 1;
    } else {
        for (int i = 0; i < (1 << 4); i ++)
            f[s].v[i] = (f[s + s].v[i]| f[s+s+1].v[i]);
    }
    for (int i = 0; i < 4; i ++)
        if (f[s].tag[i])
            for (int j = 0; j < (1 << 4); j ++)
                f[s].v[j | (1 << i)] |= f[s].v[j];
}
void ins(int l, int r, int s, long long ll, long long rr, int sig, int v) {
    if (c[r] < ll || rr < c[l]) return;
    if (ll <= c[l] && c[r] <= rr) {
        f[s].tag[v] += sig;
        upd(l, r, s);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, sig, v);
    ins((l + r) / 2 + 1, r, s + s + 1, ll, rr, sig, v);
    upd(l, r, s);
}
bool check(long long len) {
    for (int i = 1; i <= n; i ++) fa[i] = i, bz[i] = -1;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (dis(a[i], a[j]) <= len && getfa(i) != getfa(j)) {
                fa[fa[i]] = j;
            }
    int cnt = -1;
    for (int i = 1; i <= n; i ++)
        if (getfa(i) == i) {
            if (bz[i] == -1) bz[i] = ++cnt;
        }
    if (cnt > 4) return 0;
    vector<pair<pair<long long, pair<int, int> >, pair<long long, long long> > > q;
    c[0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        q.push_back({{a[i][0] - len, {1, bz[getfa(i)]}},{a[i][1], a[i][1]}});
        q.push_back({{a[i][0] + len + 1, {-1, bz[getfa(i)]}},{a[i][1], a[i][1]}});
        q.push_back({{a[i][0],{1, bz[getfa(i)]}}, {a[i][1] - len, a[i][1] + len}});
        q.push_back({{a[i][0] + 1,{-1, bz[getfa(i)]}}, {a[i][1] - len, a[i][1] + len}});
        c[++c[0]] = a[i][1];
        c[++c[0]] = a[i][1] - len;
        c[++c[0]] = a[i][1] + len;
    }
    sort(c + 1, c  + c[0] + 1);
    int tmp = c[0];
    c[0] = 1;
    for (int i = 2; i <= tmp; i ++)
        if (c[c[0]] != c[i]) c[++c[0]] = c[i];
    sort(q.begin(), q.end());
    long long lastx = -1e12;
    for (int i = 1; i <= 4 * c[0]; i ++) f[i].clear();
    for (auto u:q)
    {
        if (u.first.first != lastx) {
            if (f[1].v[(1 << (cnt + 1)) - 1]) return 1;
        }
        ins(1, c[0], 1, u.second.first,u.second.second, u.first.second.first, u.first.second.second);
        lastx = u.first.first;
    }
    if (f[1].v[(1 << (cnt + 1)) - 1]) return 1;
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld %lld", &a[i][0], &a[i][1]);
    long long l = 1, r = 1e10, mid, s = 1e10;
    while (l <= r) {
        if (check(mid = (l + r) / 2)) r = mid - 1, s = min(s, mid);
        else l = mid + 1;
    }
    if (s == 1e10) puts("-1");
    else
        printf("%lld\n", s);
    return 0;
}