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
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    vector <vector <int>> b(n, vector <int> (m, 4));
    for (int i = 0; i < n; ++i) {
      b[i][0] = 3;
      b[i][m - 1] = 3;
    }
    for (int j = 0; j < m; ++j) {
      b[0][j] = 3;
      b[n - 1][j] = 3;
    }
    b[0][0] = 2;
    b[0][m - 1] = 2;
    b[n - 1][0] = 2;
    b[n - 1][m - 1] = 2;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (b[i][j] < a[i][j]) {
          bad = true;
        }
      }
    }
    if (bad) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << b[i][j] << ' ';
        }
        cout << '\n';
      }
    }
  }
}