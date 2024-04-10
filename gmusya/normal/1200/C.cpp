#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 i128;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll g = __gcd(n, m);
  int q;
  cin >> q;
  while (q--) {
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sy--, ey--;
    ll comp1 = sy / ((sx == 1 ? n : m) / g);
    ll comp2 = ey / ((ex == 1 ? n : m) / g);
    if (comp1 == comp2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}