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
  int m, n;
  cin >> m >> n;
  vector <int> a(m), b(n);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < n; ++j) {
    cin >> b[j];
  }
  vector <vector <int>> s(m);
  ll ans = 0;
  vector <pair <int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    s[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> s[i][j];
      --s[i][j];
      ans += a[i] + b[s[i][j]];
      edges.push_back({i, s[i][j]});
    }
  }
  sort(edges.begin(), edges.end(), [&] (pair <int, int> f, pair <int, int> s) {
    return a[f.first] + b[f.second] > a[s.first] + b[s.second];
  });
  vector <int> p(n + m);
  iota(p.begin(), p.end(), 0);
  function <int(int)> get = [&] (int a) {
    return a == p[a] ? a : p[a] = get(p[a]);
  };
  auto join = [&] (int x, int y) {
    x = get(x);
    y = get(y);
    p[x] = y;
  };
  for (auto e : edges) {
    if (get(e.first) != get(m + e.second)) {
      ans -= a[e.first] + b[e.second]; 
      join(e.first, m + e.second);
    }
  }
  cout << ans << '\n';
}