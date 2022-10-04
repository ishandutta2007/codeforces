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
  vector <int> L(m), R(m);
  for (int i = 0; i < m; ++i) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }
  vector <vector <int>> gs(n); 
  auto fake_add = [&] (int x, int y) {
    x = n - x - 1;
    for (int i = x; i < n; i |= i + 1) {
      gs[i].push_back(y); 
    }
  };
  for (int i = 0; i < m; ++i) {
    fake_add(L[i], R[i]);
  }
  vector <vector <vector <int>>> fen(n);
  for (int i = 0; i < n; ++i) {
    sort(gs[i].begin(), gs[i].end());
    gs[i].resize(unique(gs[i].begin(), gs[i].end()) - gs[i].begin());
    fen[i].resize(gs[i].size());
  }
  auto add = [&] (int x, int y, int id) {
    x = n - x - 1;
    for (int i = x; i < n; i |= i + 1) {
      for (int j = lower_bound(gs[i].begin(), gs[i].end(), y) - gs[i].begin(); j < (int)gs[i].size(); j |= j + 1) {
        fen[i][j].push_back(id);
      }
    }
  };
  for (int i = m - 1; i >= 0; --i) {
    add(L[i], R[i], i);
  }
  vector <int> ans(n + 1);
  function <void(int, int, int)> solve = [&] (int l, int r, int x) {
    if (l > r) return;
    int best = m;
    for (int i = n - l - 1; i >= 0; i &= i + 1, --i) {
      for (int j = upper_bound(gs[i].begin(), gs[i].end(), r) - gs[i].begin() - 1; j >= 0; j &= j + 1, --j) {
        while (!fen[i][j].empty()) {
          int id = fen[i][j].back();
          if (R[id] - L[id] + 1 < x) {
            fen[i][j].pop_back();
          } else {
            break;
          }
        }
        if (!fen[i][j].empty()) {
          best = min(best, fen[i][j].back());
        }
      }
    }   
    if (best == m) return;
    ans[x] += R[best] - L[best] + 1;
    solve(l, L[best] - 1, x);
    solve(R[best] + 1, r, x);
  };  
  for (int x = 1; x <= n; ++x) {
    solve(0, n - 1, x);
  }
  for (int x = 1; x <= n; ++x) {
    cout << ans[x] << '\n';
  }
}