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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = 0;
  for (int i = 0; i <= 100000; ++i) {
    if (i > min(a, d)) continue;
    int cur = i * e;
    int j = min(b, min(c, d - i));
    cur += j * f;
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}