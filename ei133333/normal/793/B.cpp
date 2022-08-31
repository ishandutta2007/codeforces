#include <bits/stdc++.h>

using namespace std;

const int vy[] = {1, 0, -1, 0}, vx[] = {0, 1, 0, -1};


int H, W;
int sx, sy;
string S[1000];
bool v[1000][1000][3][4];

bool isover(int y, int x)
{
  return (y < 0 || y >= H || x < 0 || x >= W);
}

int main()
{

  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == 'S') {
        sx = j;
        sy = i;
      }
    }
  }

  queue< tuple< int, int, int, int > > que;
  for(int i = 0; i < 4; i++) {
    v[sy][sx][0][i] = true;
    que.emplace(sy, sx, 0, i);
  }

  while(!que.empty()) {
    int y, x, times, dir;
    tie(y, x, times, dir) = que.front();
    que.pop();

    if(S[y][x] == 'T') {
      cout << "YES" << endl;
      return (0);
    }

    for(int i = 0; i < 4; i++) {
      int ny = y + vy[i], nx = x + vx[i];
      if(isover(ny, nx)) continue;
      if(S[ny][nx] == '*') continue;
      int ntimes = times + (i != dir);
      if(ntimes >= 3) continue;
      if(v[ny][nx][ntimes][i]++) continue;
      que.emplace(ny, nx, ntimes, i);
    }
  }

  cout << "NO" << endl;

}