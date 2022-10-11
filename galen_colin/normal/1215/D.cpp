#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
#define ai(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define ain(a, lb, rb) for (int i = lb; i <= rb; i++) cin >> a[i];
#define ao(a, n) for (int i = 0; i < n; i++) { if (i) cout << " "; cout << a[i]; } cout << endl;
#define aout(a, lb, rb) for (int i = lb; i <= rb; i++) { if (i > lb) cout << " "; cout << a[i]; } cout << endl;
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
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
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const ll mod = 998244353;
 
ll madd(ll a, ll b) {
  return (a + b) % mod;
}
ll msub(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b) {
  return ((a % mod) * (b % mod)) % mod;
}
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
ll minv(ll base) {
  return mpow(base, mod - 1);
}
ll mdiv(ll a, ll b) {
  return mmul(a, minv(b));
}
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
// bool prime[10000006]; 
// void sieve(int n) { 
//   f0r(i, n + 1) prime[i] = 1;
//   for (int p = 2; p * p <= n; p++) { 
//     if (prime[p] == true) { 
//       for (int i = p * p; i <= n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
//   prime[1] = prime[0] = 0;
// } 
 
ll n, m, q, Q, T, k, l, r, x, y, z, g;
ll a[1000005];
ll b[1000005];
string s;
int moves[2], sum[2];
int tmoves;
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> s;
  ms(sum, 0);
  ms(moves, 0);
  f0r(i, n) {
    if (s[i] == '?') moves[i / (n/2)]++;
    else sum[i / (n/2)] += s[i] - '0';
  }

  tmoves = moves[0] + moves[1];

  if ((sum[0] == sum[1] && tmoves == 0) || (tmoves == n)) {
    cout << "Bicarp" << endl;
    exit(0);
  }
  // ao(moves, 2);
  // ao(sum, 2);

  bool f = 1;

  //pump left or right
  f0r(f1, 2) {
    //bicarp maxes
    int mleft, mright;
    if (f1) {
      mleft = moves[0] / 2;
      if (moves[0] >= moves[1]) {
        mright = moves[1];
      } else {
        mright = moves[0] + (moves[1] - moves[0]) / 2;
      }
    } else {
      mright = moves[1] / 2;
      if (moves[1] >= moves[0]) {
        mleft = moves[0];
      } else {
        mleft = moves[1] + (moves[0] - moves[1]) / 2;
      }
    }

    //pump with zeroes or nines
    f0r(f2, 2) {
      bool ok = 0;

      //bicarp's moves, how much does he spend on the left
      f0r(bic, tmoves / 2 + 1) {
        int nleft = bic, nright = tmoves / 2 - bic;

        //can he even do this
        if (nleft <= mleft && nright <= mright) {
          //does he win

          //mono pumps
          int mvleft = (f2 ? 9 : 0) * (moves[0] - nleft);
          int mvright = (f2 ? 0 : 9) * (moves[1] - nright);
          int osum[2];
          osum[0] = sum[0] + mvleft;
          osum[1] = sum[1] + mvright;
          if (osum[0] >= osum[1]) {
            if (osum[0] - osum[1] <= 9 * nright) {
              ok = 1;
              break;
            }
          } else {
            if (osum[1] - osum[0] <= 9 * nleft) {
              ok = 1;
              break;
            }
          }
          // cout << osum[0] << " " << osum[1] << endl;
        }
      }

      if (!ok) f = 0;
    }
  }

  cout << (f ? "Bicarp" : "Monocarp") << endl;
}

/* mon can pump zeroes or nines into one side, then the other */
/* only zeroes and nines */
/* no reason for him to change his strategy */
/* so we care about which ones bicarp uses and which ones mon pumps */