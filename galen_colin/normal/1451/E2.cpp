#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5147;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

void set_bit(ll pos, ll bit) {
	if (pos == 0) {
		for (ll i = 1; i < n; i++) {
			ll v = b[i] ^ a[0];
			a[i] += v & (1 << bit);
		}
	} else {
		for (ll i = 0; i < n; i++) {
			if (i != pos) {
				ll v;
				if (i == 0) v = b[pos] ^ a[pos];
				else v = b[pos] ^ b[i] ^ a[pos];
				a[i] += v & (1 << bit);
			}
		}
	}
}

void end() {
	cout << "!";
	for (ll i = 0; i < n; i++) cout << " " << a[i];
	cout << endl;
	exit(0);
}

void solve(int tc = 0) {
	cin >> n;
	
	ll k = 0;
	while ((1 << k) != n) ++k;
	
	for (ll i = 1; i < n; i++) {
		cout << "XOR " << 1 << " " << i + 1 << endl;
		cin >> b[i];
	}
	
	for (ll i = 1; i < n; i++) {
		if (b[i] == 0) {
			cout << "AND " << 1 << " " << i + 1 << endl;
			cin >> a[0];
			for (ll j = 0; j < k; j++) set_bit(0, j);
			end();
		}
	}
	
	vector<ll> vals[n];
	for (ll i = 1; i < n; i++) {
		if (vals[b[i]].size() > 0) {
			cout << "AND " << vals[b[i]][0] + 1 << " " << i + 1 << endl;
			cin >> a[vals[b[i]][0]];
			for (ll j = 0; j < k; j++) set_bit(vals[b[i]][0], j);
			end();
		}
		vals[b[i]].push_back(i);
	}
	
	for (ll i = 0; i < n; i++) vals[i].clear();
	
	bool one = 0, even = 0;
	for (ll i = 1; i < n; i++) {
		if (b[i] == 1 && !one) {
			cout << "AND " << 1 << " " << i + 1 << endl;
			ll x; cin >> x;
			for (ll j = 1; j < k; j++) {
				a[0] += x & (1 << j);
				set_bit(0, j);
			}
			one = 1;
		}
		if (b[i] % 2 == 0 && !even) {
			cout << "AND " << 1 << " " << i + 1 << endl;
			ll x; cin >> x;
			for (ll j = 0; j < 1; j++) {
				a[0] += x & (1 << j);
				set_bit(0, j);
			}
			even = 1;
		}
	}
	
	for (ll i = 1; i < n; i++) {
		if (vals[b[i] ^ 1].size() > 0 && !one) {
			cout << "AND " << vals[b[i] ^ 1][0] + 1 << " " << i + 1 << endl;
			ll x; cin >> x;
			for (ll j = 1; j < k; j++) {
				a[vals[b[i] ^ 1][0]] += x & (1 << j);
				set_bit(vals[b[i] ^ 1][0], j);
			}
			one = 1;
		}
		vals[b[i]].push_back(i);
	}
	
	vector<ll> v2[2];
	
	for (ll i = 1; i < n; i++) {
		if (v2[b[i] & 1].size() > 0 && !even) {
			cout << "AND " << v2[b[i] & 1][0] + 1 << " " << i + 1 << endl;
			ll x; cin >> x;
			for (ll j = 0; j < 1; j++) {
				a[v2[b[i] & 1][0]] += x & (1 << j);
				set_bit(v2[b[i] & 1][0], j);
			}
			even = 1;
		}
		v2[b[i] & 1].push_back(i);
	}
	
	end();
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}