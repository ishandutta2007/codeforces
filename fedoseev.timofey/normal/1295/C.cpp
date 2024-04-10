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
#include <cassert>
#include <complex>
#include <functional>
 
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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector <vector <int>> where(26);
    for (int i = 0; i < n; ++i) {
      where[s[i] - 'a'].push_back(i);
    }
    int ans = 1, uk = -1;
    bool bad = false;
    for (int i = 0; i < m; ++i) {
      int c = t[i] - 'a';
      if (where[c].empty()) {
        cout << "-1\n";
        bad = true;
        break;
      }
      auto it = upper_bound(where[c].begin(), where[c].end(), uk);
      if (it == where[c].end()) {
        uk = where[c].front();
        ++ans;
      } else {
        uk = *it;
      }
    }
    if (!bad) cout << ans << '\n';
  }
}