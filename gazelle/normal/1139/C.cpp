#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll _pow(ll a, ll n) {
	if(n==0) return 1;
	else {
		ll res = 1;
		ll buf = a;
		while(n>0) {
			if(n%2==1) {
				res *= buf;
				res %= MOD;
			}
			buf *= buf;
			buf %= MOD;
			n/=2;
		}
		return res;
	}
}

vector<vector<int>> g;
vector<bool> used;

int dfs(int pos, int par) {
	used[pos] = true;
	int ret = 1;
	REP(i, g[pos].size()) {
		if(g[pos][i] == par) continue;
		ret += dfs(g[pos][i], pos);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	g.resize(n);
	used.assign(n, false);
	REP(i, n - 1) {
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		if(x == 1) continue;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll ans = 0;
	REP(i, n) {
		if(!used[i]) {
			int tmp = dfs(i, -1);
			ans += _pow(tmp, k); ans %= MOD;
		}
	}
	ans = _pow(n, k) - ans;
	cout << (ans % MOD + MOD) % MOD << endl;
	return 0;
}

/* --------------------------------------- */