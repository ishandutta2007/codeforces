#include<bits/stdc++.h>

using namespace std;

const string tmp[5] = {"+", "-|", "^>v<", "URDL", "*"};
const bool hogei[4][5][5] = {
    {{1}, {0, 1}, {1, 0, 0, 0}, {0, 1, 1, 1}, {0}},
    {{1}, {1, 0}, {0, 1, 0, 0}, {1, 0, 1, 1}, {0}},
    {{1}, {0, 1}, {0, 0, 1, 0}, {1, 1, 0, 1}, {0}},
    {{1}, {1, 0}, {0, 0, 0, 1}, {1, 1, 1, 0}, {0}}
};
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int W, H;
string S[1000];
int sx, sy, tx, ty;

bool v[1000][1000][4];

bool out(int x, int y)
{
  return (x < 0 || y < 0 || x >= W || y >= H);
}

bool canMove(int x, int y, int move, int nowdir)
{
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < tmp[i].size(); j++) {
      if(tmp[i][j] == S[y][x]) {
        return(hogei[move][i][(j + nowdir) % tmp[i].size()]);
      }
    }
  }
}

int bfs()
{
  queue < tuple < int, int, int, int > > que;
  que.emplace(0, sx, sy, 0);
  v[sx][sy][0] = true;

  while(!que.empty()) {
    int cost, x, y, dir;
    tie(cost, x, y, dir) = que.front();
    que.pop();
    if(x == tx && y == ty) return (cost);
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if(out(nx, ny)) continue;
      if(!canMove(x, y, i, dir)) continue;
      if(!canMove(nx, ny, (i + 2) % 4, dir)) continue;
      if(v[nx][ny][dir]++) continue;
      que.emplace(cost + 1, nx, ny, dir);
    }
    if(v[x][y][(dir + 1) % 4]++) continue;
    que.emplace(cost + 1, x, y, (dir + 1) % 4);
  }
  return (-1);
}

int main()
{


  cin >> H >> W;
  for(int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  cin >> sy >> sx;
  cin >> ty >> tx;
  --sx, --sy;
  --tx, --ty;
  cout << bfs() << endl;
}