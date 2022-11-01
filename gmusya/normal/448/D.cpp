#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  ll L = 1, R = n * m;
  while (L != R) {
    ll M = (L + R) / 2;
    ll lt = 0;
    for (int i = 1; i <= n; i++)
      lt += min(m, M / i);
    if (lt < k)
      L = M + 1;
    else
      R = M;
  }
  cout << L;
  return 0;
}