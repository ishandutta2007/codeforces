#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000
#define MAXM 100000

using namespace std;

int ret[MAXN];
int l[MAXM], r[MAXM], q[MAXM];

int delta[MAXN], sum[MAXN];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int j = 0; j < m; j++) scanf("%d %d %d", &l[j], &r[j], &q[j]), l[j]--, r[j]--;

  bool ok = true;

  for (int i = 0; i < n; i++) ret[i] = 0;

  for (int b = 0; b < 30; b++) {
    for (int i = 0; i < n; i++) delta[i] = 0;
    for (int j = 0; j < m; j++) {
      if (q[j] & (1<<b)) {
	delta[l[j]]++;
	if (r[j]+1 < n) delta[r[j]+1]--;
      }
    }
    int v = 0;
    for (int i = 0; i < n; i++) {
      v += delta[i];
      if (v) ret[i] |= 1<<b;
      else ret[i] &= ~(1<<b);
      sum[i] = (v > 0);
      if (i-1 >= 0) sum[i] += sum[i-1];
    }
    
    for (int j = 0; j < m; j++)
      if (!(q[j] & (1<<b))) {
	int many = sum[r[j]] - (l[j]-1 >= 0 ? sum[l[j]-1] : 0);
	if (many == (r[j]-l[j]+1))
	  ok = false;
      }
  }

  if (ok) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      if (i-1 >= 0) printf(" ");
      printf("%d", ret[i]);
    }
    printf("\n");
  } else {
    printf("NO\n");
  }

  return 0;
}