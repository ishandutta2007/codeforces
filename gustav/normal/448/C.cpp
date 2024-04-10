#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define MAXN 5005

int N;
int a[MAXN];

int solve(int l, int r, int lo = 0) {
  if (l > r) return 0;

  int m = l;
  for (int i = l; i <= r; ++i)
    if (a[i] < a[m]) m = i;

  int ret = a[m] - lo;
  ret += solve(l, m - 1, a[m]);
  ret += solve(m + 1, r, a[m]);

  if (ret > r - l + 1)
    return r - l + 1;

  return ret;
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  printf("%d\n", solve(0, N - 1));
  
  return 0;
}