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
    string s;
    cin >> s;
    int n = s.size();
    int ans = n + 1;
    vector <vector <int>> wh(3);
    for (int i = 0; i < n; ++i) {
      wh[s[i] - '1'].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      vector <int> need;
      need.push_back((s[i] - '1' + 1) % 3);
      need.push_back((s[i] - '1' + 2) % 3);
      sort(need.begin(), need.end());
      do {
        auto it = lower_bound(wh[need[0]].begin(), wh[need[0]].end(), i);
        auto jt = lower_bound(wh[need[1]].begin(), wh[need[1]].end(), i);
        if (it != wh[need[0]].begin() && jt != wh[need[1]].end()) {
          ans = min(ans, (*jt) - (*prev(it)) + 1);
        }
      } while (next_permutation(need.begin(), need.end()));
    }
    cout << (ans == n + 1 ? 0 : ans) << '\n';
  }
}