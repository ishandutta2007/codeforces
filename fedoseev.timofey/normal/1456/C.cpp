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
  int n, k;
  cin >> n >> k;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  vector <ll> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }
  vector <ll> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + pref[i];
  }
  if (k == 0) {
    cout << sum[n] << '\n';
    return 0;
  }
  multiset <int> coef;
  for (int i = 0; i <= k; ++i) coef.insert(0);
  ll ans = sum[n];
  ll cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    int cc = *coef.begin();
    coef.erase(coef.begin());
    cur += cc * a[i];
    coef.insert(cc + 1);
    int mx = *coef.rbegin();
    ans = max(ans, cur + sum[i] + (ll)pref[i] * mx);
  }
  coef.clear();
  cout << ans << '\n';
}