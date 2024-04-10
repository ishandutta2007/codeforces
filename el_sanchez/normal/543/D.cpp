#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 200500;
const ll MOD = 1000000007;

ll inv(ll x) {
	ll st = MOD - 2, res = 1;
	while (st > 0) {
		if (st & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		st >>= 1;	
	}
	return res;
}

int n, v;
ll dp[MAXN], dpP[MAXN], ans[MAXN];
vi g[MAXN], g2[MAXN];       
int used[MAXN], par[MAXN];
queue<int> q;
ll pref[MAXN], suff[MAXN];

void dfs1(int v) {
	used[v] = 1;
	dp[v] = 1;
	
	for (auto w: g[v]) {
		if (!used[w]) {
			dfs1(w);
			dp[v] = (dp[v] * (dp[w] + 1)) % MOD;
			g2[v].pb(w);
			par[w] = v;
		}
	}		
}  

int main() {

	cin >> n;
	forn(i, n - 1) {
		scanf("%d", &v);
		v--;
		g[i + 1].pb(v);
		g[v].pb(i + 1);	
	}
	
	memset(used, 0, sizeof(used));
	dfs1(0);
		
	dpP[0] = 1;
	q.push(0);
	while (!q.empty()) {
		v = q.front();
		q.pop();

		pref[0] = 1;
		suff[g2[v].size() + 1] = 1;
				
    	for (int i = 0; i < (int)g2[v].size(); i++)
    		pref[i + 1] = (pref[i] * (dp[g2[v][i]] + 1)) % MOD;
    	for (int i = (int)g2[v].size() - 1; i >= 0; i--)
    		suff[i + 1] = (suff[i + 2] * (dp[g2[v][i]] + 1)) % MOD;
    		
		for (int i = 0; i < (int)g2[v].size(); i++) {
			int w = g2[v][i];
    		q.push(w);
			dpP[w] = (1ll + pref[i] * suff[i + 2] % MOD * dpP[v] % MOD) % MOD;			
		}
	}
	
	//forn(i, n)
	//	cout << dp[i] << ' ' << dpP[i] << '\n';
		
	forn(i, n) {
		ans[i] = (dp[i] * dpP[i]) % MOD;
		cout << ans[i] << " \n"[i == n - 1];	
	}
	
	return 0;
}