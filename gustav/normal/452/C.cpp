#include <cstdio>
#include <algorithm>

using namespace std;
typedef long double ldouble;

ldouble choose(int n, int k) {
  if (n < k) return 0.0;
  ldouble ret = 1.0;
  for (int i = 1; i <= k; ++i)
    ret *= (ldouble)(n - i + 1) / i;
  return ret;
}

int main(void)
{
  int n, m;
  scanf("%d%d", &n, &m);

  ldouble tot = choose(n * m, n);

  ldouble sol = 0.0;
  for (int k = 1; k <= min(n, m); ++k) {
    ldouble add = (ldouble)(k * k) / (ldouble)(n * n);
    add *= choose(n * m - m, n - k) / tot * choose(m, k);
    sol += add * n;
  }

  printf("%.8lf\n", (double)sol);

  return 0;
}