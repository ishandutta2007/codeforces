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
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, p;
  cin >> n >> p;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());
  vector <int> ans;
  /*for (int x = 1; x <= 2001; ++x) {
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      int cnt = n - i - max(0, a[i] - x);
      if (cnt < 0 || cnt % p == 0) {
        bad = true;
      }
    }
    if (!bad) ans.push_back(x);
  }*/
  multiset <int> mn;
  vector <int> cnt(p);
  for (int i = 0; i < n; ++i) {
    int cur = n - i - a[i]; 
    ++cnt[((cur % p) + p) % p];
    mn.insert(-cur);
  }
  set <int> good;
  for (int i = 0; i < p; ++i) {
    if (cnt[i] == 0) good.insert((-i + p) % p);
  }
  for (int i = n - 1; i > 0; --i) {
    if ((n - i) % p == 0) break;
    int cur = n - i - a[i]; 
    int cur_rem = ((cur % p) + p) % p;
    --cnt[cur_rem];
    if (cnt[cur_rem] == 0) good.insert((-cur_rem + p) % p);
    mn.erase(mn.find(-cur));
    if (good.empty()) continue;
    int low = a[i];
    if (!mn.empty()) low = max(low, *mn.rbegin());
    for (int x = low; x < a[i - 1]; ++x) {
      cur_rem = x % p;
      auto it = good.lower_bound(cur_rem);
      if (it != good.end()) {
        x += (*it - cur_rem);
      } else {
        x += (*good.begin() - cur_rem + p);
      }
      if (x < a[i - 1]) {
        ans.push_back(x);
      } else {
        break;
      }
    } 
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
}