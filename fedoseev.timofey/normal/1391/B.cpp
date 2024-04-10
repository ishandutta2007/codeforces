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
    int n, m;
    cin >> n >> m;
    vector <vector <char>> c(n, vector <char> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> c[i][j];
      }
    }
    int ans = 0;
    for (int j = 0; j + 1 < m; ++j) {
      if (c[n - 1][j] != 'R') ++ans;
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (c[i][m - 1] != 'D') ++ans;
    }
    cout << ans << '\n';
  }
}