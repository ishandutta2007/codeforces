#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 1000
#define MAXM 1000

using namespace std;

char table[MAXN][MAXM+1];
int breaknext[MAXM];

int main() {
  int n, m;
  
  scanf("%d %d", &n, &m);
  
  for (int y = 0; y < n; y++)
    scanf(" %s", table[y]);

  int ret = m;
  
  memset(breaknext, 0, sizeof(breaknext));

  for (int x = 0; x < m; x++) {
    bool ok = true;

    for (int y = 0; y+1 < n; y++) {
      if (breaknext[y]) {
      } else {
	if (table[y][x] > table[y+1][x])
	  ok = false;
      }
    }

    if (ok) {
      ret--;

      for (int y = 0; y+1 < n; y++) {
	if (breaknext[y]) {
	} else {
	  if (table[y][x] < table[y+1][x])
	    breaknext[y] = 1;
	}
      }
    }
  }
  
  printf("%d\n", ret);

  return 0;
}