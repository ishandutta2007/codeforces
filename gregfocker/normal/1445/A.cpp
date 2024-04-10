#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (auto &x : a) {
      cin >> x;
    }
    for (auto &x : b) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] + b[i] > x) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

}