#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  map <pair <pair <ll, ll>, ll>, bool> ans;
  while (t--) {
    ll p, q, b;
    cin >> p >> q >> b;
    ll oldp = p, oldq = q, oldb = b;
    if (ans.find({{p, q}, b}) != ans.end()) {
      if (ans[{{p, q}, b}])
        cout << "Finite\n";
      else
        cout << "Infinite\n";
      continue;
    }
    if (!p) {
      ans[{{p, q}, b}] = true;
      cout << "Finite\n";
      continue;
    }
    ll g = __gcd(p, q);
    p /= g, q /= g;
    g = 0;
    while (g != 1) {
      g = __gcd(q, b);
      if (g == 1) break;
      while (q % g == 0)
        q /= g;
    }
    if (q == 1) {
      cout << "Finite\n";
      ans[{{oldp, oldq}, oldb}] = true;
    } else {
      cout << "Infinite\n";
      ans[{{oldp, oldq}, oldb}] = false;
    }
  }
  return 0;
}