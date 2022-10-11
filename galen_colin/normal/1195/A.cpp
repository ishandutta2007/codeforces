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
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;
const ll mod = 1e9 + 7;

ll n, q, Q, T, m, k, r, x;
ll a[500001], b;

int main() {
  io;
  cin >> n >> k;
  ms(a, 0);
  f0r(i, n) {
    int x; cin >> x;
    a[--x]++;
  }
  ll set = ceil((double)n/2.0);
  set *= 2;
  ll ans = 0;
  f0r(i, k) {
    if (set == 0) break;
    if (a[i] % 2 == 0) {
      ll d = min(a[i], set);
      set -= d;
      ans += d;
      a[i] -= d;
      if (set == 0) break;
    }
  }
  f0r(i, k) {
    if (set == 0) break;
    if (a[i] % 2 == 1) {
      ll d = min(a[i]-1, set);
      set -= d;
      ans += d;
      a[i] -= d;
    }
  }
  f0r(i, k) {
    if (set == 0) break;
    if (a[i] % 2 == 1) {
      ll d = min(1LL, set);
      set -= 2;
      ans += d;
      a[i] -= d;
    }
  }
  cout << ans << endl;
}