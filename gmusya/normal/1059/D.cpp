#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

typedef vector <int> vi;

ld sqr(ld x) {
  return x * x;
}

ld solve(vi &x, vi &y, ld X) {
  int n = (int)x.size();
  ld L = 0, R = 50000000000000;
  for (int it = 0; it < 70; it++) {
    ld M = (L + R) / 2;
    bool flag = true;
    for (int i = 0; i < n; i++)
      if (sqr(x[i] - X) + sqr(y[i] - M) > sqr(M))
        flag = false;
    if (flag)
      R = M;
    else
      L = M;
  }
  return L;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi x(n), y(n);
  {
    int cntplus = 0, cntminus = 0;
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
      if (y[i] > 0)
        cntplus++;
      else
        cntminus--;
    }
    if (cntplus && cntminus) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
    y[i] = abs(y[i]);
  ld L = -1e7, R = 1e7;
  for (int it = 0; it < 80; it++) {
    ld K = (R - L) / 3;
    ld M1 = L + K;
    ld M2 = M1 + K;
    ld F1 = solve(x, y, M1);
    ld F2 = solve(x, y, M2);
    if (F1 < F2)
      R = M2;
    else
      L = M1;
  }
  cout << fsp(10) << solve(x, y, L);
  return 0;
}