#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  vector <ld> f(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    f[i] = (ld)(r / p - (l - 1) / p) / (r - l + 1);
  }
  f.push_back(f[0]);
  ld sum = 0;
  for (int i = 0; i < n; i++)
    sum += f[i] + f[i + 1] - f[i] * f[i + 1];
  cout << fsp(15) << sum * 2000;
  return 0;
}