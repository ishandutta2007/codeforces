#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1005;

int n;
int ax, ay, bx, by, cx, cy;
int vis[ms][ms];
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1 , -1};

bool dfs(int x, int y) {
  if(x < 0 || x > n || y < 0 || y > n || vis[x][y]) return false;
  //cout << "Dfs " << x << ' ' << y << endl;
  vis[x][y] = 1;
  if(x == cx && y == cy) return true;
  for(int i = 0; i < 8; i++) {
    if(dfs(x+dx[i], y+dy[i])) return true;
  }
  return false;
}

void go(int x, int y, int d) {
  if(x < 0 || x > n || y < 0 || y > n) return;
  vis[x][y] = 1;
  go(x+dx[d], y+dy[d], d);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  ax--; bx--; cx--; ay--; by--; cy--;
  for(int i = 0; i < 8; i++) go(ax, ay, i);
  if(dfs(bx, by)) cout << "YES\n";
  else cout << "NO\n";
}