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
  string s;
  cin >> s;
  int uk;
  vector <int> p;
  vector <int> b;

  function <bool(int, int)> solve = [&] (int l, int r) {
    if (l + 1 == r) {
      p[l] = l;
      return true;
    }
    int m = (l + r) / 2;
    if (!solve(l, m)) return false;
    if (!solve(m, r)) return false;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
      if (uk >= (int)s.size()) {
        return false;
      }
      if (s[uk] == '0') {
        b[k++] = p[i++];
      } else {
        b[k++] = p[j++];
      }
      ++uk;
    }
    while (i < m) b[k++] = p[i++];
    while (j < r) b[k++] = p[j++];
    for (int id = l; id < r; ++id) p[id] = b[id];
    return true;
  };
  int l = 0, r = (int)1e5 + 7;
  while (r - l > 1) {
    int sz = (l + r) / 2;
    p.resize(sz);
    b.resize(sz);
    uk = 0;
    if (!solve(0, sz)) {
      r = sz;
      continue;
    }
    if (uk != (int)s.size()) {
      l = sz;
      continue;
    }
    vector <int> ans(sz);
    for (int i = 0; i < sz; ++i) ans[p[i]] = i;
    cout << sz << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    return 0;
  }
  assert(false);
}