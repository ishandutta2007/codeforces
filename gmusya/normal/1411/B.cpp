#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool check(ll x) {
  vector <ll> d;
  ll c = x;
  while (c) {
    if (c % 10)
      d.push_back(c % 10);
    c /= 10;
  }
  for (auto &now : d)
    if (x % now)
      return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    while (!check(n))
      n++;
    cout << n << '\n';
  }
  return 0;
}