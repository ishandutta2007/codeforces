#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 N, A[100000];
pair< int64, int64 > par[100000];
vector< int64 > graph[100000];
int64 updp[100000];
bool memo[100000];

int64 rec(int idx)
{
  if(idx == -1)   return(0);
  if(memo[idx]++) return(updp[idx]);
  return(updp[idx] = max(0LL, rec(par[idx].first) + par[idx].second));
}
int dfs(int idx)
{
  if(updp[idx] > A[idx]) return(0);
  int ret = 1;
  for(int to : graph[idx]) ret += dfs(to);
  return(ret);
}
int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", A + i);
  }
  par[0] = {-1, 0};
  for(int i = 1; i < N; i++) {
    int p, c;
    scanf("%d %d", &p, &c);
    --p;
    par[i] = {p, c};
    graph[p].push_back(i);
  }
  for(int i = 0; i < N; i++) rec(i);
  printf("%d\n", N - dfs(0));
}