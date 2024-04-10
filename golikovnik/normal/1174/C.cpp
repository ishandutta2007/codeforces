#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::string;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> ans(n + 1, -1);
  int clr = 1;
  for (int i = 2; i <= n; i++) {
    if (ans[i] < 0) {
      ans[i] = clr;
      for (int j = i + i; j <= n; j += i) {
        ans[j] = clr;
      }
      clr++;
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}