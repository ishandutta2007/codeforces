#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

#define MAXN 2000
#define MAXM 2000

using namespace std;

typedef long long lint;

int bup[MAXN][MAXM], bdown[MAXN][MAXM], parent[MAXN][MAXM], myrank[MAXN][MAXM];

int search(int x, int a) {
  if (parent[x][a] == a) return a;
  return parent[x][a] = search(x, parent[x][a]);
}

int join(int x, int a, int b) {
  a = search(x, a); b = search(x, b);
  if (a == b) return a;
  if (myrank[x][a] > myrank[x][b]) swap(a, b);

  parent[x][a] = b;
  if (myrank[x][a] == myrank[x][b]) myrank[x][b]++;

  bup[x][b] = min(bup[x][b], bup[x][a]);
  bdown[x][b] = max(bdown[x][b], bdown[x][a]);

  return b;
}

int main() {
  int n, m, k;

  scanf("%d %d %d", &n, &m, &k);
  bool inv = n > m;

  if (inv) swap(n, m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      bup[i][j] = bdown[i][j] = parent[i][j] = -1;
      myrank[i][j] = 0;
    }

  for (int q = 0; q < k; q++) {
    int tx, ty;
    scanf("%d %d", &tx, &ty); tx--, ty--;
    if (inv) swap(tx, ty);
      
    pair<int, pair<int, int> > ret(1000000000, make_pair(-1, -1));

    for (int dx = 0; dx < n && dx <= ret.first; dx++)
      for (int dir = 0; dir < 2; dir++) {
	int x = tx + (dir ? -dx : dx);
	if (x < 0 || x >= n || (dx == 0 && dir == 1)) continue;

	if (parent[x][ty] == -1) {
	  int y = ty;
	  if (!inv)
	    ret = min(ret, make_pair(dx + abs(y - ty), make_pair(x, y)));
	  else
	    ret = min(ret, make_pair(dx + abs(y - ty), make_pair(y, x)));
	} else {
	  int rooty = search(x, ty);
	  if (bup[x][rooty]-1 >= 0) {
	    int y = bup[x][rooty]-1;
	    if (!inv)
	      ret = min(ret, make_pair(dx + abs(y - ty), make_pair(x, y)));
	    else
	      ret = min(ret, make_pair(dx + abs(y - ty), make_pair(y, x)));
	  }
	  if (bdown[x][rooty]+1 < m) {
	    int y = bdown[x][rooty]+1;
	    if (!inv)
	      ret = min(ret, make_pair(dx + abs(y - ty), make_pair(x, y)));
	    else
	      ret = min(ret, make_pair(dx + abs(y - ty), make_pair(y, x)));
	  }
	}
      }
    
    int x, y;
    if (!inv) x = ret.second.first, y = ret.second.second;
    else y = ret.second.first, x = ret.second.second;

    if (!inv) printf("%d %d\n", x+1, y+1);
    else printf("%d %d\n", y+1, x+1);
    
    parent[x][y] = bup[x][y] = bdown[x][y] = y;
    if (bup[x][y]-1 >= 0 && parent[x][bup[x][y]-1] != -1)
      y = join(x, y, bup[x][y]-1);
    if (bdown[x][y]+1 < m && parent[x][bdown[x][y]+1] != -1)
      join(x, y, bdown[x][y]+1);
  }
  
  return 0;
}