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
    int n, m, x;
    cin >> n >> m >> x;
    vector <int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    set <pair <int, int>> q;
    for (int i = 0; i < m; ++i) {
      q.insert({0, i});
    }
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
      auto p = *q.begin();
      q.erase(q.begin());
      p.first += h[i];
      ans[i] = p.second;
      q.insert(p);
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
    cout << '\n';
  }
}