#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  const int N = 1e6 + 7;
  vector<vector<int>> where(N);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    where[a[i]].push_back(i);
  }
  int ans = n;
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    mx = max(mx, (int)where[i].size());
  }
  int l = 0, r = n - 1;
  for (int i = 0; i < N; ++i) {
    if ((int)where[i].size() == mx) {
      if (where[i].back() - where[i].front() + 1 < ans) {
        ans = where[i].back() - where[i].front() + 1;
        l = where[i].front();
        r = where[i].back();
      }
    }
  }
  cout << l + 1 << ' ' << r + 1  << '\n';
}