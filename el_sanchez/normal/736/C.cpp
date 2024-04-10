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
const int INF = 1e9;
const int MAXN = 111;
const int MAXK = 23;
const int MOD = (int)1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int n, k;
vi g[MAXN];
int dp[MAXN][MAXK][MAXK];
int f[MAXN][2][2]; //wAU wAC
int okU[MAXN], okC[MAXN], nu, nc;
int ans;

void dfs(int v, int pv) {
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (g[v][i] == pv) {
			swap(g[v][i], g[v].back());
			g[v].pop_back();
			break;	
		}
	}
	
	for (auto w: g[v]) {
		dfs(w, v);	
	}
	
	if (g[v].empty()) { //LEAF
		dp[v][k + 1][0] = 1;
		if (k != 0) {
			dp[v][0][k + 1] = 1;	
		}
	} else { //NON-LEAF
		//non-colored
		vi sc;
		
		for (int mu = 0; mu <= k + 1; mu++) {
			for (int mc = 1; mc <= k + 1; mc++) {
				
				sc.clear();
				sc.pb(mc - 1);
				if (mc == k + 1) {
					sc.pb(mc);
				}
				
				for (auto c: sc) {
					int u = k + 1;
					
					if (mu == 0) {
						if (c < k) {
							continue;
						}
						
						nu = 0;
						okU[nu++] = k + 1;
					
					} else if (mu == k + 1) {
						if (c >= k) {
							continue;
						}
						
						nu = 0;
						for (int ou = 0; ou <= k - c - 2; ou++) {
							okU[nu++] = ou;
						}
						okU[nu++] = k + 1;
					
					} else {
						u = mu - 1;

						nu = 0;
						for (int ou = 0; ou <= u; ou++) {
							okU[nu++] = ou;
						}
						okU[nu++] = k + 1;	
						
					}
					
					if (u + 2 + c <= k) {
						continue;
					}
					
					nc = 0;
					for (int oc = c; oc <= k + 1; oc++) {
						okC[nc++] = oc;
					}
					
					memset(f, 0, sizeof(f));
					f[0][0][0] = 1;
/*					
					if (v == 1) {
						
						if (mu == k + 1 && mc == 1) {
							cout << "!!!\n";
							forn(i, nu)
								cout << okU[i] << " \n"[i == nu - 1];	
							forn(i, nc)
								cout << okC[i] << " \n"[i == nc - 1];	
						}
						
					}
*/					
					for (int i = 0; i < (int)g[v].size(); i++) {
						int w = g[v][i];
						
						forn(iu, nu) {
							forn(ic, nc) {
								int cu = okU[iu];
								int cc = okC[ic];
								
								forn(a, 2) {
									forn(b, 2) {
										add(f[i + 1][a | (cu == u)][b | (cc == c)],
											1ll * f[i][a][b] * dp[w][cu][cc] % MOD);
									}
								}
							}
						}
					}
					
					forn(a, 2) {
						forn(b, 2) {
							bool ok = (a == 1 || mu == 0 || mu == k + 1) && (b == 1);
							
							if (ok) {
								add(dp[v][mu][mc], f[(int)g[v].size()][a][b]);
							}
						}
					}
				}
			}
		}
		
		//colored
		
		dp[v][k + 1][0] = 1;
		
		for (int i = 0; i < (int)g[v].size(); i++) {
			int w = g[v][i];
			int s = 0;
			
			for (int u = 0; u <= k + 1; u++) {
				for (int c = 0; c <= k + 1; c++) {
					if (u == k) {
						continue;
					}
					
					add(s, dp[w][u][c]);
				}
			}
			
			dp[v][k + 1][0] = 1ll * dp[v][k + 1][0] * s % MOD;
		}
	}
}

int main() {

	while (cin >> n >> k) {
		forn(i, n) {
			g[i].clear();
		}
		memset(dp, 0, sizeof(dp));
		
		forn(i, n - 1) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			g[a].pb(b);
			g[b].pb(a);	
		}
		
		dfs(0, -1);
	/*	
		forn(i, n) {
			cout << i << ": \n";
			forn(j, k + 2) {
				forn(p, k + 2) {
					cout << dp[i][j][p] << " \n"[p == k + 1];
				}
			}
		}
	*/	
		ans = 0;
		forn(j, k + 2) {
			add(ans, dp[0][k + 1][j]);
		}
		cout << ans << '\n';
	}
	
    return 0;
}