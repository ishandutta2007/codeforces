#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  int suma = 0;
  for (int i = 1; i <= n; i++)
    suma += a[i];
  vvi dp(n + 1, vi(suma + 1, 1e9));
  dp[0][0] = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum += b[i];
  for (int i = 1; i <= n; i++) {
    vvi newdp(n + 1, vi(suma + 1, 1e9));
    for (int cnt = 0; cnt < i; cnt++)
      for (int w = 0; w + a[i] <= suma; w++)
        newdp[cnt + 1][w + a[i]] = min(newdp[cnt + 1][w + a[i]], dp[cnt][w]);
    for (int cnt = 0; cnt < i; cnt++)
      for (int w = 0; w <= suma; w++)
        newdp[cnt][w] = min(newdp[cnt][w], dp[cnt][w] + b[i]);
    swap(dp, newdp);
  }
  for (int cnt = 1; cnt <= n; cnt++) {
    ld ans = -1e9;
    for (int w = 0; w <= suma; w++)
      ans = max(ans, min((ld)w, (ld)sum - (ld)dp[cnt][w] / 2));
    cout << fsp(15) << ans << ' ';
  }
  return 0;
}