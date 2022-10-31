#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 5e5;

int n, m;
vector<int> graph[maxn];
int dp[maxn], deg[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
        deg[u]++, deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < sz(graph[i]); j++) {
            if (graph[i][j] > i) {
                continue;
            }
            dp[i] = max(dp[i], dp[graph[i][j]] + 1);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (ll) deg[i] * dp[i]);
    }
    printf(LLD "\n", ans);
    return 0;
}