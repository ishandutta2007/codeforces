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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  int sz = (n + 1) / 2;
  for (int i = 0; i < sz; ++i) cin >> a[i];
  int x;
  cin >> x;
  for (int i = sz; i < n; ++i) a[i] = x;
  if (x == 0) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if (sum > 0) {
      cout << n << '\n';
    } else {
      cout << "-1\n";
    }
    return 0;
  }
  vector <ll> pref(n + 1);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
  ll b = pref[sz + 1] - (ll)(sz + 1) * x;
  ll l = 0, r = n;
  // pref[i] < b + (st + i) * x
  // st * x > pref[i] - b - i * x
  for (int i = 0; i < n; ++i) {
    while (l <= r && !((ll)l * x > pref[i] - b - (ll)i * x)) ++l;
    while (l <= r && !((ll)r * x > pref[i] - b - (ll)i * x)) --r;
    if (i + 1 <= (n + 1 - (i + 1)) && l <= (n - i) && (n - i) <= r) {
      cout << (n + 1 - (i + 1)) << '\n';
      return 0;
    }
  } 
  cout << "-1\n";
  return 0;
}