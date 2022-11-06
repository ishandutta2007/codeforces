#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define MAXN 500

using namespace std;

typedef long long lint;

int adj[MAXN][MAXN];
int color[MAXN];
bool ok;

void dfs(int v, int c, int n) {
  if (color[v] != -1) {
    if (color[v] != c) ok = false;
    return;
  }
  color[v] = c;
  for (int u = 0; u < n; ++u)
    if (adj[v][u])
      dfs(u, c^1, n);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      adj[i][j] = 0;

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a][b] = adj[b][a] = 1;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j) {
	adj[i][j] = (adj[i][j]^1);
      }

  ok = true;
  for (int i = 0; i < n; ++i) color[i] = -1;
  for (int i = 0; i < n; ++i)
    if (color[i] == -1)
      dfs(i, 0, n);

  if (!ok) printf("No\n");
  else {
    string cand(n, ' ');
    for (int i = 0; i < n; ++i) {
      int nadj = 0;
      for (int j = 0; j < n; ++j)
	if (adj[j][i])
	  ++nadj;

      if (nadj == 0) cand[i] = 'b';
      else if (color[i] == 0) cand[i] = 'a';
      else cand[i] = 'c';
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	if (i != j) {
	  bool right = (adj[i][j] == ( (cand[i] == 'a' && cand[j] == 'c') || (cand[i] == 'c' && cand[j] == 'a')));
	  if (!right) ok = false;
	}

    if (ok) {
      printf("Yes\n");
      printf("%s\n", cand.c_str());
    } else {
      printf("No\n");      
    }
  }
  
  return 0;
}