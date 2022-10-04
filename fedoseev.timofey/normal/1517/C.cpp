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
  int n;
  cin >> n;
  vector <int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  vector <vector <int>> ans(n, vector <int> (n));
  for (int i = 0; i < n; ++i) {
    ans[i][i] = p[i];
  }
  vector <int> cur = p; 
  for (int t = 1; t < n; ++t) {
    int uk = 0;
    vector <int> ncur;
    for (int i = 0; i < n - t; ++i) {
      while (cur[uk] <= t) ++uk; 
      ans[i + t][i] = cur[uk];
      ncur.push_back(cur[uk]);
      ++uk;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}