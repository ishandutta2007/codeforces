#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int const ALPHA = 26;
  vector<int> lds(n);
  vector<int> max_lds(ALPHA);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int c = (s[i] - 'a' + 1); c < ALPHA; ++c) {
      cur = max(cur, max_lds[c]);
    }
    lds[i] = cur + 1;
    max_lds[s[i] - 'a'] = max(max_lds[s[i] - 'a'], cur + 1);
  }
  cout << *max_element(lds.begin(), lds.end()) << '\n';
  for (auto x : lds) {
    cout << x << ' ';
  }
  cout << '\n';
}