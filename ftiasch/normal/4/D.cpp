// Codeforces Beta Round #4
// Problem D -- Mysterious Present
#include <cstdio>
#include <algorithm>

#define maxN 5001

using namespace std;

int n, w[maxN], h[maxN], o[maxN], f[maxN], p[maxN];

bool cmp(int a, int b)
{
  if(w[a] == w[b])
    return h[a] > h[b];
  return w[a] < w[b];
}

int main()
{
  scanf("%d%d%d", &n, w, h);
  for(int i = 1; i <= n; ++ i)
    scanf("%d%d", w + i, h + i);
  for(int i = 0; i <= n; ++ i)
    o[i] = i;
  sort(o, o + (n + 1), cmp);
  for(int i = n; i >= 0; -- i)
  {
    f[i] = 1, p[i] = n + 1;
    for(int j = n; j > i; -- j)
      if(h[o[i]] < h[o[j]] && f[j] + 1 > f[i])
        f[i] = f[j] + 1, p[i] = j;
  }
  for(int i = 0; i <= n; ++ i)
    if(!o[i])
    {
      if(f[i] == 1)
        printf("0\n");
      else
      {
        printf("%d\n", f[i] - 1);
        for(int j = p[i]; j <= n; j = p[j])
          printf("%d ", o[j]);
        printf("\n");
      }
    }
  return 0;
}