#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 2e5+7, LG = 20, INF = 1e18, MOD = 998244353;

int d[N][LG];
vector <int> g[2][N];
int pw[N];
ii dp[N][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = (pw[i - 1] * 2) % MOD;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[0][u].app(v);
        g[1][v].app(u);
    }   

    struct T {
        int u, t, c;
        bool const operator < (T f) const {
            return c < f.c || (c == f.c && mp(u, t) < mp(f.u, f.t));
        }   
    };  

    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < LG; ++j)
            d[i][j] = INF;

    d[1][0] = 0;
    for (int p = 0; p < LG; ++p) {
        set <T> ms;
        for (int u = 1; u <= n; ++u) {
            if (d[u][p] != INF) {
                ms.insert({u, p, d[u][p]});
            }   
        }   

        auto relax = [&] (int u, int pp, int c) {
            if (c < d[u][pp]) {
                if (pp == p) {
                    ms.erase({u, p, d[u][p]});
                }   
                d[u][pp] = c;
                if (pp == p) {
                    ms.insert({u, p, d[u][p]});
                }   
            }   
        };  

        while (ms.size()) {
            int u = ms.begin()->u;
            ms.erase(ms.begin());
            int cost = d[u][p];
            if (p + 1 < LG) {
                relax(u, p + 1, cost);
            }
            for (int v : g[p & 1][u]) {
                relax(v, p, cost + 1);
            }   
        }   
    }   
    
    int ans = INF;
    for (int p = 0; p < LG; ++p) {
        if (d[n][p] != INF) {
            ans = min(ans, d[n][p] + pw[p] - 1);
        }   
    }   
    if (ans != INF) {
        cout << ans % MOD << endl;
        exit(0);
    }

    struct TT {
        int u, t;
        bool const operator < (TT f) const {
            return dp[u][t] < dp[f.u][f.t] || (dp[u][t] == dp[f.u][f.t] && mp(u, t) < mp(f.u, f.t));
        }   
    };  

    set <TT> ms;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < 2; ++j)
            dp[i][j] = mp(INF, INF);
    dp[1][0] = mp(0, 0);
    ms.insert({1, 0});

    auto relax1 = [&] (int u, int t, ii x) {
        if (x < dp[u][t]) {
            ms.erase({u, t});
            dp[u][t] = x;
            ms.insert({u, t});
        }
    };  

    while (ms.size()) {
        int u = ms.begin()->u;
        int t = ms.begin()->t;
        ms.erase(ms.begin());
        relax1(u, t ^ 1, mp(dp[u][t].f + 1, dp[u][t].s));
        for (int v : g[t][u]) {
            relax1(v, t, mp(dp[u][t].f, dp[u][t].s + 1));
        }   
    }   

    {
    auto ans = min(dp[n][0], dp[n][1]);
    assert(ans.f != INF);
    cout << (pw[ans.f] - 1 + MOD + ans.s) % MOD << endl;
    }
}