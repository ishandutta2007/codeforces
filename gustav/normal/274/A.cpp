#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N, K;
int a[MAXN];
int m[MAXN];

int main(void)
{
  scanf("%d%d", &N, &K);

  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  sort(a, a + N);
  
  if (K == 1) {
    printf("%d\n", N);
    return 0;
  }

  int sol = 0;

  for (int i = 0; i < N; ++i) {
    if (m[i]) continue;

    long long c = a[i];
    m[i] = 1;

    int len = 1;

    while (c * K <= a[N - 1]) {
      c *= K;
      int j = lower_bound(a, a + N, (int)c) - a;
      
      if (a[j] == c) ++len, m[j] = 1;
      else break;
    }

    sol += (len + 1) / 2;
  }

  printf("%d\n", sol);

  return 0;
}