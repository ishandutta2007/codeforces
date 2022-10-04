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

struct Fenwick {
  int n;
  vector <int> f;
  void modify(int i, int val) {
    for (; i < n; i |= i + 1) {
      f[i] += val;
    }
  }
  int get(int r) {
    int res = 0;
    for (; r >= 0; r &= r + 1, --r) {
      res += f[r];
    }
    return res;
  }
  Fenwick(int _n) {
    n = _n;
    f.resize(n);
  }
};
 
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector <pair <int, int>> ans;
  set <int> pos;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == s[i + 1]) {
      pos.insert(i);
    }
  }
  vector <set <pair <int, int>>> good(26);
  vector <int> cnt(26);
  auto del = [&] (int i) {
    --cnt[s[i] - 'a'];
    auto it = pos.lower_bound(i);
    if (next(it) != pos.end()) {
      int j = *next(it);
      if (s[i] != s[j]) {
        good[s[i] - 'a'].erase({i, j});
        good[s[j] - 'a'].erase({i, j});
      }
    }
    if (it != pos.begin()) {
      int j = *prev(it);
      if (s[i] != s[j]) {
        good[s[i] - 'a'].erase({j, i});
        good[s[j] - 'a'].erase({j, i});
      }
    }
    if (it != pos.begin() && next(it) != pos.end()) {
      int j = *prev(it);
      int k = *next(it);
      if (s[j] != s[k]) {
        good[s[j] - 'a'].insert({j, k});
        good[s[k] - 'a'].insert({j, k});
      }
    }
    pos.erase(it);
  };

  for (auto it = pos.begin(); it != pos.end(); ++it) {
    int i = *it;
    ++cnt[s[i] - 'a'];
    if (next(it) != pos.end()) {
      int j = *next(it);
      if (s[i] != s[j]) {
        good[s[i] - 'a'].insert({i, j});
        good[s[j] - 'a'].insert({i, j});
      }
    }
  }
  set <int> alive;
  for (int i = 0; i < n; ++i) alive.insert(i);
  Fenwick f(n);
  int cur_size = n;
  auto del_seg = [&] (int l, int r) {
    int nl = l - f.get(l), nr = r - f.get(r);
    ans.push_back({nl, nr}); 
    cur_size -= (nr - nl + 1);
    while (true) {
      auto it = alive.lower_bound(l);
      if (it == alive.end() || (*it) > r) break;
      f.modify(*it, 1);
      alive.erase(it);
    }
  };

  while (!pos.empty()) {
    int mx = 0, id = -1;
    for (int i = 0; i < 26; ++i) {
      if (!good[i].empty() && cnt[i] > mx) {
        id = i;
        mx = cnt[i];
      }
    }
    if (id == -1) {
      while (!pos.empty()) {
        int x = *pos.rbegin();
        del(x);
        del_seg(x + 1, n - 1);
      }
    } else {
      auto pr = *good[id].begin();
      del(pr.first);
      del(pr.second);
      del_seg(pr.first + 1, pr.second);
    }
  }
  if (cur_size > 0) {
    del_seg(0, n - 1);
  }
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}