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
  bool bad;
  function <vector <int>(int, int)> solve = [&] (int l, int r) {
    if (bad) return vector <int> ();
    if (l + 1 == r) {
      return vector <int> {l};
    }
    int m = (l + r) / 2;
    auto p1 = solve(l, m);
    auto p2 = solve(m, r);
    if (bad) return vector <int> ();
    vector <int> p;
    int i = 0, j = 0;
    while (i < (int)p1.size() && j < (int)p2.size()) {
      if (uk >= (int)s.size()) {
        bad = true;
        return vector <int> ();
      }
      if (s[uk] == '0') {
        if (i >= (int)p1.size()) {
          bad = true;
          return vector <int> ();
        }
        p.push_back(p1[i++]);
      } else {
        if (j >= (int)p2.size()) {
          bad = true;
          return vector <int> ();
        }
        p.push_back(p2[j++]);
      }
      ++uk;
    }
    while (i < (int)p1.size()) p.push_back(p1[i++]);
    while (j < (int)p2.size()) p.push_back(p2[j++]);
    return p;
  };
  const int N = 2e5 + 7;
  vector <int> mn(N), mx(N);
  for (int i = 2; i < N; ++i) {
    int l = i / 2, r = i - l;
    mn[i] = mn[l] + mn[r];
    mx[i] = mx[l] + mx[r];
    mn[i] += min(l, r);
    mx[i] += i - 1;
  }
  for (int sz = 1; sz < N; ++sz) {
    if (!(mn[sz] <= (int)s.size() && (int)s.size() <= mx[sz])) continue;
    bad = false;
    uk = 0;
    auto p = solve(0, sz);
    if (p.empty() || bad || uk != (int)s.size()) continue;
    vector <int> ans(sz);
    for (int i = 0; i < sz; ++i) ans[p[i]] = i;
    cout << sz << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    return 0;
  }
}