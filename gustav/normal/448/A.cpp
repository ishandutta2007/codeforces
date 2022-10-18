#include <cstdio>

int solve(int div) {
  int C = 0;
  for (int i = 0; i < 3; ++i) {
    int x; scanf("%d", &x); C += x;
  }
  return (C + div - 1) / div;
}

int main(void)
{
  int a = solve(5);
  int b = solve(10);
  int N; scanf("%d", &N);

  puts(a + b <= N ? "YES" : "NO");

  return 0;
}