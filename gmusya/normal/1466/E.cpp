#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> x(n);
    vector <int> cnt(60);
    vector <ll> pow2(60);
    pow2[0] = 1;
    for (int i = 1; i <= 59; i++)
      pow2[i] = pow2[i - 1] * 2;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      for (int j = 0; j < 60; j++)
        if (x[i] & pow2[j])
          cnt[j]++;
    }
    ll res = 0;
    for (int j = 0; j < n; j++) {
      ll suma = 0, sumb = 0;
      for (int p = 0; p < 60; p++) { // suma
        if ((x[j] & pow2[p]) == 0)
          continue;
        suma = (suma + pow2[p] % MOD * cnt[p] % MOD) % MOD;
      }
      for (int p = 0; p < 60; p++) { // sumb
        if ((x[j] & pow2[p]) != 0)
          sumb = (sumb + pow2[p] % MOD * n % MOD) % MOD;
        else
          sumb = (sumb + pow2[p] % MOD * cnt[p] % MOD) % MOD;
      }
      res = (res + suma * sumb) % MOD;
    }
    cout << res << '\n';
  }
  return 0;
}