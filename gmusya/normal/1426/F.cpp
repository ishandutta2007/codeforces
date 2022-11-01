#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <char> s(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  vector <int> a(n + 1), b(n + 1), c(n + 1), q(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1], q[i] = q[i - 1];
    if (s[i] == 'a')
      a[i]++;
    if (s[i] == 'b')
      b[i]++;
    if (s[i] == 'c')
      c[i]++;
    if (s[i] == '?')
      q[i]++;
  }
  int k = q[n];
  vector <ll> pow3(k + 1);
  pow3[0] = 1;
  for (int i = 1; i <= k; i++)
    pow3[i] = pow3[i - 1] * 3 % MOD;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'a' || s[i] == 'c')
      continue;
    if (s[i] == 'b') {
      ll cnta = a[i - 1];
      ll cntl = q[i - 1];
      ll cntc = c[n] - c[i];
      ll cntr = q[n] - q[i];
      ans = (ans + cnta * cntc % MOD * pow3[k] % MOD) % MOD;
      if (k > 0)
        ans = (ans + cntl * cntc % MOD * pow3[k - 1] % MOD) % MOD;
      if (k > 0)
        ans = (ans + cnta * cntr % MOD * pow3[k - 1] % MOD) % MOD;
      if (k > 1)
        ans = (ans + cntl * cntr % MOD * pow3[k - 2] % MOD) % MOD;
    } else {
      ll cnta = a[i - 1];
      ll cntl = q[i - 1];
      ll cntc = c[n] - c[i];
      ll cntr = q[n] - q[i];
      if (k > 0)
        ans = (ans + cnta * cntc % MOD * pow3[k - 1] % MOD) % MOD;
      if (k > 1)
        ans = (ans + cntl * cntc % MOD * pow3[k - 2] % MOD) % MOD;
      if (k > 1)
        ans = (ans + cnta * cntr % MOD * pow3[k - 2] % MOD) % MOD;
      if (k > 2)
        ans = (ans + cntl * cntr % MOD * pow3[k - 3] % MOD) % MOD;
    }
  }
  cout << ans;
  return 0;
}