#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

struct vec {
  ll x, y;
  void read() {
    cin >> x >> y;
  }
  void write() {
    cout << "(" << x << "," << y << ")" << endl;
  }
  ll operator*(vec p) {
    return x * p.x + y * p.y;
  }
  ll operator%(vec p) {
    return x * p.y - y * p.x;
  }
  int type() {
    if (x == 0 && y > 0)
      return 0;
    if (x > 0)
      return 1;
    if (x == 0 && y < 0)
      return 2;
    if (x < 0)
      return 3;
  }
  ll mod() {
    return x * x + y * y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <vec, int>> p(n);
  for (int i = 0; i < n; i++) {
    p[i].fi.read();
    p[i].se = i;
  }
  sort(p.begin(), p.end(), [&](pair <vec, int> c, pair <vec, int> d){
    vec a = c.fi, b = d.fi;
    if (a.type() != b.type())
      return a.type() < b.type();
    return a % b < 0;
  });
  p.push_back(p[0]);
  pair <ld, pii> ans = {abs(atan2(p[0].fi % p[1].fi, p[0].fi * p[1].fi)), {p[0].se, p[1].se}};
  for (int i = 0; i < n; i++) {
    ld ang = abs(atan2(p[i].fi % p[i + 1].fi, p[i].fi * p[i + 1].fi));
    ans = min(ans, {ang, {p[i].se, p[i + 1].se}});
  }
  cout << ans.se.fi + 1 << ' ' << ans.se.se + 1;
  return 0;
}