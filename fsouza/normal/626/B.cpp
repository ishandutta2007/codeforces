#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define MAXN 200
#define MAXS (3*MAXN)

using namespace std;

typedef long long lint;

char possible[MAXS+1][MAXS+1][MAXS+1];

int main() {
  int n;
  scanf("%d", &n);
  map<char, int> many;
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    ++many[c];
  }
  int nr = many['R'], ng = many['G'], nb = many['B'];

  memset(possible, 0, sizeof(possible));
  possible[nr][ng][nb] = true;
  for (int s = nr+ng+nb; s > 1; --s) {
    for (int r = 0; r <= s; ++r)
      for (int g = 0; g <= s; ++g) {
	const int b = s-r-g;
	if (b >= 0 && possible[r][g][b]) {
	  if (r > 0 && g > 0) possible[r-1][g-1][b+1] = true;
	  if (r > 0 && b > 0) possible[r-1][g+1][b-1] = true;
	  if (g > 0 && b > 0) possible[r+1][g-1][b-1] = true;
	  if (r >= 2) possible[r-1][g][b] = true;
	  if (g >= 2) possible[r][g-1][b] = true;
	  if (b >= 2) possible[r][g][b-1] = true;
	}
      }
  }

  if (possible[0][0][1]) printf("B");
  if (possible[0][1][0]) printf("G");
  if (possible[1][0][0]) printf("R");
  printf("\n");
  return 0;
}