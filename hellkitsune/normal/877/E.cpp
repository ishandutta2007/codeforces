#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
vector<int> g[200000];
int t[200000];
int tin[200000], tout[200000], timer = 0;
char s[123];

void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
    tout[v] = timer;
}

int st[1 << 19], sp[1 << 19];
const int OFF = 1 << 18;

void stBuild() {
    forn(i, n) st[OFF + tin[i]] = t[i];
    for (int i = OFF - 1; i >= 1; --i) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}

void stPush(int v, int sz) {
    for (int i = 2 * v; i <= 2 * v + 1; ++i) {
        st[i] = sz - st[i];
        if (sz > 1) {
            sp[i] ^= 1;
        }
    }
    sp[v] = 0;
}

void stUpdate(int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (L == l && R == r) {
        st[v] = R - L + 1 - st[v];
        sp[v] ^= 1;
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) {
        stPush(v, R - mid);
    }
    stUpdate(2 * v, L, mid, l, min(r, mid));
    stUpdate(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    st[v] = st[2 * v] + st[2 * v + 1];
}

int stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    if (sp[v]) {
        stPush(v, R - mid);
    }
    return stGet(2 * v, L, mid, l, min(r, mid)) +
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int par;
        scanf("%d", &par), --par;
        g[par].pb(i + 1);
    }
    dfs(0);
    forn(i, n) scanf("%d", t + i);
    stBuild();
    scanf("%d", &q);
    forn(_, q) {
        int v;
        scanf("%s%d", s, &v);
        --v;
        if (s[0] == 'g') {
            int res = stGet(1, 0, OFF - 1, tin[v], tout[v] - 1);
            printf("%d\n", res);
        } else {
            stUpdate(1, 0, OFF - 1, tin[v], tout[v] - 1);
        }
    }
    return 0;
}