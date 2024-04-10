#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll


bool e(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

bool compus(int x) {
  if (x <= 1) return 0;
  return !e(x);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      sum += x;
    }
    if (compus(sum)) {
      cout << n << "\n";
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << "\n";
      continue;
    }
    bool deja = 0;
    for (int i = 0; i < n; i++) {
      if (compus(sum - a[i])) {
        cout << n - 1 << "\n";
        for (int j = 0; j < n; j++) {
          if (i != j) {
            cout << j + 1 << " ";
          }
        }
        cout << "\n";
        deja = 1;
        break;
      }
    }
    assert(deja);
  }


  return 0;
}