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
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<vector<ll>> memo(505050, vector<ll>(2, -1));

ll k;

ll dfs(int sz, int sm) {
	if(memo[sz][sm] != -1) return memo[sz][sm];
	if(sz == 1) {
		if(sm) {
			return k - 1;
		} else {
			return k - 2;
		}
	}
	ll ret = 0;
	if(sm) ret += (k - 1) * dfs(sz - 1, 0);
	else ret += (k - 2) * dfs(sz - 1, 0) + dfs(sz - 1, 1);
	return memo[sz][sm] = ret % MOD;
}

ll proc(vector<ll>& v) {
	FOR(i, 1, v.size()) {
		if(v[i] != -1 && v[i - 1] != -1 && v[i - 1] == v[i]) {
			return 0;
		}
	}
	ll ret = 1;
	bool b = true;
	REP(i, v.size()) if(v[i] != -1) b = false;
	if(b) {
		ret *= k;
		FOR(i, 1, v.size()) {
			ret *= (k - 1);
			ret %= MOD;
		}
	} else {
		ll l = 0, r = (ll)v.size() - 1;
		while(v[l] == -1) {
			ret *= (k - 1);
			l++;
			ret %= MOD;
		}
		while(v[r] == -1) {
			ret *= (k - 1);
			r--;
			ret %= MOD;
		}
		ll sz = 0, bef = v[l];
		FOR(i, l + 1, r + 1) {
			if(v[i] == -1) sz++;
			else {
				if(sz > 0) {
					ret *= dfs((int)sz, (int)(bef == v[i]));
					sz = 0;
					ret %= MOD;
				}
				bef = v[i];
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> v1, v2;
	REP(i, n) {
		if(i % 2 == 0) v1.pb(a[i]);
		else v2.pb(a[i]);
	}
	ll ans = proc(v1) * proc(v2); ans %= MOD;
	cout << (ans + MOD) % MOD << endl;
	return 0;
}

/* --------------------------------------- */