#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  int t;
  cin >> t;
  vector <ll> a;
  ll x = 1;
  ll s = 0;
  while (a.size() < 30) {
    s = x * (x + 1) / 2;
    a.push_back(s);
    x = 2 * x + 1;
  }
  while (t--) {
    ll n;
    cin >> n;
    int it = 0;
    while (it < 30 && n >= a[it]) {
      n -= a[it];
      it++;
    }
    cout << it << '\n';
  }
  return 0;
}