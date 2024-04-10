#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000], b[100000], c[100000], d[100000], ord[100000], tmp[100000];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (b[lhs] != b[rhs]) return b[lhs] < b[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> st[1 << 18];
const int off = 1 << 17;

void stBuild() {
    REP(i, n) st[off + i].insert(i);
    for (int i = off - 1; i >= 1; --i) {
        for (int x : st[2 * i]) st[i].insert(x);
        for (int x : st[2 * i + 1]) st[i].insert(x);
    }
}

void stRemove(int pos) {
    for (int x = pos + off; x >= 1; x >>= 1) {
        st[x].erase(pos);
    }
}

vector<int> res;
int to;
void stGet(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        for (int x : st[v]) {
            if (b[x] > to) break;
            res.pb(x);
        }
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) stGet(2 * v, L, mid, l, min(r, mid));
    if (r > mid) stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

inline bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

void reord(int *a) {
    REP(i, n) tmp[i] = a[ord[i]];
    REP(i, n) a[i] = tmp[i];
}

int pre[100000];
queue<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    reord(a);
    reord(b);
    reord(c);
    reord(d);
    stBuild();
    REP(i, n) pre[i] = -1;
    REP(i, n) if (a[i] == 0 && b[i] == 0) {
        pre[i] = 0;
        q.push(i);
        stRemove(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int lo = -1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a[mid] > c[v]) hi = mid - 1;
            else lo = mid;
        }
        if (lo >= 0) {
            res.clear();
            to = d[v];
            stGet(1, 0, off - 1, 0, lo);
            for (int x : res) {
                stRemove(x);
                pre[x] = v;
                q.push(x);
            }
        }
    }
    int z = -1;
    REP(i, n) if (ord[i] == n - 1) z = i;
    if (pre[z] == -1) {
        printf("-1\n");
    } else {
        vector<int> v;
        v.pb(z);
        for (int i = z; a[i] != 0 || b[i] != 0; i = pre[i]) {
            v.pb(pre[i]);
        }
        reverse(v.begin(), v.end());
        printf("%d\n", (int)v.size());
        for (int x : v) printf("%d ", ord[x] + 1);
        printf("\n");
    }
    return 0;
}