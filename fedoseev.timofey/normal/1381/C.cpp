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
    int n, x, y;
    cin >> n >> x >> y;
    int xx = x, yy = y;
    y -= x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    vector <int> b(n, -1);
    vector <vector <int>> where(n + 1);
    for (int i = 0; i < n; ++i) where[a[i]].push_back(i);
    vector <int> cnt(n + 1);
    for (int i = 0; i < n; ++i) ++cnt[a[i]];
    int em = -1;
    for (int i = 0; i <= n; ++i) if (cnt[i] == 0) em = i;
    set <pair <int, int>> gs;
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] > 0) gs.insert({cnt[i], i});
    }
    while (x > 0) {
      --x;
      auto p = *gs.rbegin();
      gs.erase(--gs.end());
      int c = p.second;
      --cnt[c];
      b[where[c].back()] = c;
      where[c].pop_back();
      if (cnt[c] > 0) {
        gs.insert({cnt[c], c});
      }
    }
    vector <int> good;
    for (int i = 0; i <= n; ++i) if (cnt[i] > 0) good.push_back(i);
    sort(good.begin(), good.end(), [&] (int i, int j) {
      return cnt[i] > cnt[j];
    });
    vector <int> gg;
    for (int x : good) {
      gs.erase({cnt[x], x});
      for (int i : where[x]) {
        if (y == 0) break;
        if (!gs.empty()) {
          int c = gs.rbegin()->second;
          gs.erase({cnt[c], c});
          --cnt[c];
          b[i] = c;
          if (cnt[c] > 0) gs.insert({cnt[c], c});
          --y;
        } else {
          while (!gg.empty() && cnt[gg.back()] == 0) gg.pop_back();
          if (!gg.empty()) {
            b[i] = gg.back();
            --cnt[gg.back()];
            --y;
          }
        }
      }
      gg.push_back(x);
    }
    for (int i = 0; i < n; ++i) if (b[i] == -1) b[i] = em;
    if (y > 0) {
      cout << "NO\n";
    } else {
      int tx = 0, ty = 0; 
      for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++tx;
      vector <int> cnt1(n + 1), cnt2(n + 1);
      for (int i = 0; i < n; ++i) ++cnt1[a[i]];
      for (int i = 0; i < n; ++i) ++cnt2[b[i]];
      for (int i = 0; i <= n; ++i) ty += min(cnt1[i], cnt2[i]);
      assert(tx == xx && ty == yy);

      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        cout << b[i] + 1 << ' ';
      }
      cout << '\n';
    }
  }
}