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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <pair <int, int>> gs;
    for (int i = 0; i < n; ++i) {
      if (gs.empty() || s[i] - '0' != gs.back().first) {
        gs.push_back({s[i] - '0', 1});
      } else {
        ++gs.back().second;
      }
    } 
    int m = gs.size();
    vector <int> pref(m + 1), suf(m + 1);
    for (int i = 0; i < m; ++i) {
      pref[i + 1] = pref[i] | (gs[i].first == 1);
    }
    for (int i = m - 1; i >= 0; --i) {
      suf[i] = suf[i + 1] | (gs[i].first == 0);
    }
    string ans;

    if (gs[0].first == 0) {
      for (int j = 0; j < gs[0].second; ++j) ans += '0';
    }   
    bool fl = false;
    for (int i = 1; i < m; ++i) if (gs[i].first == 0) fl = true;
    if (fl) ans += '0';
    if (gs.back().first == 1) {
      for (int j = 0; j < gs.back().second; ++j) ans += '1';
    }
    cout << ans << '\n';
  }
}