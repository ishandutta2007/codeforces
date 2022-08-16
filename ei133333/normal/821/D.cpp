#include<bits/stdc++.h>

using namespace std;

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};

int main()
{

  int H, W, K;
  set< int > cell1[10005], cell2[10005];

  cin >> H >> W >> K;
  for(int i = 0; i < K; i++) {
    int y, x;
    cin >> y >> x;
    --y, --x;
    cell1[y].emplace(x);
    cell2[x].emplace(y);
  }

  typedef tuple< int, int, int, int > Pi;
  deque< Pi > que;
  map< pair< int, int >, int > vv[3];

  auto update = [&](int tt, int yyy, int xxx, int cs, int add)
  {
    cs += add;
    if(!vv[tt].count({yyy, xxx}) || cs < vv[tt][{yyy, xxx}]) {
      vv[tt][{yyy, xxx}] = cs;
      if(add) que.emplace_back(cs, yyy, xxx, tt);
      else que.emplace_front(cs, yyy, xxx, tt);
    }
  };

  update(0, 0, 0, 0, 0);

  while(!que.empty()) {
    int ny, nx, cost, type;
    tie(cost, ny, nx, type) = que.front();
    que.pop_front();
    if(cost > vv[type][{ny, nx}]) continue;

    if((type == 0 && ny == H - 1 && nx == W - 1) ||
       (type == 1 && ny == H - 1) ||
       (type == 2 && nx == W - 1)) {
      cout << cost << endl;
      return (0);
    }

    if(type == 0) {
      for(int i = 0; i < 4; i++) {
        int sy = ny + vy[i], sx = nx + vx[i];
        if(sy < 0 || sx < 0 || sy >= H || sx >= W) continue;
        if(cell1[sy].count(sx)) update(0, sy, sx, cost, 0);
      }
      if(ny) {
        --ny;
        update(1, ny, -1, cost, 1);
        update(2, -1, nx, cost, 1);
        ++ny;
      }
      if(nx) {
        --nx;
        update(1, ny, -1, cost, 1);
        update(2, -1, nx, cost, 1);
        ++nx;
      }
      if(ny + 1 < H) {
        ++ny;
        update(1, ny, -1, cost, 1);
        update(2, -1, nx, cost, 1);
        --ny;
      }
      if(nx + 1 < W) {
        ++nx;
        update(1, ny, -1, cost, 1);
        update(2, -1, nx, cost, 1);
        --nx;
      }
    } else if(type == 1) {
      for(auto &s : cell1[ny]) update(0, ny, s, cost, 0);
      if(ny) for(auto &s : cell1[ny - 1]) update(0, ny - 1, s, cost, 0);
      for(auto &s : cell1[ny + 1]) update(0, ny + 1, s, cost, 0);
    } else {
      for(auto &s : cell2[nx]) update(0, s, nx, cost, 0);
      if(nx) for(auto &s : cell2[nx - 1]) update(0, s, nx - 1, cost, 0);
      for(auto &s : cell2[nx + 1]) update(0, s, nx + 1, cost, 0);
    }
  }

  cout << -1 << endl;
}