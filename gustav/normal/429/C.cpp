#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 25
#define pc __builtin_popcount

int N;
int c[25];

int dp_solve[1 << 12][25];
int dp_split[1 << 12][25][2];

int solve(int mask, int leafs);
int split(int mask, int leafs);

int split(int mask, int leafs, int force) {
  int &ref = dp_split[mask][leafs][force];
  ref = 0;

  if (!force && solve(mask, leafs))
    return ref = 1;

  for (int k = 2; k < leafs; ++k) {
    for (int m = ((mask - 1) & mask); m; m = (m - 1) & mask) {
      if (solve(m, k) && split(mask ^ m, leafs - k, 0))
        return ref = 1;
    }
  }

  return ref;
}

int solve(int mask, int leafs) {
  if (mask == 0 && leafs == 0) return 1;
  if (mask == 0 || leafs == 0) return 0;
  if (leafs < 2) return 0;

  int &ref = dp_solve[mask][leafs];
  ref = 0;

  for (int i = 0; i < 13; ++i) {
    if (((mask >> i) & 1) == 1) {
      if (c[i] == pc(mask) + leafs) {
        for (int k = 0; k <= leafs; ++k) {
          if (split(mask ^ (1 << i), leafs - k, k == 0))
            return ref = 1;
        }
      }
    }
  }

  return ref = 0;
}

int main(void)
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%d", c + i);

  sort(c, c + N);
  reverse(c, c + N);

  int leafs = 0;
  for (int i = 0; i < N; ++i)
    if (c[i] == 1)
      ++leafs;

  if (N == 1) {
    puts(leafs == 1 ? "YES" : "NO");
    return 0;
  }

  if (2 * leafs <= N) {
    puts("NO");
    return 0;
  }

  memset(dp_solve, -1, sizeof dp_solve);
  memset(dp_split, -1, sizeof dp_split);

  if (solve((1 << (N - leafs)) - 1, leafs))
    puts("YES");
  else
    puts("NO");

  return 0;
}