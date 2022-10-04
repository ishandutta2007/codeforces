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
  vector <int> a(n), c(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
    ans += c[i];
  }
  vector <int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&] (int i, int j){
    return a[i] < a[j];
  });
  multiset <ll> have;
  have.insert(c[ord[0]] + a[ord[0]]);
  for (int i = 1; i < n; ++i) {
    if (*have.rbegin() >= a[ord[i]]) {
    } else {
      ans += a[ord[i]] - *have.rbegin();
      have.erase(--have.end());
    } 
    have.insert(c[ord[i]] + a[ord[i]]);
  }
  cout << ans << '\n';
}