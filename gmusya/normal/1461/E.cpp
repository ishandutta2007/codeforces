#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ll k, l, r;
  cin >> k >> l >> r;
  r -= l;
  k -= l;
  ll t, x, y;
  cin >> t >> x >> y;
  if (k + y <= r)
    k += y;
  if (y == x) {
    if (k < x)
      cout << "No\n";
    else
      cout << "Yes\n";
    return 0;
  }
  if (y < x) {
    k -= x;
    ll val = k / (x - y);
    if (val + 1 < t)
      cout << "No\n";
    else
      cout << "Yes\n";
    return 0;
  }
  set <ll> used;
  while (t > 0) {
    if (used.find(k % x) != used.end() && k >= x) {
      cout << "Yes\n";
      return 0;
    }
    used.insert(k % x);
    ll oper = k / x;
    if (oper == 0) {
      cout << "No\n";
      return 0;
    }
    t -= oper;
    k -= oper * x;
    ll add = min(oper, (r - k) / y);
    k += add * y;
  }
  cout << "Yes\n";
  return 0;
}