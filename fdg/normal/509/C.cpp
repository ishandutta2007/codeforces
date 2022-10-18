#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<string> ans;

int main() {
  int n, a;
  scanf("%d", &n);
  ans.push_back("0");
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    int len = max((a + 8) / 9, (int) ans.back().size());
    string best = "", cur = ans.back();
    int sum = 0;
    if (len == cur.size())
      for (int i = 0; i < len; ++i) {
        for (int d = cur[i] - '0' + 1; d < 10; ++d) {
          string tmp = cur;
          tmp[i] = d + '0';
          int left = a - sum - d;
          if (left >= 0)
            for (int j = len - 1; j > i; --j) {
              tmp[j] = min(left, 9) + '0';
              left -= min(left, 9);
            }
          if (left == 0 && (best == "" || best > tmp))
            best = tmp;
        }
        sum += cur[i] - '0';
      }
    if (best != "") {
      ans.push_back(best);
    } else {
      len = max((a + 8) / 9, (int) ans.back().size() + 1);
      best = string(len, '0');
      int f = max(1, a - (len - 1) * 9);
      best[0] = f + '0';
      int left = a - f;
      for (int i = len - 1; i > 0; --i) {
        best[i] = min(left, 9) + '0';
        left -= min(left, 9);
      }
      ans.push_back(best);
    }
  }
  for (int i = 1; i < ans.size(); ++i)
    cout << ans[i] << endl;
  return 0;
}