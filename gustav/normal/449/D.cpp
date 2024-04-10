#include <cstdio>
#include <cstring>

typedef long long llint;
const int mod = 1000000007;
const int all = (1 << 20) - 1;

#define MAXN 1000005

int mult(int a, int b) { return (llint)a * b % mod; }
int add(int a, int b) { return (llint)(a + b) % mod; }

int power(int n, int pow) {
  int ret = 1;
  for (int i = 0; (1LL << i) <= pow; ++i) {
    if (((pow >> i) & 1) == 1)
      ret = mult(ret, n);
    n = mult(n, n);
  }
  return ret;
}

int N, a;

int cnt[all + 1];

void spread(int l, int r) {
  if (l + 1 == r) return;

  int m = (l + r) / 2;

  for (int i = m; i < r; ++i) 
    cnt[l + i - m] += cnt[i];

  spread(l, m);
  spread(m, r);
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%d", &a);
    cnt[a] += 1;
  }

  spread(0, all + 1);

  int sol = 0;

  for (int i = 1; i <= all; ++i) {
    int parity = __builtin_popcount(i) % 2;

    if (parity == 1) 
      sol = add(sol, power(2, cnt[i]));
    else 
      sol = add(sol, mod - power(2, cnt[i]));
  }

  sol = add(power(2, N), mod - sol);

  printf("%d\n", sol);

  return 0;
}