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
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
  
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <pair <int, int>> ed;
  set <pair <int, int>> hv;
  vector <vector <int>> g(n);
  for (int i = 0; i < 2 * n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    ed.push_back({a, b});
    hv.insert({a, b});
    hv.insert({b, a});
  }
  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 4) {
      cout << "-1\n";
      return 0;
    }
  }
  int a = 0;
  for (int b : g[a]) {
    for (int c : g[b]) {
      if (c == a) continue;
  vector <int> res;
  vector <bool> used(n);
  res.push_back(a);
  res.push_back(b);
  res.push_back(c);
  used[a] = used[b] = used[c] = 1;
  bool bad = false;
  for (int i = 3; i < n; ++i) {
    for (int x : g[res.back()]) {
      if (!used[x] && hv.count({x, res[(int)res.size() - 2]})) {
        res.push_back(x);
        used[x] = 1; 
        break;
      }
    }
    if (res.size() != i + 1) {
      bad = true;
      break;
    }
  }
  if (bad) continue;
  set <pair <int, int>> nh;
  for (int i = 0; i < n; ++i) {
    for (int d = -2; d <= 2; ++d) {
      if (d == 0) continue;
      int j = (i + d + n) % n;
      nh.insert({res[i], res[j]});
    }
  }
  if (nh != hv) {
    continue;
  } else {
    for (int x : res) cout << x + 1 << ' ';
    return 0;
  }
    }
  }
  cout << "-1\n";
}