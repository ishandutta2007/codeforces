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
#define mp make_pair
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

const int maxn = 2e5 + 5, mod = 1e9 + 7, inf = 1e9; 
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
vi g[maxn]; 
int n; 
int leaves; 
int rem; 
int buds; 
int isleave(int i, int p) { 
   int cnt = 0; 
   for(int j: g[i]) { 
      if(j == p) continue; 
      if(isleave(j, i)) { 
         cnt++; 
         leaves++; 
      }
      else buds++;  
   }
   // cout << i << sp << cnt << endl;
   if(i == 1) { 
      rem = cnt > 0; 
      return 0; 
   }
   else { 
      return cnt == 0; 
   }
 }

void solve() {
   // remember to reset all values each test
   cin >> n; 
   leaves =buds = rem = 0; 
   fori(i, 1, n) g[i] = vi(); 
   fori(i, 1, n - 1) { 
      int u, v; cin >> u >> v; 
      g[u].eb(v); 
      g[v].eb(u); 
   }
   isleave(1,1); 
   // cout << rem << endl;
   cout << leaves - (buds - 1) - rem << endl; 
}