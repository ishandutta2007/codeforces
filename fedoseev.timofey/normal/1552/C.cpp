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
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> segs;
    vector <int> used(2 * n);
    for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      used[x] = used[y] = 1;
      if (x > y) swap(x, y);
      segs.push_back({x, y});
    }
    auto inter = [&] (int x1, int y1, int x2, int y2) {
      return (x1 < x2 && x2 < y1 && y1 < y2) || (x2 < x1 && x1 < y2 && y2 < y1);
    };
    vector <int> alive;
    for (int i = 0; i < 2 * n; ++i) {
      if (!used[i]) {
        alive.push_back(i);
      }
    }
    for (int i = 0; i < n - k; ++i) {
      segs.push_back({alive[i], alive[i + n - k]});
    }
    int have = 0;
    for (int i = 0; i < (int)segs.size(); ++i) {
      for (int j = i + 1; j < (int)segs.size(); ++j) {
        have += inter(segs[i].first, segs[i].second, segs[j].first, segs[j].second);
      }
    }
    /*int best = 0;
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = i + 1; j < 2 * n; ++j) {
        if (used[i] || used[j]) continue;
        int cnt = 0;
        for (auto p : segs) {
          cnt += inter(p.first, p.second, i, j);
        }
        best = max(best, cnt);
      }
    }
    for (int i = 0; i < n - k; ++i) {
      have += best;
      ++best;
    }*/
    cout << have << '\n';
  }
}