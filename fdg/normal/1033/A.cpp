#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, arr[1005][1005];
bool ok = false;

int ax, ay, bx, by, cx, cy;

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n || arr[x][y] == 1)
    return;

  if (x == cx && y == cy)
    ok = true;

  arr[x][y] = 1;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy)
      dfs(x + dx, y + dy);
}

int main() {
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == ax || j == ay || abs(i - ax) == abs(j - ay))
        arr[i][j] = 1;
      // cout << arr[i][j];
    }
    // cout << endl;
  }

  dfs(bx, by);
  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}