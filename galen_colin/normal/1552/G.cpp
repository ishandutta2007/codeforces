#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
 
// benq - print any container + pair
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
	cout << "["; 
	for (auto it = v.begin(); it != v.end();) {
		cout << *it;
		if (++it != v.end()) cout << ", ";
	}
	return cout << "]";
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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17646;
ll a[41];
ll b[41];
ll c[41];

ll qv[11][41];
ll stor[11][41];
ll nxt[11][41];
vector<ll> at[11];
ll vals[41];
ll ans = 1;
ll tc = 0;
ll dp[11];
ll take[11];
ll cat[11];

void dfs(ll i) {
  if (i == q) {
    if (tc == n) return;

    // cout << "---\n";
    
    for (ll j = q - 1; j >= 0; j--) {
      dp[j] = 0;

      if (cat[j] < a[j]) {
        ll p = qv[j][cat[j]];
        
        if (nxt[j][p] != -1) dp[j] = dp[nxt[j][p]];
        else dp[j] = (p == tc);
      }

      if (take[j] < c[j]) ans &= dp[j];
    }
    
    return;
  }

  ll tot = 0;
  for (ll j = 0; j < at[i].size(); j++) tot += (vals[at[i][j]] == 0);
    
    for (ll j = 0; j < tot; j++) {
      stor[i][j] = vals[qv[i][j]];
      vals[qv[i][j]] = 0;
    }
      for (ll j = tot; j < a[i]; j++) {
      stor[i][j] = vals[qv[i][j]];
      vals[qv[i][j]] = 1;
    }
  for (ll cnt = 0; cnt <= c[i]; cnt++) {
    tc += cnt;

    take[i] = cnt;
    cat[i] = tot + cnt;

    dfs(i + 1);

    tc -= cnt;
    
    if (cnt < c[i]) vals[qv[i][tot + cnt]] = 0;
  }
  
  for (ll j = 0; j < a[i]; j++) vals[qv[i][j]] = stor[i][j];
  
}

void solve(int tc = 0) {
  cin >> n >> q;
// n = 40, q = 10;

  ll cnt = 0;
  for (ll i = 0; i < q; i++) {
    cin >> a[i];
    // a[i] = 4 * (i + 1);
    for (ll j = 0; j < a[i]; j++) {
      cin >> qv[i][j];
    // qv[i][j] = j + 1;
      --qv[i][j];
      if (b[qv[i][j]] == 0) {
        b[qv[i][j]] = 1;
        ++c[i];
        ++cnt;
      } else {
        at[i].push_back(qv[i][j]);
      }
    }
  }

  memset(nxt, -1, sizeof(nxt));
  for (ll i = 0; i < q; i++) {
    for (ll j = 0; j < n; j++) {
      for (ll k = q - 1; k > i; k--) {
        for (ll x = 0; x < a[k]; x++) {
          if (qv[k][x] == j) {
            nxt[i][j] = k;
          }
        }
      }
    }
  }

  if (n == 1) {
    cout << "ACCEPTED\n";
    return;
  }

  if (cnt < n) {
    cout << "REJECTED\n";
    return;
  }

  memset(vals, -1, sizeof(vals));
  dfs(0);

  cout << (ans ? "ACCEPTED\n" : "REJECTED\n");
  // cout << z;
}


int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}

/*
4 4
2 3 4
3 1 2 3
2 3 4
2 2 3

*/