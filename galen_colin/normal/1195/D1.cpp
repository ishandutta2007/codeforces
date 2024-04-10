#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef unsigned long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;
const ll mod = 998244353;

ll n, q, Q, T, m, k, r, x;
ll a[100001], used[2][100001];
ll dig = 0;

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  ll x = a[0];
  while (x) {
    x /= 10;
    dig++;
  }
  if (dig == 10) {
    
  }
  f0r(i, n) {
    ll x = a[i], newx = 0, pow = 1;
    while (x) {
      pow *= 10;
      newx += pow * (x % 10);
      x /= 10;
      pow *= 10;
    }
    newx = newx % mod;
    used[0][i] = newx;
  }
  f0r(i, n) {
    ll x = a[i], newx = 0, pow = 1;
    while (x) {
      newx += pow * (x % 10);
      x /= 10;
      pow *= 100;
    }
    newx = newx % mod;
    used[1][i] = newx;
  }
  ll ans = 0;
  f0r(i, n) {
    ans += (n * used[0][i]) % mod;
    ans += (n * used[1][i]) % mod;
  }
  cout << ans%mod << endl;
}