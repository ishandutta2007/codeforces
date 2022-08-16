#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1LL << 60;
const int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int H, W, P;
vector< pair< int, int > > point[300 * 300 + 1];
int memo[300][300];
int cost[300][300];
int ps[300][300];

signed main()
{
  fill_n(*cost, 300 * 300, INF);
  
  scanf("%I64d %I64d %I64d", &H, &W, &P);
  
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      scanf("%I64d", &ps[i][j]);
      point[ps[i][j]].push_back({i, j});
    }
  }
  
  for(auto& to : point[1]) {
    cost[to.first][to.second] = min(cost[to.first][to.second], to.first + to.second);
  }
        
  int ret = INF;
  for(int i = 2; i <= P; i++) {
    if(point[i - 1].size() * point[i].size() > 4 * W * H) {
      queue< pair< int, pair< int, int > > > que;
      fill_n(*memo, 300 * 300, INF);
      for(auto k : point[i - 1]) {
        memo[k.first][k.second] = cost[k.first][k.second];
        que.push({cost[k.first][k.second], k});
      }
      while(!que.empty()) {
        auto p = que.front(); que.pop();
        if(p.first > memo[p.second.first][p.second.second]) continue;
        if(ps[p.second.first][p.second.second] == i) {
          cost[p.second.first][p.second.second] = p.first;
        }
        for(int i = 0; i < 4; i++) {
          int ny = p.second.first + dy[i], nx = p.second.second + dx[i];
          if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
          if(p.first + 1 >= memo[ny][nx]) continue;
          memo[ny][nx] = p.first + 1;
          que.push({memo[ny][nx], {ny, nx}});
        }
      }
      
    } else {
      for(auto& from : point[i - 1]) {
        for(auto& to : point[i]) {
         cost[to.first][to.second] = min(cost[to.first][to.second], cost[from.first][from.second] + abs(from.first - to.first) + abs(from.second - to.second));
        }
      }
    }
  }

  for(auto& to : point[P]) {
    ret = min(ret, cost[to.first][to.second]);
  }
  printf("%I64d\n", ret);
}