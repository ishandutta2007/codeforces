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

int n, q, Q, t, T, a[400004];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  int m = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != a[0]) {
      m = i;
      break;
    }
  }
  f0r(i, n) {
    if (a[i] != a[n-1]) {
      m = max(m, n - 1 - i);
      break;
    }
  }
  cout << m << endl;
}