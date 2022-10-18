#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;

void solve() {
  llint n, k, d1, d2;
  cin >> n >> k >> d1 >> d2;

  if (n % 3 != 0) {
    puts("no");
    return;
  }

  llint p = n / 3;

  vector< llint > x(3, 0);

  for (int i = -1; i <= +1; i += 2) {
    for (int j = -1; j <= +1; j += 2) {
      x[0] = 0;
      x[1] = i * d1;
      x[2] = i * d1 + j * d2;

      llint m = 0, M = 0;
      for (auto X : x) m = min(m, X);

      llint sum = 0;
      for (auto &X : x) { X -= m; sum += X; }

      if (sum > k) continue;
      if ((k - sum) % 3 != 0) continue;

      llint a = (k - sum) / 3;
      for (auto &X : x) { X += a; M = max(M, X); }

      if (M > p) continue;

      puts("yes");
      return;
    }
  }

  puts("no");
}

int main(void)
{
  int t;
  cin >> t;

  while (t--)
    solve();


  return 0;
}