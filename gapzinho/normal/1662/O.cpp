#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"

const int ms = 5005, mv = 1e6;

int grid[50][740];
int vis[50][740];

void dfs(int x, int y) {
    if(x < 0 ) return;
    if(y == 720) {
        dfs(x, 0);
        return;
    }
    if(y == -1) {
        dfs(x, 719);
        return;
    }
    // cout << x << "  " << y << endl;
    if(x > 45) return;
    if(grid[x][y]) return;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

void solve() {
    memset(grid, 0, sizeof grid);
  int n;
  cin >> n;
  while(n--) {
    char t;
    cin >> t;
    int a, b, c;
    cin >> a >> b >> c;
    if(t == 'C') {
      if(c < b) {
        for(int i = b*2; i < 720; ++i) {
            grid[a*2][i] = 1;
        }
        for(int i = 0; i < c*2; ++i) {
            grid[a*2][i] = 1;
        }
      } else {
        for(int i = b*2; i < c*2; ++i) {
            grid[a*2][i] = 1;
        }
      }
    }
    else {
        for(int i = a*2; i < b*2; i++) {
            grid[i][c*2] = 1;
        }
    }
  }
  memset(vis, 0, sizeof vis);
  dfs(0, 0);
  if(vis[45][0]) {
      cout << "YES" << endl;
  } else {
      cout << "NO" << endl;
  }
}

 main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}