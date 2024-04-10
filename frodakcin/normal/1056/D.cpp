#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef vector<int> vi;
#define pb push_back

const int MAXN = 1e5 + 100;

int N;
vi adj[MAXN];

int t[MAXN];

int dfs(const int& n, const int& p = -1) {
  int v = 0;
  for(int i = 0;i < adj[n].size();i++) v += dfs(adj[n][i], n);
  if(v == 0) v = 1;
  t[v]++;
  return v;
}

int main() {
  scanf("%d", &N);
  
  for(int i = 2, u;i <= N;i++) {
    scanf("%d", &u);
    adj[u].pb(i);
  }
  for(int i = 0;i <= N;i++) t[i] = 0;
  
  dfs(1);
  
  int h = 0;
  for(int i = 1, j = 0;i <= N;i++) {
    while(h < i) h += t[++j];
    printf("%d ", j);
  }
  printf("\n");
  
  return 0;
}