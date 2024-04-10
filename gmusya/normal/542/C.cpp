#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  vector <bool> flag(n);
  vi c;
  for (int i = 0; i < n; i++) {
    int s = i;
    flag[i] = true;
    for (int it = 1; it <= 200; it++) {
      s = f[s];
      if (s == i) {
        c.push_back(it);
        flag[i] = false;
        break;
      }
    }
  }
  ll val = 0;
  for (int i = 0; i < n; i++) {
    int s = i;
    if (!flag[i])
      continue;
    for (int it = 1; it <= 200; it++) {
      s = f[s];
      if (!flag[s]) {
        val = max(val, (ll)it);
        break;
      }
    }
  }
  ll lcm = 1;
  for (ll x : c) {
    ll g = __gcd(x, lcm);
    lcm *= x / g;
  }
  for (int j = 1; j <= 1000; j++)
    if (j % lcm == 0 && j >= val) {
      cout << j;
      return 0;
    }
  cout << lcm;
  return 0;
}