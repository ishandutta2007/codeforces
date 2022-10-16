#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  std::string s;
  cin >> n >> s;
  std::vector<int> ans;
  int cur = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[cur]) {
      ans.push_back(cur);
      ans.push_back(i);
      cur = ++i;
    }
  }
  cout << n - ans.size() << "\n";
  for (int x : ans) {
    cout << s[x];
  }
  cout << "\n";
  return 0;
}