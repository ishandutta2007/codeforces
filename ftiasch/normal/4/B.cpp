// Codeforces Beta Round #4
// Problem B -- Before an Exam
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[30], b[30], l, r;

int main()
{
  scanf("%d%d", &n, &m);
  l = r = 0;
  for(int i = 0; i < n; ++ i)
  {
    scanf("%d%d", a + i, b + i);
    l += a[i], r += b[i];
  }
  if(l <= m && m <= r)
  {
    printf("YES\n");
    m -= l;
    for(int i = 0; i < n; ++ i)
    {
      printf("%d ", a[i] + min(m, b[i] - a[i]));
      m -= min(m, b[i] - a[i]);
    }
    printf("\n");
  }
  else
    printf("NO\n");
  return 0;
}