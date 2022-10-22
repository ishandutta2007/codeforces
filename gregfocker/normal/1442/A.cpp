#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = 30000 + 7;
int n;
int a[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

///  freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int difs = 0;
    for (int i = 1; i < n; i++) {
      difs += max(0LL, a[i] - a[i + 1]);
    }
    if (difs <= a[1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}