#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector <pair <int, pair <int, int>>> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

const int INF = 1e9;
const int MAXN = 250;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  a += "$", b += "$";
  vvi dp(n + 1, vi(MAXN, {-INF, {0, 0}}));
  dp[0][0] = {0, {-1, -1}};
  vvvi save_dp;
  save_dp.push_back(dp);
  while (save_dp.back()[n][0].first != m) {
    vvi dp_new(n + 1, vi(MAXN, {-INF, {0, 0}}));
    for (int i = 0; i <= n; i++)
      for (int bal = 1; bal < MAXN; bal++) {
        if (dp[i][bal].first < 0)
          continue;
        dp_new[(a[i] == ')') + i][bal - 1] = max(dp_new[(a[i] == ')') + i][bal - 1], {dp[i][bal].first + (b[dp[i][bal].first] == ')'), {i, bal}});
      }
    for (int i = 0; i <= n; i++)
      for (int bal = 0; bal + 1 < MAXN; bal++) {
        if (dp[i][bal].first < 0)
          continue;
          dp_new[(a[i] == '(') + i][bal + 1] = max(dp_new[(a[i] == '(') + i][bal + 1], {dp[i][bal].first + (b[dp[i][bal].first] == '('), {i, bal}});
      }
    swap(dp, dp_new);
    save_dp.push_back(dp);
  }
  int it = save_dp.size() - 1;
  vector <char> ans;
  int curbal = 0, i = n;
  while (it >= 1) {
    pair <int, int> st = save_dp[it][i][curbal].second;
    if (st.second > curbal)
      ans.push_back(')');
    else
      ans.push_back('(');
    i = st.first, curbal = st.second;
    it--;
  }
  reverse(ans.begin(), ans.end());
  for (char ch : ans)
    cout << ch;
  return 0;
}