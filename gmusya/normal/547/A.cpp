#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  ll x1, y1;
  ll g = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}

int main() {
  ll m;
  cin >> m;
  ll h1, a1;
  cin >> h1 >> a1;
  ll x1, y1;
  cin >> x1 >> y1;
  ll h2, a2;
  cin >> h2 >> a2;
  ll x2, y2;
  cin >> x2 >> y2;
  vector <vector <ll>> A(m), B(m);
  for (int it = 0; it < 2'000'000; it++) {
    h1 = (x1 * h1 + y1) % m;
    h2 = (x2 * h2 + y2) % m;
    if (h1 == a1 && h2 == a2) {
      cout << it + 1;
      return 0;
    }
    A[h1].push_back(it);
    B[h2].push_back(it);
  }
  if (A[a1].size() < 2 || B[a2].size() < 2) {
    cout << -1;
    return 0;
  }
  ll t1 = A[a1][0], t2 = A[a1][1];
  ll s1 = B[a2][0], s2 = B[a2][1];
  if (t1 > s1) {
    swap(t1, s1);
    swap(t2, s2);
  }
  ll val1 = t2 - t1;
  ll val2 = s1 - s2;
  ll val3 = s1 - t1;
  ll k, l;
  ll g = gcd(val1, val2, k, m);
  if (val3 % g) {
    cout << -1;
    return 0;
  }
  k *= val3 / g;
  k %= abs(val2);
  if (k < 0)
    k += abs(val2);
  cout << t1 + k * (t2 - t1) + 1;
  return 0;
}