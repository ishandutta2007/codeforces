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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    ll sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) sa += a[i];
    for (int i = 0; i < n; ++i) sb += b[i];
    if (sb < sa) {
      cout << "NO\n";
      continue;
    }
    vector <int> c;
    for (int i = 0; i < n; ++i) {
      c.push_back(a[i] - b[(i - 1 + n) % n]);
    }
    for (int i = 0; i < n; ++i) {
      c.push_back(a[i] - b[(i - 1 + n) % n]);
    }
    bool bad = false;
    ll mn = 0, sm = 0;
    for (int i = 0; i < (int)c.size(); ++i) {
      sm += c[i];
      mn = min(mn, sm);
      if (sm - mn - b[i % n] > 0) bad = true;
    }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
  }
}