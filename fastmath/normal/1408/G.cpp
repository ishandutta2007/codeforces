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

const int N = 1507, INF = 1e9+7;
int n;
int a[N][N];

vector <ii> ord[N];

int pref1[N][N], pref2[N][N];
bool is[N][N];

mt19937 rnd(2007);
int w1[N], w2[N];

int par[N * 2];
vector <int> tree[N * 2];
int dp[N * 2][N];
int cnt[N * 2];

const int MOD = 998244353;

void dfs(int u) {
    dp[u][0] = 1;

    if (tree[u].empty())
        cnt[u] = 1;

    for (int v : tree[u]) {
        dfs(v);
        for (int i = cnt[u]; i >= 0; --i) {
            int x = dp[u][i];
            dp[u][i] = 0;
            for (int j = 1; j <= cnt[v]; ++j) {
                dp[u][i + j] += x * dp[v][j];
                dp[u][i + j] %= MOD;
            }   
        }   
        cnt[u] += cnt[v];
    }   

    dp[u][1]++;
    dp[u][1] %= MOD;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        w1[i] = rnd();
        w2[i] = rnd();
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            ord[i].app(mp(a[i][j], j));
        }   
        sort(all(ord[i]));
        for (int j = 0; j < n; ++j) {
            pref1[i][j + 1] = pref1[i][j] + w1[ord[i][j].s];
            pref2[i][j + 1] = pref2[i][j] + w2[ord[i][j].s];
        }   
    }   

    vector <ii> co;
    for (int sz = 1; sz <= n; ++sz) {
        map <ii, int> d;
        for (int i = 1; i <= n; ++i)
            d[mp(pref1[i][sz], pref2[i][sz])]++;
        for (int i = 1; i <= n; ++i)
            if (d[mp(pref1[i][sz], pref2[i][sz])] == sz) {

                bool good = 1;
                int mn = INF, mx = 0;
                for (int u = 1; u <= n; ++u) {
                    if (mp(pref1[u][sz], pref2[u][sz]) == mp(pref1[i][sz], pref2[i][sz])) {
                        mx = max(mx, ord[u][sz - 1].f);
                        if (sz < n) {
                            mn = min(mn, ord[u][sz].f);
                        }
                    }   
                }   
                
                if (mx < mn) {
                    is[i][sz] = 1;
                    co.app(mp(pref1[i][sz], pref2[i][sz]));
                }
            }   
    }   

    sort(all(co));
    co.resize(unique(all(co)) - co.begin());
    assert(co.size() < N * 2);

    for (int i = 0; i < N * 2; ++i)
        par[i] = -1;        

    int root = (int)co.size() - 1;
    assert(root == lower_bound(all(co), mp(pref1[1][n], pref2[1][n])) - co.begin());

    for (int i = 1; i <= n; ++i) {
        int prv = root;
        for (int sz = n - 1; sz; --sz) {
            if (is[i][sz]) {
                int num = lower_bound(all(co), mp(pref1[i][sz], pref2[i][sz])) - co.begin();                
                if (par[num] != -1) {
                    assert(par[num] == prv);
                }
                else {
                    tree[prv].app(num);
                }   
                par[num] = prv;
                prv = num;
            }   
        }   
    }   

    #ifdef HOME
    for (int i = 0; i < co.size(); ++i) 
        cout << i << "->" << par[i] << endl;
    #endif

    dfs(root);
    for (int i = 1; i <= n; ++i) {
        cout << dp[root][i] << ' ';
    }   
    cout << endl;
}