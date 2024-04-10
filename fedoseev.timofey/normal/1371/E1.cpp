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
  for (int x = 1; x <= 2001; ++x) {
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      int need = max(0, a[i] - x);
      int cnt = n - need - i;
      if (cnt < 0 || cnt % p == 0) {
        bad = true;
      }
    }
    if (!bad) ans.push_back(x);
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
}