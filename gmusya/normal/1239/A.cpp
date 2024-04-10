#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  vector <int> f(200'000);
  f[0] = f[1] = 1;
  for (int i = 2; i <= 199'999; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] >= MOD)
      f[i] -= MOD;
  }
  int n, m;
  cin >> n >> m;
  cout << 2 * 1ll * (f[n] + f[m] - 1) % MOD;
  return 0;
}