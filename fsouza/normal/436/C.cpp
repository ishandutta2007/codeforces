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
#define MAXK 1010
#define MAXNM 100

typedef long long lint;

using namespace std;

int adj[MAXK+1][MAXK+1];
char field[MAXK][MAXNM];
int dist[MAXK+1], mark[MAXK+1];
int parent[MAXK+1];
vector <pair <int, int> > ans;

int prim(int n) {
  int ret = 0;

  for (int i = 0; i < n; i++) dist[i] = INF, mark[i] = 0, parent[i] = -1;
  int current = n-1;

  dist[current] = 0;
  
  while (current != -1) {
    mark[current] = 1;
    
    for (int j = 0; j < n; j++)
      if (adj[current][j] < dist[j]) {
	dist[j] = adj[current][j];
	parent[j] = current;
      }

    current = -1;
    for (int j = 0; j < n; j++)
      if (!mark[j] && (current == -1 || dist[j] < dist[current]))
	current = j;

    if (current != -1) {
      ans.push_back(make_pair(current, parent[current]));
      ret += dist[current];
    }
  }

  return ret;
}

int main(int argc, char ** argv)
{
  int n, m, k, w;

  scanf("%d %d %d %d", &n, &m, &k, &w);
  int nm = n*m;

  for (int z = 0; z < k; z++)
    for (int i = 0; i < nm; i++)
      scanf(" %c", &field[z][i]);
  
  for (int a = 0; a < k; a++) {
    adj[a][a] = 0;
    for (int b = a+1; b < k; b++) {
      int v = 0;
      for (int i = 0; i < nm; i++) v += (field[a][i] != field[b][i]);
      adj[a][b] = adj[b][a] = v * w;
    }
  }

  for (int a = 0; a < k; a++) adj[a][k] = adj[k][a] = n*m;
  adj[k][k] = 0;
  
  printf("%d\n", prim(k+1));
  for (int i = 0; i < (int)ans.size(); i++) {
    int a = ans[i].first, b = ans[i].second;
    a++;
    if (b == k) b = 0; else b++;
    printf("%d %d\n", a, b);
  }

  return 0;
}