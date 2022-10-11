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

ll n, q, Q, t, T, a[1003], b[1003];

int main() {
  io;
  cin >> n >> q;
  f0r(i, n) cin >> a[i];
  int l = 1, h = n;
  while (l <= h) {
    int m = (l + h) / 2;
    f0r(i, m) b[i] = a[i];
    sort(b, b + m);
    reverse(b, b + m);
    ll left = q;
    f0r(i, m) {
      left -= b[i];
      i++;
    }
    if (left >= 0) l = m + 1;
    else h = m - 1;
  }
  cout << h << endl;
}