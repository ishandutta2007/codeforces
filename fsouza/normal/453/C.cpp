#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

#define MAXN 100000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
bool mark[MAXN];
int have[MAXN], want[MAXN];
vector<int> ret;

void dfs(int v, bool root) {
  mark[v] = true;

  ret.push_back(v);
  have[v] ^= 1;

  for (int i = 0; i < (int)adj[v].size(); i++) {
    int v2 = adj[v][i];
    if (!mark[v2]) {
      dfs(v2, false);

      ret.push_back(v);
      have[v] ^= 1;

      if (have[v2] != want[v2]) {
	ret.push_back(v2);
	have[v2] ^= 1;

	ret.push_back(v);
	have[v] ^= 1;
      }
    }
  }

  if (root && have[v] != want[v]) {
    have[v] ^= 1;
    ret.pop_back();
  }
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    adj[i].clear();
    mark[i] = false;
    have[i] = 0;
  }
  
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b); a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++)
    scanf("%d", &want[i]);

  ret.clear();

  for (int i = 0; i < n; i++)
    if (want[i]) {
      dfs(i, true);
      break;
    }

  bool ok = true;

  for (int i = 0; i < n; i++)
    if (have[i] != want[i]) {
      ok = false;
      break;
    }

  if (!ok) printf("-1\n");
  else {
    printf("%d\n", (int)ret.size());
    if (!ret.empty()) {
      for (int i = 0; i < (int)ret.size(); i++) {
	if (i-1 >= 0) printf(" ");
	printf("%d", ret[i]+1);
      }
      printf("\n");
    }
  }
  
  return 0;
}