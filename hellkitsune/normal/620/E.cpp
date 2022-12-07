#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int c[400000];
vector<int> g[400000];
int tin[400000], tout[400000], pos[400000], timer = -1;
LL st[1 << 20];
bool ste[1 << 20] = {};
const int off = 1 << 19;

void stBuild() {
    REP(i, n) pos[tin[i]] = i;
    REP(i, n) st[off + i] = 1ll << c[pos[i]];
    for (int i = n; i < off; ++i) st[off + i] = 0;
    REP(i, off) ste[off + i] = true;
    for (int i = off - 1; i >= 1; --i) st[i] = st[i << 1] | st[(i << 1) | 1];
}

void stPush(int v) {
    for (int i = (v << 1); i <= ((v << 1) | 1); ++i) {
        ste[i] = true;
        st[i] = st[v];
    }
    ste[v] = false;
}

int stc;
void stUpdate(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        ste[v] = true;
        st[v] = 1ll << stc;
        return;
    }
    int mid = (L + R) >> 1;
    if (ste[v]) stPush(v);
    if (l <= mid) stUpdate(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stUpdate((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    st[v] = st[v << 1] | st[(v << 1) | 1];
}

LL stGet(int v, int L, int R, int l, int r) {
    if ((l == L && r == R) || ste[v]) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    LL ret = 0;
    if (l <= mid) ret = stGet(v << 1, L, mid, l, min(r, mid));
    if (r > mid) ret |= stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    return ret;
}

void dfs(int v, int p) {
    tin[v] = ++timer;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
    tout[v] = timer;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", c + i), --c[i];
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    stBuild();
    REP(qq, m) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int v;
            scanf("%d%d", &v, &stc), --v, --stc;
            stUpdate(1, 0, off - 1, tin[v], tout[v]);
        } else {
            int v;
            scanf("%d", &v), --v;
            printf("%d\n", __builtin_popcountll(stGet(1, 0, off - 1, tin[v], tout[v])));
        }
    }
    return 0;
}