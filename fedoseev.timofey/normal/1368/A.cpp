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
    int a, b, n;
    cin >> a >> b >> n;
    int sa = a, sb = b;
    int cnt = 0;
    int it = 0;
    while (a <= n && b <= n) {
      if (it % 2) b += a;
      else a += b;
      ++it;
    }
    int ans = it;
    a = sa, b = sb;
    it = 0;
    while (a <= n && b <= n) {
      if (it % 2) a += b;
      else b += a;
      ++it;
    }
    ans = min(ans, it);
    cout << ans << '\n';
  }
}