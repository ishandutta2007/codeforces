#include <bits/stdc++.h>
using namespace std;

const int maxN = 3000 + 5;
int n;
vector<int> G[maxN];

vector<int> loop;
int no[maxN];
bool vis[maxN];

int stk[maxN], len = 0;
bool DFS(int u, int fa) {
  stk[len ++] = u;
  vis[u] = true;
  for(int v : G[u]) if(v != fa) {
    if(vis[v]) {
      do {
        len --;
        loop.push_back(stk[len]);
        no[stk[len]] = (int)loop.size() - 1;
      } while(stk[len] != v);
      return true;
    } else {
      if(DFS(v, u)) return true;
    }
  }
  -- len;
  return false;
}

double ans = 0;

vector<int> l[maxN];
void Go(int u, int fa) {
  l[u].assign(1, 0);
  for(int v : G[u]) if(v != fa) {
    Go(v, u);
    for(int x : l[u]) for(int y : l[v]) {
      ans += 1.0 / (x + y + 1 + 1);
    }
    for(int y : l[v]) l[u].push_back(y + 1);
    l[v].clear();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++ i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  memset(vis, 0, sizeof(vis));
  memset(no, -1, sizeof(no));
  bool foundCycle = DFS(0, -1);
  assert(foundCycle);
  for(int u : loop) {
    for(auto i = G[u].begin(); i != G[u].end(); ++ i) if(no[*i] >= 0) {
      G[u].erase(i); break;
    }
    for(auto i = G[u].begin(); i != G[u].end(); ++ i) if(no[*i] >= 0) {
      G[u].erase(i); break;
    }
    Go(u, -1);
  }
  for(int A : loop) for(int B : loop) {
    int i = no[A], j = no[B];
    if(i >= j) continue;
    int x = j - i, y = (int)loop.size() + i - j;
    for(int u : l[A]) for(int v : l[B]) {
      ans += 1.0 / (u + v + x + 1) + 1.0 / (u + v + y + 1) - 1.0 / (u + v + x + y);
      // printf("%d %d %d %d\n", u, v, x, y);
    }
  }
  cout << fixed << setprecision(10) << ans * 2.0 + n << endl;
  return 0;
}