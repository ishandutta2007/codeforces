#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> operations;
    bool fail = false;
    for (int lcp = 0; lcp < n; ++lcp) {
      auto cs = s[lcp];
      auto ct = t[lcp];
      if (cs == ct) {
        continue;
      }
      for (int i = lcp + 1; i < n; ++i) {
        if (s[i] == cs) {
          operations.emplace_back(i + 1, lcp + 1);
          swap(s[i], t[lcp]);
          break;
        }
        if (t[i] == cs) {
          operations.emplace_back(i + 1, i + 1);
          swap(s[i], t[i]);
          operations.emplace_back(i + 1, lcp + 1);
          swap(s[i], t[lcp]);
          break;
        }
      }
      if (s[lcp] != t[lcp]) {
        fail = true;
        break;
      }
    }
    if (fail) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n" << operations.size() << '\n';
    for (auto[i, j] : operations) {
      cout << i << ' ' << j << '\n';
    }
  }
  return 0;
}