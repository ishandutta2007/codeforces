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
  int n, m;
  cin >> n >> m;
  vector<pair<vector<int>, int>> gs(n);
  for (int i = 0; i < n; ++i) {
    gs[i].first.resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> gs[i].first[j];
    }
    sort(gs[i].first.begin(), gs[i].first.end());
    cin >> gs[i].second;
  }
  sort(gs.begin(), gs.end(), [&](auto &f, auto &s) {
    return f.second < s.second;
  });
  const ll Inf = 1e18;
  ll ans = Inf;
  vector<pair<vector<int>, int>> nw;
  for (auto &v : gs) {
    vector<int> cnt(1 << m);
    bool fnd = false;
    for (auto &cur : nw) {
      if (v.second + cur.second > ans) {
        fnd = true;
        break;
      }
      int uk = 0; 
      int mask = 0;
      for (int i = 0; i < m; ++i) {
        while (uk < m && cur.first[uk] < v.first[i]) ++uk;
        if (uk < m && cur.first[uk] == v.first[i]) {
          mask |= (1 << i);
        }
      }
      if (mask == 0) {
        ans = min(ans, (ll)v.second + cur.second);
        fnd = true;
        break;
      }
      ++cnt[mask];
    }
    if (fnd || ans != Inf) continue;
    bool ok = true;
    for (int mask = 1; mask < (1 << m); ++mask) {
      int pw = 1;
      for (int i = 0; i < m; ++i) if (!(mask & (1 << i))) pw *= m;
      if (cnt[mask] >= pw) {
        ok = false;
      }
    }
    if (ok) nw.push_back(v);
  }
  if (ans != Inf) {
    cout << ans << '\n';
  } else {
    cout << "-1\n";
  }
}