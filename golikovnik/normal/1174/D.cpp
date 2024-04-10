#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::string;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned n, x;
  cin >> n >> x;
  std::set<unsigned> banned;
  banned.insert(x);
  vector<unsigned> ans = {0};
  for (unsigned i = 1; i < (1 << n); i++) {
    if (banned.count(i)) {
      continue;
    }
    banned.insert(i ^ x);
    ans.push_back(i);
  }
  cout << ans.size() - 1 << "\n";
  for (size_t i = 1; i < ans.size(); i++) {
    cout << (ans[i] ^ ans[i - 1]) << " ";
  }
  cout << "\n";
  return 0;
}