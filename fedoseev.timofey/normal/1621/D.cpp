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
    int n;
    cin >> n;
    ll sum = 0;
    vector<vector<ll>> need(8, vector<ll>(n));
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < 2 * n; ++j) {
        int c;
        cin >> c;
        if (i < n && j < n) {
        } else if (i >= n && j >= n) {
          sum += c;
        } else if (i < n) {
          need[0][max(n - i - 1, j - n)] += c;
          need[1][max(n - i - 1, 2 * n - j - 1)] += c;
          need[2][max(i, 2 * n - j - 1)] += c;
          need[3][max(i, j - n)] += c;
        } else {
          need[4][max(n - j - 1, i - n)] += c;
          need[5][max(n - j - 1, 2 * n - i - 1)] += c;
          need[6][max(j, 2 * n - i - 1)] += c;
          need[7][max(j, i - n)] += c;
        }
      }
    }
    ll best = (ll)1e18;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 1; ++j) {
        best = min(best, need[i][j]);
      }
    }
    cout << sum + best << '\n';
  }
}