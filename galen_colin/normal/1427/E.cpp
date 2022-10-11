#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2047;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<pair<pair<ll, ll>, ll>> ops; // 0 - xor, 1 - sum

void getmul(ll n, ll k) {
	ll cur = 0;
	while (k > 0) {
		if (k & 1) {
			ops.push_back(make_pair(make_pair(cur, n), 1));
			cur += n;
		}
		ops.push_back(make_pair(make_pair(n, n), 1));
		n *= 2;
		k /= 2;
	}
}

void end() {
	cout << ops.size() << '\n';
	for (pair<pair<ll, ll>, ll> x: ops) {
		cout << x.f.f << " ";
		if (x.s) cout << "+";
		else cout << "^";
		cout << " " << x.f.s << '\n';
	}
	
	exit(0);
}

void solve(int tc = 0) {
	cin >> n;
	ops.push_back(make_pair(make_pair(n, n), 0));
	
	for (ll i = 1; i < 10000000; i++) {
		ll v = (i * n) ^ ((i + 1) * n);
		if (__gcd(v, n) == 1) {
			getmul(n, i);
			getmul(n, i + 1);
			ops.push_back(make_pair(make_pair(n * i, (i + 1) * n), 0));
			
			ll j = 1;
			while (1) {
				ll k = v * j;
				if ((k - 1) % n == 0) {
					getmul(v, j);
					ll d = (k - 1) / n;
					getmul(n, d);
					
					if (k % 2 == 0) {
						ops.push_back(make_pair(make_pair(n, k - 1), 1));
						ops.push_back(make_pair(make_pair(n, k), 1));
						k += n;
					}
					ops.push_back(make_pair(make_pair(k - 1, k), 0));
					end();
				} else if ((k + 1) % n == 0) {
					getmul(v, j);
					ll d = (k + 1) / n;
					getmul(n, d);
					
					if (k % 2 == 1) {
						ops.push_back(make_pair(make_pair(n, k + 1), 1));
						ops.push_back(make_pair(make_pair(n, k), 1));
						k += n;
					}
					ops.push_back(make_pair(make_pair(k + 1, k), 0));
					end();
				}
				++j;
			}
		}
	}
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
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