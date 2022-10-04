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
  const int K = 100;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> cnt(2, vector <int> (K + 1));
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        ++cnt[i][x];
      }
    }
    int low = -1, high = (int)1e9;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      vector <vector <int>> cur = cnt;
      cur[0][100] += mid;
      cur[1][0] += mid;
      int all = n + mid;
      int cnt = all - all / 4;
      auto get = [&] (int id) {
        ll score = 0;
        int rem = cnt;
        for (int i = 100; i >= 0; --i) {
          int tk = min(rem, cur[id][i]);
          rem -= tk;
          score += (ll)tk * i;
        }
        return score;
      };
      if (get(0) >= get(1)) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cout << high << '\n';
  }
}