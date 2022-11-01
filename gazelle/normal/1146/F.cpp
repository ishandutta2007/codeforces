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
#include<cassert>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll n;
vector<vector<ll>> g;
vector<vector<ll>> memo;


vector<ll> dfs(ll p, ll par) {
	if(memo[p][0] != -1) return memo[p];
	if(p != 0 && (int)g[p].size() == 1) {
		return memo[p] = {0, 1, 0};
	}
	vector<ll> ret = {1, 0, 0};
	REP(i, g[p].size()) {
		if(g[p][i] == par) continue;
		else {
			vector<ll> tmp = dfs(g[p][i], p);
			ret[0] *= (tmp[0] + tmp[1]);
			ret[0] %= MOD;
		}
	}
	vector<vector<ll>> v;
	v.pb({1, 0, 0});
	REP(i, g[p].size()) {
		if(g[p][i] == par) continue;
		else {
			vector<ll> tmp = dfs(g[p][i], p);
			vector<ll> vv = {0, 0, 0};
			vv[0] += v[(ll)v.size() - 1][0] * (tmp[0] + tmp[1]); vv[0] %= MOD;
			vv[1] += v[(ll)v.size() - 1][1] * (tmp[0] + tmp[1]); vv[1] %= MOD;
			vv[1] += v[(ll)v.size() - 1][0] * (tmp[1] + tmp[2]); vv[1] %= MOD;
			vv[2] += v[(ll)v.size() - 1][2] * (tmp[0] + tmp[1]); vv[2] %= MOD;
			vv[2] += (v[(ll)v.size() - 1][1] + v[(ll)v.size() - 1][2]) * (tmp[1] + tmp[2]); vv[2] %= MOD;
			// cerr << vv[0] << " " << vv[1] << " " << vv[2] << endl;
			v.pb(vv);
		}
	}
	ret[1] = v[(ll)v.size() - 1][2];
	ret[2] = v[(ll)v.size() - 1][1];
	return memo[p] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	g.resize(n);
	memo.resize(n, {-1, -1});
	REP(i, n - 1) {
		ll p;
		cin >> p;
		g[i + 1].pb(p - 1);
		g[p - 1].pb(i + 1);
	}
	vector<ll> ans = dfs(0, -1);
	cout << (ans[0] + ans[1]) % MOD << endl;
	return 0;
}
/* --------------------------------------- */