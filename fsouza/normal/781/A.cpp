#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 200000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
int color[MAXN];

void dfs(int v, int p, int colorv, int colorp) {
  int nextcolor = 0;
  color[v] = colorv;
  for (int u : adj[v])
    if (u != p) {
      while (nextcolor == colorv || nextcolor == colorp)
        ++nextcolor;
      dfs(u, v, nextcolor, colorv);
      ++nextcolor;
    }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1, 0, -1);

  int ncolor = *max_element(color, color + n) + 1;
  printf("%d\n", ncolor);
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", color[i] + 1);
  }
  printf("\n");

  return 0;
}