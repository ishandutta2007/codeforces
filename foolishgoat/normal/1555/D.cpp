#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> presum;
  vector<char> ch(3);
  for (ch[0] = 'a'; ch[0] <= 'c'; ++ch[0]) {
    for (ch[1] = 'a'; ch[1] <= 'c'; ++ch[1]) {
      if (ch[1] == ch[0]) continue;
      for (ch[2] = 'a'; ch[2] <= 'c'; ++ch[2]) {
        if (ch[2] == ch[0] || ch[2] == ch[1]) continue;
        presum.emplace_back(n+1, 0);
        for (int i = 0; i < n; ++i) {
          presum.back()[i+1] = presum.back()[i] + (s[i] != ch[i % 3]);
        }
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    int ans = r - l;
    for (int j = 0; j < (int)presum.size(); ++j) {
      ans = min(ans, presum[j][r] - presum[j][l]);
    }
    cout << ans << '\n';
  }
  return 0;
}