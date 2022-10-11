#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}
 
// bool prime[1000001]; 
// void sieve(int n) { 
//   ms(prime, 1);
//   for (int p=2; p*p<=n; p++) { 
//     if (prime[p] == true) { 
//       for (int i=p*p; i<=n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
// } 

const ll mod = 998244353;

// ll mpow(ll base, ll exp) {
//   ll res = 1;
//   while (exp) {
//     if (exp % 2 == 1){
//         res = (res * base) % mod;
//     }
//     exp >>= 1;
//     base = (base * base) % mod;
//   }
//   return res;
// }

ll n, q, Q, T, m, k, r, x, y, z, g;
bool mat[2001][2001];
ll cb[2001][2], rb[2001][2];
bool chas[2001], rhas[2001];
ll val[2001][2001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  cin >> n >> k;
  m = n;
  f0r(i, n) {
    string s; cin >> s;
    f0r(j, n) {
      mat[i][j] = (s[j] == 'B');
    }
  }
  f0r(i, n) {
    rb[i][0] = 2001;
    rb[i][1] = -1;
    rhas[i] = 0;
    f0r(j, m) {
      if (mat[i][j]) {
        rhas[i] = 1;
        rb[i][0] = min(rb[i][0], j);
        rb[i][1] = max(rb[i][1], j);
      }
    }
    // cout << rb[i][0] << " " << rb[i][1] << endl;
  }
  f0r(i, m) {
    cb[i][0] = 2001;
    cb[i][1] = -1;
    chas[i] = 0;
    f0r(j, n) {
      if (mat[j][i]) {
        chas[i] = 1;
        cb[i][0] = min(cb[i][0], j);
        cb[i][1] = max(cb[i][1], j);
      }
    }
    // cout << cb[i][0] << " " << cb[i][1] << endl;
  }
  ll ocnt = 0;
  f0r(i, n) ocnt += !rhas[i];
  f0r(i, m) ocnt += !chas[i];

  // do cols first
  f0r(i, n - k + 1) {
    ll cnt = 0;
    f0r(j, k) {
      if (chas[j] && i <= cb[j][0] && i + k - 1 >= cb[j][1]) cnt++;
    }
    val[i][0] = cnt;
    f1r(j, k, m) {
      if (chas[j - k] && i <= cb[j - k][0] && i + k - 1 >= cb[j - k][1]) cnt--;
      if (chas[j] && i <= cb[j][0] && i + k - 1 >= cb[j][1]) cnt++;
      val[i][j - k + 1] = cnt;
    }
  }

  f0r(i, m - k + 1) {
    ll cnt = 0;
    f0r(j, k) {
      if (rhas[j] && i <= rb[j][0] && i + k - 1 >= rb[j][1]) cnt++;
    }
    val[0][i] += cnt;
    f1r(j, k, n) {
      if (rhas[j - k] && i <= rb[j - k][0] && i + k - 1 >= rb[j - k][1]) cnt--;
      if (rhas[j] && i <= rb[j][0] && i + k - 1 >= rb[j][1]) cnt++;
      val[j - k + 1][i] += cnt;
    }
  }
  // f0r(i, n) {
  //   f0r(j, n) cout << val[i][j] << " ";
  //   cout << endl;
  // }
  ll mval = 0;
  f0r(i, n) f0r(j, n) mval = max(val[i][j], mval);
  cout << mval + ocnt << endl;
}