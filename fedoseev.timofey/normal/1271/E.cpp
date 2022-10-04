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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ll n, k;
  cin >> n >> k;
  auto get = [&] (ll x) {
    int st = 0;
    ll cnt = 0;
    while (x <= n) {
      ll mx = (1LL << st) - 1;
      if (x + mx > n) {
        cnt += n - x + 1;
      } else {
        cnt += (1LL << st);
      }
      x *= 2;
      ++st;
    }
    return cnt;
  };
  ll ans = 0;
  ll cur = 0;
  for (int i = 60; i >= 1; --i) {
    ll nw = cur + (1ll << i);
    ll hv = 0;
    if (nw <= n) hv += get(nw);
    if (nw + 1 <= n) hv += get(nw + 1);
    if (nw <= n && hv >= k) cur = nw;
  }
  ans = max(ans, cur);
  cur = 1;
  for (int i = 60; i >= 1; --i) {
    ll nw = cur + (1ll << i);
    if (nw <= n && get(nw) >= k) cur = nw;
  }
  ans = max(ans, cur);
  cout << ans << '\n';
}