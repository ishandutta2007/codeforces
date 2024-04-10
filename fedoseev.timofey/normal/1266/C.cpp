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
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "0\n";
  } else if (n == 1) {
    for (int i = 2; i <= m + 1; ++i) {
      cout << i << ' ';
    }
  } else if (m == 1) {
    for (int i = 2; i <= n + 1; ++i) {
      cout << i << '\n';
    }
  } else {
    vector <vector <int>> ans(n, vector <int> (m, 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[i][j] *= (i + 1);
      }
    }
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        ans[i][j] *= (n + j + 1);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}