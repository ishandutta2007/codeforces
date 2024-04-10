#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll L = 0, R = 1e9;
  while (L != R) {
    ll M = (L + R + 1) / 2;
    if (3 * M > a || 2 * M > b || 2 * M > c)
      R = M - 1;
    else
      L = M;
  }
  a -= 3 * L;
  b -= 2 * L;
  c -= 2 * L;
  ll tmp = L * 7;
  ll ans = 0;
  vector <ll> todel = {0, 1, 2, 0, 2, 1, 0};
  for (int i = 0; i < 7; i++) {
    vector <ll> todel_new;
    for (int j = 0; j < 7; j++)
      todel_new.push_back(todel[(i + j) % 7]);
    ll _a = a, _b = b, _c = c;
    ll kek = 0;
    for (int x : todel_new) {
      if (x == 0) {
        if (!_a)
          break;
        _a--, kek++;
        continue;
      }
      if (x == 1) {
        if (!_b)
          break;
        _b--, kek++;
        continue;
      }
      if (x == 2) {
        if (!_c)
          break;
        _c--, kek++;
        continue;
      }
    }
    ans = max(ans, tmp + kek);
  }
  cout << ans;
  return 0;
}