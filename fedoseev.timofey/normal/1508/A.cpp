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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <string> gs(3);
    for (int i = 0; i < 3; ++i) cin >> gs[i];
    string ans;
    for (int i = 0; i < 3; ++i) {
      if (!ans.empty()) break;
      for (int j = i + 1; j < 3; ++j) {
        if (!ans.empty()) break;
        for (int c = 0; c <= 1; ++c) {
          vector <int> p1, p2;
          for (int t = 0; t < 2 * n; ++t) {
            if (gs[i][t] == '0' + c) {
              if (p1.size() < n) p1.push_back(t);
            }
            if (gs[j][t] == '0' + c) {
              if (p2.size() < n) p2.push_back(t);
            }
          }
          if (p1.size() == n && p2.size() == n) {
            p1.insert(p1.begin(), -1);
            p2.insert(p2.begin(), -1);
            p1.push_back(2 * n);
            p2.push_back(2 * n);
            vector <string> need(n + 1); 
            for (int t = 1; t < (int)p1.size(); ++t) {
              need[t - 1] += gs[i].substr(p1[t - 1] + 1, p1[t] - p1[t - 1] - 1);
            }
            for (int t = 1; t < (int)p2.size(); ++t) {
              need[t - 1] += gs[j].substr(p2[t - 1] + 1, p2[t] - p2[t - 1] - 1);
            }
            for (int t = 0; t < n + 1; ++t) {
              ans += need[t];
              if (t != n) ans += char('0' + c);
            }
            break;
          }
        }
      }
    }
    while (ans.size() < 3 * n) ans += '0';
    cout << ans << '\n';
  }
}