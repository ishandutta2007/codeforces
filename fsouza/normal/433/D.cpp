#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 1000
#define MAXM 1000

typedef long long lint;

using namespace std;

bool light[MAXN][MAXM];
int toup[MAXN][MAXM], todown[MAXN][MAXM], toleft[MAXN][MAXM], toright[MAXN][MAXM];

int main(int argc, char ** argv)
{
  int n, m, nq;

  scanf("%d %d %d", &n, &m, &nq);

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) {
      int v;
      scanf("%d", &v);
      light[y][x] = (v == 1);
    }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++)
      toleft[y][x] = (light[y][x] ? (1 + (x-1 >= 0 ? toleft[y][x-1] : 0)) : 0);
    for (int x = m-1; x >= 0; x--)
      toright[y][x] = (light[y][x] ? (1 + (x+1 < m ? toright[y][x+1] : 0)) : 0);
  }

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < n; y++)
      toup[y][x] = (light[y][x] ? (1 + (y-1 >= 0 ? toup[y-1][x] : 0)) : 0);
    for (int y = n-1; y >= 0; y--)
      todown[y][x] = (light[y][x] ? (1 + (y+1 < n ? todown[y+1][x] : 0)) : 0);
  }
  
  for (int q = 0; q < nq; q++) {
    int op, x2, y2;

    scanf("%d %d %d", &op, &x2, &y2); x2--, y2--;
    swap(x2, y2); // Oops

    if (op == 1) {
      light[y2][x2] ^= 1;

      { 
	int y = y2;
	for (int x = 0; x < m; x++)
	  toleft[y][x] = (light[y][x] ? (1 + (x-1 >= 0 ? toleft[y][x-1] : 0)) : 0);
	for (int x = m-1; x >= 0; x--)
	  toright[y][x] = (light[y][x] ? (1 + (x+1 < m ? toright[y][x+1] : 0)) : 0);
      } {
	int x = x2;
	for (int y = 0; y < n; y++)
	  toup[y][x] = (light[y][x] ? (1 + (y-1 >= 0 ? toup[y-1][x] : 0)) : 0);
	for (int y = n-1; y >= 0; y--)
	  todown[y][x] = (light[y][x] ? (1 + (y+1 < n ? todown[y+1][x] : 0)) : 0);
      }
    } else {
      int result = 0;
      int y = y2, x = x2;

      {
	int l = x, r = x;
	for (int h = toup[y][x]; h >= 0; h--) {
	  while (l-1 >= 0 && toup[y][l-1] >= h) l--;
	  while (r+1 < m && toup[y][r+1] >= h) r++;
	  result = max(result, (r-l+1) * h);
	}
	l = x, r = x;
	for (int h = todown[y][x]; h >= 0; h--) {
	  while (l-1 >= 0 && todown[y][l-1] >= h) l--;
	  while (r+1 < m && todown[y][r+1] >= h) r++;
	  result = max(result, (r-l+1) * h);
	}
      } {
	int u = y, d = y;
	for (int h = toleft[y][x]; h >= 0; h--) {
	  while (u-1 >= 0 && toleft[u-1][x] >= h) u--;
	  while (d+1 < n && toleft[d+1][x] >= h) d++;
	  result = max(result, (d-u+1) * h);
	}
	u = y, d = y;
	for (int h = toright[y][x]; h >= 0; h--) {
	  while (u-1 >= 0 && toright[u-1][x] >= h) u--;
	  while (d+1 < n && toright[d+1][x] >= h) d++;
	  result = max(result, (d-u+1) * h);
	}
      }

      printf("%d\n", result);
    }
  }

  return 0;
}