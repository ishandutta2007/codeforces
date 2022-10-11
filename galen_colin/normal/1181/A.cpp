#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int main() {
  io;
  ll x, y, z; cin >> x >> y >> z;
  ll a = (x / z) * z, b = (y / z) * z, h = ((x + y) / z);
  /* no reason to */
  if (h == a/z + b/z) {
    cout << h << " " << 0 << endl;
    exit(0);
  }
  ll c = x - a, d = y - b;
  if (c == d && d == 0) {
    cout << h << " " << 0 << endl;
  }
  else if (c > d) {
    cout << h << " " << (z + a) - x << endl;
  } else {
    cout << h << " " << (z + b) - y << endl;
  }
}