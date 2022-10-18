#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N;
int a[MAXN];

int main(void)
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  int start = -1;
  int end = -1;

  for (int i = 0; i < N - 1; ++i) {
    if (a[i] > a[i + 1]) {
      start = (start == -1) ? i : start;
      end = i + 1;
    }
  }

  for (int i = start, j = end; i < j; ++i, --j) 
    swap(a[i], a[j]);

  bool ok = true;
  for (int i = 0; i < N - 1; ++i)
    if (a[i] > a[i + 1])
      ok = false;

  if (ok)
    printf("yes\n%d %d\n", max(0, start) + 1, max(0, end) + 1);
  else
    puts("no");

  return 0;
}