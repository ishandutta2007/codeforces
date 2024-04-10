#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll n, m;

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

bool dfs(ll pos, vector<vector<ll>>& g, vector<ll>& col, P& cnt, ll c) {
	bool ret = true;
	if(c == 0) cnt.first++;
	else cnt.second++;
	col[pos] = c;
	REP(i, g[pos].size()) {
		if(col[g[pos][i]] != -1) {
			if(col[g[pos][i]] == c) {
				ret = false;
			}
		} else {
			ret = ret & dfs(g[pos][i], g, col, cnt, !c);
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	REP(testcase, t) {
		cin >> n >> m;
		vector<vector<ll>> g(n);
		REP(i, m) {
			ll u, v;
			cin >> u >> v;
			u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vector<ll> col(n, -1);
		ll ans = 1;
		REP(i, n) {
			if(col[i] != -1) continue;
			P cnt = P(0, 0);
			if(!dfs(i, g, col, cnt, 0)) ans = 0;
			else {
				if(cnt.first + cnt.second == 1) {
					ans *= 3LL; ans %= MOD;
				} else {
					ans *= (_pow(2, cnt.first) + _pow(2, cnt.second)); ans %= MOD;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

/* --------------------------------------- */