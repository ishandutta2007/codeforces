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
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  vector<int> sz(n);
  for (int i = 0; i < n; ++i) p[i] = i, sz[i] = 1;
  function<int(int)> get = [&](int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
  };
  auto join = [&](int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
      p[a] = b;
      sz[b] += sz[a];
    }
  };
  for (int i = 0; i < d; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    join(x, y);
    vector<int> szs;
    for (int i = 0; i < n; ++i) {
      if (get(i) == i) {
        szs.push_back(sz[i]);
      }
    }
    sort(szs.rbegin(), szs.rend());
    int have = i + 1;
    int need = 0;
    int res = 0;
    for (auto x : szs) {
      need += x - 1;
      res = max(res, x - 1);
    }
    int delta = have - need;
    int extra = delta;
    for (int i = 1; i < min(1 + delta, (int)szs.size()); ++i) {
      res += szs[i];
      --extra;
    }
    res += extra;
    res = min(res, n - 1);
    cout << res << '\n';
  }
}