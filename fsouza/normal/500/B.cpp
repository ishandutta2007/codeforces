#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 300

using namespace std;

int mark[MAXN], perm[MAXN];
char adj[MAXN][MAXN+1];
vector<int> pos, vals;
int n;

void dfs(int v) {
  mark[v] = 1;
  pos.push_back(v);
  vals.push_back(perm[v]);

  for (int i = 0; i < n; i++)
    if (adj[v][i] == '1' && !mark[i])
      dfs(i);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &perm[i]);
    perm[i]--;
  }

  for (int i = 0; i < n; i++)
    scanf(" %s", adj[i]);

  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < n; i++)
    if (!mark[i]) {
      pos.clear();
      vals.clear();

      dfs(i);

      sort(pos.begin(), pos.end());
      sort(vals.begin(), vals.end());
      
      for (int j = 0; j < (int)pos.size(); j++)
	perm[pos[j]] = vals[j];
    }

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) printf(" ");
    printf("%d", perm[i]+1);
  }
  printf("\n");

  return 0;
}