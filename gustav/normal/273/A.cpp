#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX 100005

int N, M, w, h;
ll val;
ll a[MAX];

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) 
    scanf("%lld", a + i);

  scanf("%d", &M);

  ll cmax = 0;
  int next = 0;

  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &w, &h);

    while (next + 1 <= w) 
      cmax = max(cmax, a[next++]);

    printf("%lld\n", cmax);
    cmax += h;
  }

  return 0;
}