// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define li long long
#define ld long double
#define ii pair<int, int>
#define dd pair<double, double> 
#define lii pair<li, li>
#define ldd pair<ld, ld>
#define vi vector<int> // typedef vector<int> vi + #define int long long -> vi is still vector of 32 bit int, which took me 2 hours to figure out
#define vd vector<double> 
// untested
#define vli vector<li> 
#define vld vector<ld> 
#define vii vector<ii> 
#define vdd vector<dd> 
#define vlii vector<lii> 
#define vldd vector<ldd> 
#define vvi vector<vi> 
#define vvii vector<vii>
#define vvli vector<vli> 
#define vvlii vector<vlii>

#define fi first
#define se second
// #define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

#define fr front
#define bc back

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i) 
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i) 

#define rd_array(arr, a, b) fori(i, a, b) {cin >> arr[i];}
#define rd_matrix(mat, a, b, c, d) fori(i, a, b) fori(j, c, d) {cin >> mat[i][j];}
#define pr_array(arr, a, b) fori(i, a, b) {cout << arr[i] << sp;} cout << endl;
#define pr_matrix(mat, a, b, c, d) fori(i, a, b) { fori(j, c, d) {cout << mat[i][j] << sp;} cout << endl; }
#define rd_vector(arr, n) {arr.resize(n); rd_array(arr, 0, n - 1);}
#define take_vector(a) for(auto &x:a)cin>>x;
#define dbg(x) cout<<#x<<" = "<<x<<ln

#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())

#define gcd __gcd
#define bitcount __builtin_popcountll
#define lcm(a,b) (a/gcd(a,b))*b
#define maxel max_element
#define minel min_element
#define accu(a, b) accumulate(a, b,0)
#define lwb lower_bound
#define upb upper_bound

#define rand rng
#define endl '\n'
#define sp ' '

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define int long long // for convenience, not recommended
// #define double long double

const int maxn = 2e6 + 5, mod = 1e9 + 7, inf = 1e12; 
const ld pi = 4 * atan(1.0), eps = 1e-9; 

void solve(); 

signed main() {
   #ifndef ONLINE_JUDGE
      freopen("input.inp","r",stdin);
      freopen("output.out","w",stdout);
   #endif
   fastio();
   int tc = 1; 
    cin >> tc;
   fori(test, 1, tc) {
//    cout << "Case #" << test << ": "; 
      solve();
   }
   return 0;
}   

int n, m; 
vii seg; int arr[maxn]; map<int, int> mp; 
vi R[maxn]; 
int dp[maxn], mn[maxn], mn2[maxn], check[maxn]; 
int rl[maxn]; 

void solve() {
   // remember to reset all values each test
   cin >> n >> m; 
   seg = vii(); mp = map<int, int>(); 
   fori(i, 1, n) {
      cin >> arr[i]; 
      mp[arr[i]] = 1; 
   }
   arr[0] = -inf, arr[n + 1] = inf; 
   mp[-inf] = mp[inf] = 1; 
   fori(i, 1, m) { 
      int l, r; cin >> l >> r; 
      seg.eb(l, r); 
      mp[l] = 1; 
      mp[r] = 1; 
   }
   int tmp = 0; 
   for(auto &t: mp) { 
      t.se = ++tmp; 
      rl[tmp] = t.fi; 
   }

   fori(i, 0, tmp + 4) R[i].clear();
   fill(dp, dp + tmp + 5, inf); 
   fill(mn, mn + tmp + 5, inf); 
   fill(mn2, mn2 + tmp + 5, inf); 
   fill(check, check + tmp + 5, 0); 

   fori(i, 0, n + 1) { 
      check[mp[arr[i]]] = 1; 
   }
   for(auto t : seg) { 
      R[mp[t.fi]].eb(mp[t.se]); 
   }

   dp[1] = 0; 
   int last = 1; 
   fori(i, 2, tmp) {
      if(!check[i]) continue; 
      int fur = i; 
      ford(j, i - 1, last) { 
         mn2[fur] = min(mn2[fur], dp[j] + 2 * (rl[i] - rl[fur])); 
         mn[fur] = min(mn[fur], dp[j] + (rl[i] - rl[fur]));
         for(int r: R[j])  { 
            fur = min(fur, r); 
         }
      }
      ford(j, i - 1, last + 1) { 
         mn2[j] = min(mn2[j], mn2[j + 1]); 
      }
      fori(j, last + 2, i) { // it may visit >= last + 1, so ... 
         mn[j] = min(mn[j], mn[j - 1]); 
      }
      int ptr = i; 
      fori(j, i, tmp) { 
         if(check[j] and j > i) break; 
         while(ptr - 1 > last and rl[i] - rl[ptr - 1] <= rl[j] - rl[i]) --ptr; 
         dp[j] = min(mn2[ptr] + rl[j] - rl[i], mn[ptr] + 2 * (rl[j] - rl[i])); 
      }
      last = i; 
      assert(1 <= last and last <= tmp); 
   }
   cout << dp[tmp] << endl; 
}