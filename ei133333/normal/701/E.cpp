#include<bits/stdc++.h>
using namespace std;

int N, K;
int C[200000];
vector< int > graph[200000];
long long ret;

long long dfs(int idx, int prev)
{
  int in = C[idx];
  for(int to : graph[idx]) {
    if(prev != to) in += dfs(to, idx);
  }
  if(~prev) ret += min(in, 2 * K - in);
  return(~prev ? in : ret);
}
int main()
{
  cin >> N >> K;
  for(int i = 0; i < 2 * K; i++) {
    int U;
    cin >> U;
    C[--U] = true;
  }
  for(int i = 0; i < N - 1; i++) {
    int U, V;
    cin >> U >> V;
    --U, --V;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  cout << dfs(0, -1) << endl;
}