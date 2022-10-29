#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;
            
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 88;

int n, k, m;
int dp[MAXN][MAXN][MAXN];
vector<pii> g[MAXN];

void relax(int &x, int y) {
    x = min(x, y);    
}

int main() {
    
    cin >> n >> k;
    
    if (k == 1) {
        cout << 0 << '\n';
        return 0;    
    }
    if (n < k) {
        cout << -1 << '\n';
        return 0;   
    }
    //so n >= k >= 2
    
    forn(i, MAXN) {
        forn(j, MAXN) {
            forn(l, MAXN) {
                dp[i][j][l] = INF;    
            }
        }
    }
    
    cin >> m;
    forn(i, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        if (a != b) {
            g[a].pb(mp(b, c));  
            
            //and init
            if (a < b) {
                relax(dp[2][b][a + 1], c);
                relax(dp[2][b][n - 1], c);
            } else {
                relax(dp[2][b][a - 1], c);
                relax(dp[2][b][0], c);    
            }
        }       
        
    }
    
    for (int d = 2; d < k; d++) {
        for (int pos = 0; pos < n; pos++) {
            for (int bnd = 0; bnd < n; bnd++) {
                if (dp[d][pos][bnd] != INF) {
                    int L = min(pos, bnd);
                    int R = max(pos, bnd);
                    
                    for (auto e: g[pos]) {
                        int v = e.X;
                        int cost = e.Y;
                        int val = dp[d][pos][bnd] + cost;
                        
                        //v != pos!   
                        if (L <= v && v <= R) {
                            if (pos == L) {
                                relax(dp[d + 1][v][L + 1], val);
                                relax(dp[d + 1][v][R], val);                                
                            } else {
                                assert(pos == R);
                                relax(dp[d + 1][v][R - 1], val);
                                relax(dp[d + 1][v][L], val);                                   
                            }
                        }
                    }
                }
            }
        }
    }
    
    int ans = INF;
    forn(i, n) {
        forn(j, n) {
            ans = min(ans, dp[k][i][j]);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    
    return 0;
}