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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;
  vector <pair <int, int>> st;
  ll sum = 0;
  int cur_len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++cur_len;
      int cnt = 0;
      while (!st.empty() && st.back().first < cur_len) {
        sum -= (ll)st.back().first * st.back().second;
        cnt += st.back().second;
        st.pop_back();
      }
      sum += (ll)cnt * cur_len;
      st.push_back({cur_len, cnt});
    } else {
      for (int i = cur_len; i >= 0; --i) {
        st.push_back({i, 1});
        sum += i;
      }
      cur_len = 0;
    }
    ans += sum;
    ans += (ll)cur_len * (cur_len + 1) / 2;
  }
  cout << ans << '\n';
}