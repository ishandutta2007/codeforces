#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;

bool check(ll x, vector <ll> a) {
  int first = 0;
  for (int it = 0; it < m; it++) {
    ll curt = x - first;
    if (curt <= 0)
      break;
    if (!a[first]) {
      first++;
      it--;
      continue;
    }
    while (curt > 0 && first < n) {
      if (curt <= a[first]) {
        a[first] -= curt;
        break;
      }
      curt -= a[first] + 1;
      a[first] = 0;
      first++;
    }
  }
  for (int i = 0; i < n; i++)
    if (a[i])
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll L = 0, R = 2e18;
  while (L != R) {
    ll M = L + (R - L) / 2;
    if (!check(M, a))
      L = M + 1;
    else
      R = M;
  }
  cout << L + 1;
  return 0;
}