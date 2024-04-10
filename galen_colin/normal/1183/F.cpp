#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, q, Q, t, T;

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n;
    vector<ll> a;
    f0r(i, n) {
      ll x; cin >> x;
      a.pb(x); 
    }
    set<ll> s(a.begin(), a.end());
    a.assign(s.begin(), s.end());
    n = s.size();
    if (n == 1) {
      cout << a[0] << endl;
      continue;
    }
    ll sum = a[n-1], next = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (next == -1) {
        if (a[n-1] % a[i] != 0) {
          next = a[i];
          sum += a[i];
        }
      } else {
        if (a[n-1] % a[i] != 0 && next % a[i] != 0) {
          sum += a[i];
          break;
        }
      }
    }
    ll ans = sum;

    if (n == 2) {
      cout << ans << endl;
      continue;
    }
    sum = a[n-2], next = -1;
    for (int i = n - 3; i >= 0; i--) {
      if (next == -1) {
        if (a[n-2] % a[i] != 0) {
          next = a[i];
          sum += a[i];
        }
      } else {
        if (a[n-2] % a[i] != 0 && next % a[i] != 0) {
          sum += a[i];
          break;
        }
      }
    }

    cout << max(sum, ans) << endl;
  }
}