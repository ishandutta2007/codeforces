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

#define MAXN 2500
#define MAXM 2500

typedef long long lint;

using namespace std;

char field[MAXN][MAXM+1];

int main(int argc, char ** argv)
{
  int n, m, k;
  
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < n; i++) scanf(" %s", field[i]);

  vector<int> ret(m, 0);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (field[i][j] == 'U') {
	if (i%2 == 0) ret[j]++;
      } else if (field[i][j] == 'L') {
	if (j-i >= 0) ret[j-i]++;
      } else if (field[i][j] == 'R') {
	if (j+i < m) ret[j+i]++;
      } else if (field[i][j] == 'D') {
      }
    }
  
  for (int i = 0; i < m; i++) {
    if (i-1 >= 0) printf(" ");
    printf("%d", ret[i]);
  }
  printf("\n");

  return 0;
}