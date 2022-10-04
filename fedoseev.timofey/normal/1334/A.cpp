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
    int n;
    cin >> n;
    vector <int> p(n), c(n);
    for (int i = 0; i < n; ++i) cin >> p[i] >> c[i];
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (p[i] < c[i]) bad = true;
    }
    for (int i = 1; i < n; ++i) {
      if (p[i] < p[i - 1]) bad = true;
      if (c[i] < c[i - 1]) bad = true;
      if (p[i] - p[i - 1] < c[i] - c[i - 1]) {
        bad = true;
      }
    }
    if (!bad) cout << "YES\n";
    else cout << "NO\n";
  }
}