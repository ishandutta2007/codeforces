#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  vector<int> d(n, n);
  int last = -1;
  for (int i = 0; i < n; ++i) {
    if (!a[i]) {
      last = i;
    }
    if (last >= 0) {
      d[i] = min(d[i], i - last);
    }
  }
  last = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (!a[i]) {
      last = i;
    }
    if (last >= 0) {
      d[i] = min(d[i], last - i);
    }
  }
  for (int x : d) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}