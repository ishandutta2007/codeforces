#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

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

const ll inf = 1e12;
const ll mod = 1e9 + 7;

namespace modop {
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
    return mpow(base, mod - 2);
  }
  ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
  }
}

using namespace modop;

ll sum(ll x) {
  ll s = 0;
  while (x > 0) {
    s += x % 10;
    x /= 10;
  }
  return s;
}

vector<ll> numbers;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n; cin >> n;

  for (ll i = max((ll) 1, n - 100); i <= n; i++) {
    if (i + sum(i) == n) {
      numbers.pb(i);
    }
  }

  cout << numbers.size() << endl;
  f0r(i, numbers.size()) {
    cout << numbers[i] << endl;
  }


}