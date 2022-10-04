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
    int cr = 0, cc = 0;
    for (int i = 0; i < n; ++i) {
      bool ok = true;
      for (int j = 0; j < m; ++j) {
        ok &= (a[i][j] == 0);
      }
      if (ok) ++cr;
    }
    for (int j = 0; j < m; ++j) {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        ok &= (a[i][j] == 0);
      }
      if (ok) ++cc;
    }
    if (min(cr, cc) % 2 == 0) {
      cout << "Vivek\n";
    } else {
      cout << "Ashish\n";
    }
  }
}