#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> a[2];
    for (int i = 0, nxt = 0; i < n; ++i, nxt = 1 - nxt) {
      if (i == 0 or v[i] != v[i - 1]) {
        nxt = 0;
      }
      a[nxt].push_back(v[i]);
    }
    auto mex = [](const vector<int> &input) -> int {
      int nxt = 0;
      for (int i: input) {
        if (i == nxt) ++ nxt;
      }
      return nxt;
    };
    cout << mex(a[0]) + mex(a[1]) << "\n";
  }
}