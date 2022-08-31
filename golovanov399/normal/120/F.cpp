#include <cstdio>
#include <iostream>

#include <vector>

using namespace std;

#define sz(x) ((int)(x).size())
#define pb push_back

const int maxn = 100 + 5;

vector <int> A[maxn];

int dfs(int v, int p) 
{
  int res = 0;
  
  for (int i = 0; i < sz(A[v]); ++i) {
    int u = A[v][i];
    if (u == p)
      continue;
      
    res = max(res, dfs(u, v));
  }
  
  return res + 1;
}

int solve()
{
  int n;
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    A[i].clear();
  }
  
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    A[v].pb(u);
    A[u].pb(v);
  }
  
  int res = -1;
  
  for (int i = 0; i < n; ++i) {
    res = max(res, dfs(i, -1));
  }
  
  return res - 1;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int t;
  cin >> t;
  
  int res = 0;
  
  for (int i = 0; i < t; ++i) {
    res += solve();
  }
  
  cout << res << "\n";
  
  return 0;
}