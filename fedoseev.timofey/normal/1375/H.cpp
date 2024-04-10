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
 
const int N = 1 << 12;
const int max_size = 1 << 8;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
 
  vector <int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }
 
  int cnt = n;
  vector <pair <int, int>> ans;
  auto get = [&] (int f, int s) {
    if (f == 0) return s;
    if (s == 0) return f;
    ans.push_back({f, s}); 
    return ++cnt;
  };
  vector <map <pair <int, int>, int>> id;
 
  function <void(int, int, int)> build = [&] (int l, int r, int v) {
    if (l < r) {
      int m = (l + r) >> 1;
      build(l, m, 2 * v + 1);
      build(m + 1, r, 2 * v + 2);
      if (r - l + 1 <= max_size) {
        vector <int> where;
        for (int i = l; i <= r; ++i) {
          where.push_back(pos[i]);
        }
        sort(where.begin(), where.end());
        for (int L = 0; L < (int)where.size(); ++L) {
          int l_f = n - 1, r_f = 0, l_s = n - 1, r_s = 0; 
          for (int R = L; R < (int)where.size(); ++R) {
            if (a[where[R]] <= m) {
              l_f = min(l_f, where[R]);
              r_f = max(r_f, where[R]);
            } else {
              l_s = min(l_s, where[R]);
              r_s = max(r_s, where[R]);
            }
            id[v][{where[L], where[R]}] = get(id[2 * v + 1][{l_f, r_f}], id[2 * v + 2][{l_s, r_s}]);
          }
        }
      }
    } else {
      while (id.size() <= v) id.push_back({});
      id[v][{pos[l], pos[l]}] = pos[l] + 1; 
    }
  };
  build(0, n - 1, 0);  
  function <int(int, int, int, int, int)> answer = [&] (int ql, int qr, int l, int r, int v) {
    if (r - l + 1 > max_size) {
      int m = (l + r) >> 1;
      int f = answer(ql, qr, l, m, 2 * v + 1);
      int s = answer(ql, qr, m + 1, r, 2 * v + 2);
      return get(f, s);
    } else {
      int l_f = n - 1, r_f = 0;
      for (int i = l; i <= r; ++i) {
        int x = pos[i];
        if (ql <= x && x <= qr) {
          l_f = min(l_f, x);
          r_f = max(r_f, x);
        }
      }
      return id[v][{l_f, r_f}];
    }
  };
 
  vector <int> who;
 
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    who.push_back(answer(l, r, 0, n - 1, 0));
  }
  cout << cnt << '\n';
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
  for (int x : who) cout << x << ' ';
}