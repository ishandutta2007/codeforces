#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector <ll> vl;
typedef vector <vl> vvl;

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vvl arr(k + 1, vl(n));
  for (int i = 0; i < n; i++)
    arr[0][i] = 1;
  for (int it = 1; it <= k; it++) {
    for (int i = 0; i + 1 < n; i++)
      arr[it][i] = arr[it - 1][i + 1];
    for (int i = 1; i < n; i++) {
      arr[it][i] += arr[it - 1][i - 1];
      if (arr[it][i] >= MOD)
        arr[it][i] -= MOD;
    }
  }
  vl sum(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      sum[i] = (sum[i] + arr[j][i] * arr[k - j][i]) % MOD;
  ll res = 0;
  vl a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    res = (res + a[i] * sum[i]) % MOD;
  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    res -= a[i] * sum[i];
    a[i] = x;
    res += a[i] * sum[i];
    res %= MOD;
    if (res < 0)
      res += MOD;
    cout << res << '\n';
  }
  return 0;
}