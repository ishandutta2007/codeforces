#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  int cnt_l = 0;
  while (cnt_l < n && s[cnt_l] == '0') ++cnt_l;
  s = s.substr(cnt_l, n - cnt_l);
  n = s.size();
  if (n == 0) {
    cout << cnt_l << '\n';
    return 0;
  }
  int cnt_r = 0; 
  while (cnt_r < n && s[n - cnt_r - 1] == '0') ++cnt_r;
  s = s.substr(0, n - cnt_r);
  n = s.size();
  vector <int> dp(n); 
  vector <pair <int, int>> st;
  auto go_merge = [&] () {
    while (st.size() >= 2 && st.rbegin()[0].second == st.rbegin()[1].second) {
      add(st.rbegin()[1].first, st.rbegin()[0].first);
      st.pop_back();
    }
  };  

  int sum = 0;
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      add(dp[i], 1);
      add(dp[i], sum);
      len = 0;
      st.push_back({dp[i], 0});
    } else {
      ++len;
      if (st.back().second < len) {
        add(dp[i], st.back().first);
        st.back().second = len;
      }
      add(sum, dp[i]);
    }
    go_merge();
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) if (s[i] == '1') add(ans, dp[i]);
  ans = mul(ans, mul(cnt_l + 1, cnt_r + 1));
  cout << ans << '\n';
}