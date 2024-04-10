#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;
typedef function< int(int,int) > fn;

#define MAXN 100005

int N;
int a[MAXN];
int l[MAXN], r[MAXN];

void calc(int *a, int *l, fn cmp) {
  for (int i = 0; i < N; ++i)
    l[i] = 1;

  for (int i = 1; i < N; ++i) {
    if (cmp(a[i - 1], a[i])) {
      l[i] = l[i - 1] + 1;
    }
  }
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  if (N == 1) {
    puts("1");
    return 0;
  }

  calc(a, l, [](int a, int b) { return a < b; });
  reverse(a, a + N);
  calc(a, r, [](int a, int b) { return a > b; });
  reverse(r, r + N);
  reverse(a, a + N);

  int sol = *max_element(l, l + N);
  sol = max(sol, *max_element(l, l + N - 1) + 1);
  sol = max(sol, *max_element(r + 1, r + N) + 1);

  for (int i = 1; i < N - 1; ++i) {
    if (a[i - 1] + 1 < a[i + 1]) {
      sol = max(sol, l[i - 1] + 1 + r[i + 1]);
    }
  }

  printf("%d\n", sol);

  return 0;
}