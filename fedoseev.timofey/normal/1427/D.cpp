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
  int n;
  cin >> n;
  vector <int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector <int> ord;
  {
    int l = (n + 1) / 2;
    int r = l;
    int it = 0;
    ord.push_back(l);
    while (l != 1 || r != n) {
      if (it % 2 == 1) {
        ord.push_back(--l);
      } else {
        ord.push_back(++r);
      }
      ++it;
    }   
  }
  vector <vector <int>> ans;
  auto apply = [&] (vector <int> go) {
    vector <vector <int>> gs;
    int uk = 0;
    for (int x : go) {
      vector <int> v;
      for (int j = 0; j < x; ++j) {
        v.push_back(c[uk++]);
      }
      gs.push_back(v);
    }
    reverse(gs.begin(), gs.end());
    c.clear();
    for (auto v : gs) {
      for (auto x : v) {
        c.push_back(x);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    vector <int> cur;
    auto add = [&] (int x) {
      if (x > 0) {
        cur.push_back(x);
      }
    };
    if (i % 2 == 0) {
      int len = -1;
      for (int j = 0; j < n; ++j) {
        if (c[j] == ord[i]) {
          len = j - i + 1;
        }
      }
      assert(len > 0);
      add(i);
      add(len);
      add(n - i - len);
    } else {
      int len = -1;
      for (int j = 0; j < n; ++j) {
        if (c[j] == ord[i]) {
          len = n - j - i;
        }
      }
      assert(len > 0);
      add(n - i - len);
      add(len);
      add(i);
    }
    ans.push_back(cur);
    apply(cur);
  }
  assert(is_sorted(c.begin(), c.end()));
  int cnt = 0;
  for (auto v : ans) {
    if (v.size() > 1) {
      ++cnt;
    }
  }
  cout << cnt << '\n';
  for (auto v : ans) {
    if (v.size() > 1) {
      cout << v.size() << ' ';
      for (int x : v) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}