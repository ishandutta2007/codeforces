#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll f(ll x) {
  ll cost = 0;
  ll num = 1;
  ll p10 = 10;
  while (p10 <= x) {
    cost += (p10 - (p10 / 10)) * num;
    p10 *= 10;
    num++;
  }
  p10 /= 10;
  cost += (x - p10 + 1) * num;
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll w, m, k;
  cin >> w >> m >> k;
  w /= k;
  ll L = 0, R = 1e16;
  while (L != R) {
    ll M = (L + R + 1) / 2;
    ll F = f(m + M - 1) - f(m - 1);
    if (F > w)
      R = M - 1;
    else
      L = M;
  }
  cout << L;
  return 0;
}