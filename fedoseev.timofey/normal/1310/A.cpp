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
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
#include <functional>
          
using namespace std;
        
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n), t(n);
  set <int> have;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector <int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&] (int i, int j) {
    return a[i] < a[j];
  });
  multiset <int> who;
  ll sm = 0;
  ll ans = 0;
  for (int j = 0; j < n; ++j) {
    int i = id[j];
    int lst = (j == 0 ? -1 : a[id[j - 1]]);
    if (lst < a[i]) {
      while (!who.empty() && lst < a[i]) {
        sm -= *who.rbegin();
        who.erase(--who.end());
        ++lst;
        ans += sm;
      }
    }
    who.insert(t[i]);
    sm += t[i];
  }
  while (!who.empty()) {
    sm -= *who.rbegin();
    who.erase(--who.end());
    ans += sm;
  }
  cout << ans << '\n';
}