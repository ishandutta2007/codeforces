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
const int N = 2e5+7, K = 10;
int n, m, k;
vector <ii> g[N];
bitset <N> who[K][K];
int cnt[N];
bool bad[K][K];
int ban[K][K], num[K][K];
int ans = 0;
void solve(int i, int b) {
    if (i == k + 1) {
        ans++;
        return;                    
    }
    for (int j = 1; j <= i; ++j) {
        if (!bad[i][j] && !((b >> num[i][j]) & 1)) {
            solve(i + 1, b | ban[i][j]);
        }   
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].app(mp(w, v));
    }   

    for (int u = 1; u <= n; ++u)
        sort(all(g[u]));

    for (int x = 1; x <= k; ++x) {
        for (int y = 1; y <= x; ++y) {
            memset(cnt, 0, sizeof cnt);
            for (int u = 1; u <= n; ++u) {
                if (g[u].size() == x) {
                    int v = g[u][y-1].s;
                    cnt[v]++;
                }   
            }   
            for (int u = 1; u <= n; ++u) {
                if (cnt[u] > 1) {
                    bad[x][y] = 1;
                    break;
                }   
            }            
            for (int u = 1; u <= n; ++u) {
                if (cnt[u]) {
                    who[x][y][u] = 1;
                }
            }   
        }   
    }   
    
    int ptr = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= i; ++j)
            num[i][j] = ptr++;

    for (int x1 = 1; x1 <= k; ++x1) {
        for (int y1 = 1; y1 <= x1; ++y1) {
            for (int x2 = x1 + 1; x2 <= k; ++x2) {
                for (int y2 = 1; y2 <= x2; ++y2) {

                    if (!bad[x1][y1] && !bad[x2][y2]) {
                        if ((who[x1][y1] & who[x2][y2]).count()) {
                            ban[x1][y1] += 1ll << num[x2][y2];
                        }   
                    }   
                    
                }   
            }   
        }   
    }   

    /*
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << ban[i][j] << ' ';
        }   
        cout << endl;
    }
    */  

    solve(1, 0);
    cout << ans << endl;
}