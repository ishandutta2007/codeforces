#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 200000
#define MAXV 1000000

using namespace std;

int a[MAXN];
int last[MAXV+1];

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  sort(a, a+n);
  n = unique(a, a+n)-a;

  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) last[a[i]] = a[i];

  int l = -1;
  for (int v = 0; v <= MAXV; v++) {
    if (last[v] != -1) l = last[v];
    last[v] = l;
  }
  
  int result = 0;

  const int c = 1000;

  for (int i = 0; i < n; i++) {
    if (a[i] > c) break;
    for (int j = i+1; j < n; j++) result = max(result, a[j] % a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (a[i] <= c) continue;

    const int lim = MAXV/a[i];
    int l = 0;
    for (int q = 1; q <= lim; q++) {
      l += a[i];
      int r = l + a[i] - 1;

      int guy = last[min(r, MAXV)];
//      if (guy >= l)
          result = max(result, guy - l);
    }
  }
  
  printf("%d\n", result);

  return 0;
}