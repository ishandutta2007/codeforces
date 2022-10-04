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
    vector <int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vector <int> deg(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      ++deg[u];
      ++deg[v];
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += w[i];
    multiset <pair <int, int>> have;
    for (int i = 0; i < n; ++i) {
      have.insert({w[i], deg[i] - 1});
    }
    cout << sum << ' ';
    for (int tt = 2; tt <= n - 1; ++tt) {
      while (true) {
        if (have.empty()) break;
        auto p = *have.rbegin();
        have.erase(--have.end());
        if (p.second == 0) continue;
        sum += p.first;
        --p.second;
        have.insert(p);
        break;
      }
      cout << sum << ' ';
    } 
    cout << '\n';
  }
}