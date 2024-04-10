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

struct triple {
  int i, j; ll x;
};
 
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
    vector <ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n) {
      cout << "-1\n";
      continue;
    }
    vector <triple> ans;
    for (int i = 1; i < n; ++i) {
      int id = i + 1;
      int need = (id - (a[i] % id)) % id;
      assert(a[0] >= need);
      ans.push_back({1, id, need});
      a[0] -= need;
      a[i] += need;
      assert(a[i] % id == 0);
      ans.push_back({id, 1, a[i] / id});
      a[0] += a[i];
      a[i] = 0;
    } 
    for (int i = 1; i < n; ++i) {
      ans.push_back({1, i + 1, sum / n});
      a[0] -= sum / n;
      a[i] += sum / n;
    }
    cout << ans.size() << '\n';
    for (auto op : ans) {
      cout << op.i << ' ' << op.j << ' ' << op.x << '\n';
    }
  }
}