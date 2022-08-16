#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dx[] = {-1, 0, 1, -1, -1, 0, 1, 1};
string S;
char grid[2][13];
bool used[26];

bool isover(int x, int y)
{
  return (x < 0 || y < 0 || x >= 13 || y >= 2);
}

bool solve(int idx, int x, int y)
{
  if(idx == S.size()) {
    return (true);
  } else if(used[S[idx] - 'A']) {
    for(int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if(isover(nx, ny)) continue;
      if(grid[ny][nx] == S[idx]) return (solve(idx + 1, nx, ny));
    }
  } else {
    used[S[idx] - 'A'] = true;

    if(grid[y ^ 1][x] == 0) {
      grid[y ^ 1][x] = S[idx];
      if(solve(idx + 1, x, y ^ 1)) return (true);
      grid[y ^ 1][x] = 0;
    }

    if(!isover(x + 1, y) && grid[y][x + 1] == 0) {
      grid[y][x + 1] = S[idx];
      if(solve(idx + 1, x + 1, y)) return (true);
      grid[y][x + 1] = 0;
    } else if(!isover(x + 1, y ^ 1) && grid[y ^ 1][x + 1] == 0) {
      grid[y ^ 1][x + 1] = S[idx];
      if(solve(idx + 1, x + 1, y ^ 1)) return (true);
      grid[y ^ 1][x + 1] = 0;
    }

    if(!isover(x - 1, y) && grid[y][x - 1] == 0) {
      grid[y][x - 1] = S[idx];
      if(solve(idx + 1, x - 1, y)) return (true);
      grid[y][x - 1] = 0;
    } else if(!isover(x - 1, y ^ 1) && grid[y ^ 1][x - 1] == 0) {
      grid[y ^ 1][x - 1] = S[idx];
      if(solve(idx + 1, x - 1, y ^ 1)) return (true);
      grid[y ^ 1][x - 1] = 0;
    }

    used[S[idx] - 'A'] = false;
  }
  return (false);
}

void Output()
{
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 13; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  exit(0);
}

int main()
{
  cin >> S;
  for(int i = 0; i < 12; i++) {
    grid[0][i] = S.front();
    used[S.front() - 'A'] = true;
    if(solve(1, i, 0)) Output();
    grid[0][i] = 0;
    used[S.front() - 'A'] = false;
  }
  cout << "Impossible" << endl;
}