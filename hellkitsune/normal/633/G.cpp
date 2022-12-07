#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bitset<1000> mask;
bitset<1000> st[1 << 18];
int sp[1 << 17] = {};
int a[100000];
const int off = 1 << 17;
int n, m;
vector<int> g[100000];

void stBuild() {
    for (int i = off - 1; i >= 1; --i) {
        st[i] = st[2 * i] | st[2 * i + 1];
    }
}

int tin[100000], tout[100000], timer = -1;

void dfs(int v, int p) {
    tin[v] = ++timer;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
    tout[v] = timer;
}

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= m) x -= m;
}

void sh(bitset<1000> &b, int val) {
    b = ((b << val) | (b >> (m - val))) & mask;
}

void stPush(int v, bool eq) {
    for (int i = 2 * v; i <= 2 * v + 1; ++i) {
        sh(st[i], sp[v]);
        if (!eq) modAdd(sp[i], sp[v]);
    }
    sp[v] = 0;
}

int stVal;
void stAdd(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        sh(st[v], stVal);
        if (L != R) modAdd(sp[v], stVal);
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) {
        stPush(v, R == L + 1);
    }
    if (l <= mid) stAdd(2 * v, L, mid, l, min(r, mid));
    if (r > mid) stAdd(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    st[v] = st[2 * v] | st[2 * v + 1];
}

bitset<1000> stRes, primeMask;
void stGet(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        stRes |= st[v];
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) {
        stPush(v, R == L + 1);
    }
    if (l <= mid) stGet(2 * v, L, mid, l, min(r, mid));
    if (r > mid) stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

bool pr[1001];

int main() {
    //freopen("input.txt", "r", stdin);
    REP(i, 1001) pr[i] = true;
    pr[0] = pr[1] = false;
    REP(i, 1001) if (pr[i]) {
        for (int j = i * i; j < 1001; j += i) {
            pr[j] = false;
        }
    }
    REP(i, 1000) if (pr[i]) primeMask.set(i);
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, m) mask.set(i);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    REP(i, n) {
        st[off + tin[i]].set(a[i] % m);
    }
    stBuild();
    int q;
    scanf("%d", &q);
    REP(qq, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int v;
            scanf("%d%d", &v, &stVal), --v, stVal %= m;
            stAdd(1, 0, off - 1, tin[v], tout[v]);
        } else {
            int v;
            scanf("%d", &v), --v;
            stRes.reset();
            stGet(1, 0, off - 1, tin[v], tout[v]);
            stRes &= primeMask;
            printf("%d\n", (int)stRes.count());
        }
    }
    return 0;
}