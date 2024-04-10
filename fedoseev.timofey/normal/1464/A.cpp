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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> par(n);
    for (int i = 0; i < n; ++i) par[i] = i;
    function <int(int)> get = [&] (int a) {
      return (a == par[a] ? a : par[a] = get(par[a]));
    };
    auto join = [&] (int a, int b) {
      a = get(a);
      b = get(b);
      par[a] = b;
    };
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if (x != y) {
        ++ans;
        x = get(x);
        y = get(y);
        if (x == y) ++ans;
        join(x, y);
      } 
    }

    cout << ans << '\n';
  }
}