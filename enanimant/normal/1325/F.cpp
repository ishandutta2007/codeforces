// March 14, 2020
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 100005;

int n, m, sqrt_n;
vector<int> g[N];

int depth[N];
bool in_set[N];
stack<int> stk;

void dfs(int v) {
  stk.push(v);
  bool any = false;
  for (int u : g[v]) {
    any |= in_set[u];
    if (depth[u] != -1) {
      if (depth[v] - depth[u] + 1 >= sqrt_n) {
        cout << "2\n";
        cout << depth[v] - depth[u] + 1 << '\n';
        for (int i = 0; i < depth[v] - depth[u] + 1; i++) {
          if (i > 0) {
            cout << ' ';
          }
          cout << stk.top() + 1;
          stk.pop();
        }
        cout << '\n';
        exit(0);
      }
      continue;
    }
    depth[u] = depth[v] + 1;
    dfs(u);
    any |= in_set[u];
  }
  if (!any) {
    in_set[v] = true;
  }
  stk.pop();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  sqrt_n = 2;
  while (sqrt_n * sqrt_n < n) {
    sqrt_n++;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(depth, depth + N, -1);
  depth[0] = 0;
  dfs(0);
  int cnt = 0;
  cout << "1\n";
  for (int i = 0; i < n && cnt < sqrt_n; i++) {
    if (in_set[i]) {
      if (cnt > 0) {
        cout << ' ';
      }
      cout << i + 1;
      cnt++;
    }
  }
  cout << '\n';
  // assert(cnt == sqrt_n);


  return 0;
}