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
  int n, q;
  cin >> n >> q;
  vector <int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  set <int> c;
  multiset <int> d;
  auto add = [&] (int x) {
    c.insert(x);
    auto it = c.lower_bound(x);
    if (next(it) != c.end()) {
      d.insert(*next(it) - *it);
    }
    if (it != c.begin()) {
      d.insert(*it - *prev(it));
    }
    if (next(it) != c.end() && it != c.begin()) {
      d.erase(d.find(*next(it) - *prev(it)));
    }
  };
  auto del = [&] (int x) {
    auto it = c.lower_bound(x);
    if (next(it) != c.end()) {
      d.erase(d.find(*next(it) - *it));
    }
    if (it != c.begin()) {
      d.erase(d.find(*it - *prev(it)));
    }
    if (next(it) != c.end() && it != c.begin()) {
      d.insert(*next(it) - *prev(it));
    }
    c.erase(it);
  };
  for (int i = 0; i < n; ++i) {
    add(p[i]);
  }
  auto get = [&] () {
    int ans = 0;
    if (!c.empty()) ans += *c.rbegin() - *c.begin();
    if (!d.empty()) ans -= *d.rbegin();
    return ans;
  };
  cout << get() << '\n';
  for (int i = 0; i < q; ++i) {
    int t, x;
    cin >> t >> x;
    if (t == 0) del(x);
    else add(x);
    cout << get() << '\n';
  }
}