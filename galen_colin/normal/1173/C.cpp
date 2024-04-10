#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

const int mn = 200020;
int a[mn], b[mn], t[mn], lp, m;

int main() {
  int n; cin >> n;
  f0r(i, n) cin >> a[i];
  f0r(i, n) cin >> b[i];
  int best = 0, c = 0;
  f0r(i, n) {
    if (b[i] - 1 == c) {
      c++;
      best++;
    } else {
      c = 0;
      best = 0;
    }
  }
  int m = -10000000;
  f0r(i, n - best) {
    if (b[i] == 0) continue;
    m = max(m, i - b[i]);
  }
  if (m + 1 < -best) cout << n - best << endl;
  else if (best == 0) cout << n + m + 2 << endl;
  else cout << 2 * n - best + 1 << endl;
}