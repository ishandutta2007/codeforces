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

typedef long long lint;

using namespace std;

int g[5][5];

int main(int argc, char ** argv)
{
  int result = 0;

  for (int a = 0; a < 5; a++)
    for (int b = 0; b < 5; b++)
      scanf("%d", &g[a][b]);

  int order[5];

  for (int i = 0; i < 5; i++) order[i] = i;

  do {
    int res = 0;

    for (int i = -1; i < 5; i++)
      for (int j = i+1; j+1 < 5; j += 2)
	res += g[order[j]][order[j+1]] + g[order[j+1]][order[j]];

    result = max(result, res);
  } while (next_permutation(order, order+5));

  printf("%d\n", result);

  return 0;
}