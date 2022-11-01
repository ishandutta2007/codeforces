#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m;
vector <ll> a;

ll solve(ll x) {
  vector <vector <ll>> arr(x);
  for (int i = 0; i < n; i++)
    arr[i % x].push_back(a[i]);
  ll sum = 0;
  for (int i = 0; i < x; i++)
    for (int j = 0; j < (int) arr[i].size(); j++)
      sum += max(0ll, arr[i][j] - j);
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll L = 1, R = n + 1;
  while (L != R) {
    ll M = (L + R) / 2;
    ll f = solve(M);
    if (f < m)
      L = M + 1;
    else
      R = M;
  }
  if (L == n + 1)
    L = -1;
  cout << L;
  return 0;
}