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
  // (a, c), (a, b)
  int n;
  cin >> n;
  map <int, int> cnt1;
  map <pair <int, int>, int> cnt2;
  ll ans = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    ans += cnt1[x];
    ++cnt1[x];
    if (x != y) {
      ans += cnt1[y];
      ++cnt1[y];
      ans -= cnt2[{x, y}];
      ++cnt2[{x, y}];
    }
  }
  cout << ans << '\n';
}