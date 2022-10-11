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
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
/* note: additional optimization - first take everything modulo mod^2, using if (x >= mod^2) x -= mod^2, then take everything modulo mod at the end */
template<int n>
struct matrix {
  using TYPE = ll;
  TYPE v[n][n];

  matrix() {
    memset(v, 0, sizeof(v));
  }

  // matrix<n> mul(matrix &b) {
    // matrix<n> res;
    // for (int i = 0; i < n; i++) {
      // for (int k = 0; k < n; k++) {
        // for (int j = 0; j < n; j++) {
          // res.v[i][j] = (res.v[i][j] + v[i][k] * b.v[k][j]) % mod;
        // }
      // }
    // }
    // return res;
  // }
  
  matrix<n> mul(matrix &b) {
    matrix<n> res;
	static const ll msq = mod * mod;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
          res.v[i][j] += v[i][k] * b.v[k][j];
		  res.v[i][j] = (res.v[i][j] >= msq ? res.v[i][j] - msq : res.v[i][j]);
        }
      }
    }
	for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res.v[i][j] %= mod;
      }
    }
    return res;
  }

  matrix<n> pow(matrix<n> &a, long long x) {
    matrix<n> res;
    for (int i = 0; i < n; i++) res.v[i][i] = 1;

    while (x) {
      if (x & 1) {
        res = res.mul(a);
      }
      x /= 2;
      a = a.mul(a);
    }
    return res;
  } 
  
  void pr() {
	  cout << "------------\n";
	  for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		  cout << v[i][j] << " ";
		}
		cout << '\n';
	  }
	  cout << "------------\n";
  }
  
  #pragma message("be careful with mod in matrix")
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll dp[1005];
ll trans[105];
const ll sz = 100;
 
void solve(int tc = 0) {
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	matrix<sz + 1> m;
	
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	memset(trans, 0, sizeof(trans));
	
	for (ll i = 0; i < n; i++) ++trans[a[i]];
	
	for (ll i = 0; i < 805; i++) {
		for (ll j = 1; j <= sz; j++) {
			dp[i + j] = (dp[i + j] + dp[i] * trans[j]) % mod;
		}
	}
	
	if (k < sz) {
		ll ans = 0;
		for (ll i = 0; i <= k; i++) ans += dp[i];
		cout << ans % mod << '\n';
		// cout << dp[k] << '\n';
		return;
	}
	
	for (ll i = 1; i < sz; i++) m.v[i][i - 1] = 1;
	for (ll i = 0; i < sz; i++) m.v[0][i] = trans[i + 1];
	m.v[sz][0] = m.v[sz][sz] = 1;
	
	m = m.pow(m, k - sz + 1);
	
	ll ans = 0;
	for (ll i = 0; i < sz; i++) {
		ans = (ans + dp[sz - i - 1] * m.v[0][i]) % mod;
	}
	
	ll rem = 0;
	for (ll i = 0; i < sz - 1; i++) {
		rem = (rem + dp[i]) % mod;
	}

	for (ll i = 0; i < sz; i++) {
		ans = (ans + dp[sz - i - 1] * m.v[sz][i]) % mod;
	}
	ans = (ans + rem * m.v[sz][sz]) % mod;
	
	cout << ans << '\n';
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