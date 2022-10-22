//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll n, int e) {
	ll r = 1;
	for( ; e>0; e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

ll inverse(ll n) {
	return power(n, MOD-2);
}

const int M = 99;
ll fact[M], invf[M];

const int N = 4e7;
vector<int> ps;
bitset<N> np;

unordered_map<ll,vector<int>> factors;

void combine(int i, const vector<pair<ll,int>>& cnt, ll v, vector<int>& cur) {
	if(i < 0) {
		assert(!factors.count(v));
		factors[v] = cur;
		//cerr<<"ADD "<<v<<nl;
		return;
	}
	//cerr<<"@ "<<cnt[i].first<<" w/ "<<cnt[i].second<<nl;
	ll f = 1;
	for(int j=0; j<=cnt[i].second; j++) {
		cur.push_back(j);
		combine(i-1, cnt, v*f, cur);
		cur.pop_back();
		f *= cnt[i].first;
	}
}

void build(ll n) {
	vector<pair<ll,int>> cnt;
	for(int p : ps) {
		if((ll)p*p > n) break;
		int c = 0;
		while(n % p == 0) {
			n /= p;
			c++;
		}
		if(c > 0) {
			cnt.push_back(make_pair(p, c));
		}
	}
	if(n > 1) {
		cnt.push_back(make_pair(n, 1));
	}
	vector<int> cur;
	combine((int)cnt.size()-1, cnt, 1, cur);
}

ll paths(ll n) {
	assert(factors.count(n));
	ll ans = 1;
	int tot = 0;
	for(int it : factors[n]) {
		tot += it;
		ans = ans * invf[it] % MOD;
	}
	ans = ans * fact[tot] % MOD;
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	for(int i=2; i*i<N; i++) {
		if(np[i]) continue;
		for(int j=i*i; j<N; j+=i) {
			np[j] = true;
		}
	}
	for(int i=2; i<N; i++) {
		if(!np[i]) {
			ps.push_back(i);
		}
	}

	fact[0] = invf[0] = 1;
	for(int i=1; i<M; i++) {
		fact[i] = fact[i-1] * i % MOD;
		invf[i] = inverse(fact[i]);
	}

	ll n;
	cin >> n;
	build(n);
	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		ll a, b;
		cin >> a >> b;
		ll g = __gcd(a, b);
		cout << paths(a/g) * paths(b/g) % MOD << nl;
	}

	return 0;
}