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

const int Inf = 1e9 + 7;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  auto ask = [&] (int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  int bc = -1, val = Inf;
  for (int j = 0; j < m; ++j) {
    int cur = ask(0, j);
    if (cur < val) {
      val = cur;
      bc = j;
    }
  }
  int ans = Inf;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, ask(i, bc));
  }
  cout << "! " << ans << endl;
}