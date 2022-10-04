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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string best;
    auto get_min = [&] (int sum) {
      string res;
      while (sum > 0) {
        int need = (sum + 8) / 9;
        for (int go = 0; go <= min(sum, 9); ++go) {
          int cur = 1 + (sum - go + 8) / 9;
          if (cur == need) {
            res += char('0' + go);
            sum -= go;
            break;
          }
        }
      }
      return res;
    }; 
    auto get_min_good = [&] (int sum) {
      if (sum == 0) return string();
      string ret;
      for (int last = 0; last <= min(sum, 8); ++last) {
        string cur = get_min(sum - last);
        cur += char('0' + last);
        if (ret.empty()) ret = cur;
        if ((int)cur.size() < (int)ret.size() || ((int)cur.size() == (int)ret.size() && cur < ret)) ret = cur;
      }
      return ret;
    };
    for (int cnt_9 = 0; cnt_9 * 9 <= n; ++cnt_9) {
      for (int last = 0; last <= 9; ++last) {
        int cur_sum = cnt_9 * 9 + last;
        
        auto get = [&] (int pref_sum) {
          int all_sum = cur_sum + pref_sum;
          int clast = last;
          int ret = 0;

          for (int i = 0; i <= k; ++i) {
            ret += all_sum;
            ++all_sum;
            ++clast;
            if (clast == 10) {
              clast = 0;
              all_sum -= (cnt_9 + 1) * 9;
            }
          }
          return ret;
        };
        int l = 0, r = 1000;
        while (r - l > 1) {
          int m = (l + r) >> 1;
          if (get(m) <= n) l = m;
          else r = m;
        }
        if (get(l) == n) {
          string cur = get_min_good(l);
          for (int i = 0; i < cnt_9; ++i) cur += '9';
          cur += char('0' + last);
          if (best.empty()) best = cur;
          if ((int)cur.size() < (int)best.size() || ((int)cur.size() == (int)best.size() && cur < best)) best = cur;
        } 
      }
    }
    if (best.empty()) cout << "-1\n";
    else cout << best << '\n';
  }
}