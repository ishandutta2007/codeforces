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
  int k = 6;
  vector <int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  int n;
  cin >> n;
  vector <int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector <pair <int, int>> ev;
  for (int i = 0; i < n; ++i) {
    for (int j = k - 1; j >= 0; --j) {
      ev.push_back({b[i] - a[j], i});
    }
  }
  sort(ev.begin(), ev.end());
  vector <int> where(n);
  for (int i = 0; i < n; ++i) {
    where[i] = k - 1;
  }
  multiset <int> dif;
  for (int i = 0; i < n; ++i) {
    dif.insert(b[i] - a[where[i]]);
  }
  int ans = 2e9;
  auto relax = [&] () {
    ans = min(ans, *dif.rbegin() - *dif.begin());
  };
  relax();
  for (auto p : ev) {
    int i = p.second;
    dif.erase(dif.find(b[i] - a[where[i]]));
    --where[i];
    if (where[i] == -1) break;
    dif.insert(b[i] - a[where[i]]);
    relax();
  }
  cout << ans << '\n';
}