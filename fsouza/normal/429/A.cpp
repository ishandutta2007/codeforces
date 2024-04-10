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
#define MAXN 100000

typedef long long lint;

using namespace std;

int state[2];
vector<int> adj[MAXN], ret;
int init[MAXN], goal[MAXN];

void dfs(int v, int parent, int h) {
  int back[2] = {state[0], state[1]};

  if ((init[v] ^ state[h%2]) != goal[v]) {
    state[h%2] ^= 1;
    ret.push_back(v);
  }
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int v2 = adj[v][i];
    if (v2 == parent) continue;
    dfs(v2, v, h+1);
  }

  state[0] = back[0], state[1] = back[1];
}

int main(int argc, char ** argv)
{
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b), a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) scanf("%d", &init[i]);
  for (int i = 0; i < n; i++) scanf("%d", &goal[i]);

  dfs(0, -1, 0);

  printf("%d\n", (int)ret.size());
  for (int i = 0; i < (int)ret.size(); i++)
    printf("%d\n", ret[i]+1);

  return 0;
}