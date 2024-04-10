// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<pair<int, int>> st;
  int have = 0;
  vector<long long> dp;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++have;      
      while (!st.empty() && st.back().first < have) {
        st.pop_back();
      }
      long long res = 0;
      if (st.empty()) {
        res += 1ll * have * (have + 1) / 2;
        res += 1LL * have * (i - have + 1);
      } else {
        int ind = st.back().second + st.back().first - 1;
        res += dp[ind];
        res += 1LL * (i - ind) * have;                
      }
      dp.push_back(res);
    } else {
      st.emplace_back(have, i - have);
      have = 0;
      dp.push_back(dp.empty() ? 0 : dp.back());
    }
  }
  cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}