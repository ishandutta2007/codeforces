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

ll n, Q, T, m, k, r, x;
ll a[100001], used[2][10][100001], q[100001]; //q = ndigit
ll cnt[25];
ll dig;

int main() {
  io;
  cin >> n;
  ms(cnt, 0);
  f0r(i, n) cin >> a[i];
  f0r(i, n) {
    dig = 0;
    ll x = a[i];
    while (x) {
      x /= 10;
      dig++;
    }
    cnt[dig]++;
    q[i] = dig;
  }
  f0r(i, n) {
    f1r(dig, 1, 11) {
      ll x = a[i], newx = 0, pow = 1, cnt = 0;
      while (x) {
        pow *= 10;
        newx += pow * (x % 10);
        x /= 10;
        cnt++;
        if (cnt < dig) pow *= 10;
      }
      newx = newx % mod;
      used[0][dig][i] = newx;
    }
  }
  f0r(i, n) {
    f1r(dig, 1, 11) {
      ll x = a[i], newx = 0, pow = 1, cnt = 0;
      while (x) {
        newx += pow * (x % 10);
        x /= 10;
        cnt++;
        pow *= 10;
        if (cnt <= dig) pow *= 10;
      }
      newx = newx % mod;
      used[1][dig][i] = newx;
    }
  }
  ll ans = 0;
  f0r(i, n) {
    f1r(dig, 1, 11) {
      ans += (cnt[dig] * used[0][dig][i]) % mod;
      ans += (cnt[dig] * used[1][dig][i]) % mod;
    }
  }
  cout << ans%mod << endl;
}