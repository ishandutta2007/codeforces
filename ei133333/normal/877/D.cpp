#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int vy[] = {1, 0, -1, 0}, vx[] = {0, 1, 0, -1};

int H, W, K;
string S[1000];
int SY, SX, GY, GX;
int v[1000][1000][5];

int main()
{
  cin >> H >> W >> K;
  for(int i = 0; i < H; i++) cin >> S[i];
  cin >> SY >> SX >> GY >> GX;
  --SY, --SX, --GY, --GX;

  queue< tuple< int, int > > que;
  fill_n(**v, 1000 * 1000 * 5, INF);

  auto update = [&](int x, int y, int dir, int cost)
  {
    if(cost < v[x][y][dir]) {
      v[x][y][dir] = cost;
      if(cost < v[x][y][4]) {
        v[x][y][4] = cost;
        que.emplace(x, y);
      }
      return (true);
    }
    return (false);
  };

  update(SX, SY,0, 0);

  while(!que.empty()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    auto cost = v[x][y][4];

    if(x == GX && y == GY) {
      cout << cost << endl;
      return (0);
    }

    for(int i = 0; i < 4; i++) {
      for(int j = 1; j <= K; j++) {
        int ny = y + vy[i] * j, nx = x + vx[i] * j;
        if(ny < 0 || nx < 0 || ny >= H || nx >= W) break;
        if(S[ny][nx] == '#') break;
        if(!update(nx, ny, i, cost + 1)) break;
      }
    }
  }

  cout << -1 << endl;
}