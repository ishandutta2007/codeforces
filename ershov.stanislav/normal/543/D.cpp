#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;

int n, ans[N];
ll ans1[N];
bool used[N];
vector<int> g[N];
vector<ll> suff[N], pref[N];

ll dfs1(int v) {
    if (used[v]) {
        return ans1[v];
    }
    used[v] = true;
    ll prod1 = 1;
    pref[v].pb(1);
    for (int i = 0; i < (int) g[v].size(); i++) {
        prod1 = (prod1 * (dfs1(g[v][i]) + 1)) % MOD;
        pref[v].pb(prod1);
    }
    ll prod2 = 1;
    suff[v].pb(1);
    for (int i = (int) g[v].size() - 1; i >= 0; i--) {
        prod2 = (prod2 * (dfs1(g[v][i]) + 1)) % MOD;
        suff[v].pb(prod2);
    }
    reverse(all(suff[v]));
    return ans1[v] = prod2;
}

void dfs2(int v, ll par) {
    ans[v] = ((par + 1) * pref[v].back()) % MOD;
    for (int i = 0; i < (int) g[v].size(); i++) {
        dfs2(g[v][i], (par + 1) * pref[v][i] % MOD * suff[v][i + 1] % MOD);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].pb(i);
    }

    dfs1(1);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        printf("%d ", (int) ans[i]);
    }

    return 0;
}