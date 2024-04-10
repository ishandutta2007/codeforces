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
  int n;
  cin >> n;
  vector <int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i += 2) {
    ll bal = 0;
    ll min_bal = 0;
    for (int j = i + 1; j < n; ++j) {
      if (i % 2 != j % 2) {
        ll needa = max(1LL, -min_bal);
        ll needb = bal + needa;
        if (needa <= c[i] && needb <= c[j]) {
          //cout << i << ' ' << j << ' ' << needa << ' ' << needb << endl;
          ans += min(c[i] - needa + 1, c[j] - needb + 1);
        }
      } 
      if (j % 2 == i % 2) {
        bal += c[j];
      } else {
        bal -= c[j];
      }
      min_bal = min(min_bal, bal);
    }
  }
  cout << ans << '\n';
}