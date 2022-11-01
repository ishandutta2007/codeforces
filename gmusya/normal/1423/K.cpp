#include <iostream>
#include <vector>
#include <math.h>

typedef long double ld;
typedef long long ll;

using namespace std;

const ld eps = 1e-3;
const int MAXN = 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <bool> is_prime(MAXN + 1, true);
  is_prime[1] = false;
  for (ll i = 2; i <= MAXN; i++)
    if (is_prime[i])
      for (ll j = i * i; j <= MAXN; j += i)
        is_prime[j] = false;
  vector <ll> pre(MAXN + 1);
  for (int i = 1; i <= MAXN; i++)
    pre[i] = pre[i - 1] + is_prime[i];
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int val = sqrt(n + eps);
    cout << pre[n] - pre[val] + 1 << '\n';
  }
  return 0;
}