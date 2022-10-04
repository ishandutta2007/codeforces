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
#include <chrono>

using namespace std;

typedef long long ll;

vector <ll> get(ll x) {
  vector <ll> res;
  for (ll d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      res.push_back(d);
      while (x % d == 0) {
        x /= d;
      }
    }
  }
  if (x > 1) res.push_back(x);
  return res;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  auto st = clock();
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = n;
  set <ll> used;
  while ((double)(clock() - st) / CLOCKS_PER_SEC < 2) {
    int id = rnd() % n;
    for (int d = -1; d <= 1; ++d) {
      ll num = a[id] + d;
      if (num <= 0) continue;
      for (auto x : get(num)) {
        if (used.count(x)) continue;
        ll need = 0;
        for (int i = 0; i < n; ++i) {
          ll rem = a[i] % x;
          if (rem == a[i]) {
            need += x - rem;
          } else {
            need += min(rem, x - rem);
          }
          if (need > ans) break;
        }
        if (need < ans) ans = need;
      } 
    }
  }
  cout << ans << '\n';
}