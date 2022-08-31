#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int A, B, M;
vector< pair< int, int > > g[2000];
bitset< 1000 > mask[2000];
int color[2000][2000];

void dfs(int idx, int next_color, int curr_color) {
  for(auto to : g[idx]) {
    if(color[idx][to.first] == next_color) {
      dfs(to.first, curr_color, next_color);


      mask[to.first][next_color].flip();
      mask[idx][next_color].flip();

      color[to.first][idx] = curr_color;
      color[idx][to.first] = curr_color;

      mask[to.first][curr_color].flip();
      mask[idx][curr_color].flip();

      return;
    }
  }
}


int main() {
  memset(color, -1, sizeof(color));
  cin >> A >> B >> M;
  int ret = 0;
  vector< pair< pair< int, int >, int > > tap(M);
  for(int i = 0; i < M; i++) {
    cin >> tap[i].first.first >> tap[i].first.second;
    tap[i].second = i;
  }
  random_shuffle(begin(tap), end(tap));
  for(auto &pp : tap) {
    int x, y;
    tie(x, y) = pp.first;
    int i = pp.second;

    --x, --y;
    y += A;

    ret = max< int >(ret, g[x].size() + 1);
    ret = max< int >(ret, g[y].size() + 1);
    // ret-1

    bitset< 1000 > beet = mask[x] | mask[y];

    if(beet.count() == ret) {
      int latte = 0, malta = 0;
      while(mask[x][latte]) ++latte;
      while(mask[y][malta]) ++malta;
      // x malta
      // malta
      dfs(x, malta, latte);

      mask[x][malta] = true;
      mask[y][malta] = true;

      color[x][y] = malta;
      color[y][x] = malta;

      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);

    } else {
      int c = 0;
      while(beet[c]) ++c;

      mask[x][c] = true;
      mask[y][c] = true;

      color[x][y] = c;
      color[y][x] = c;

      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);

    }

  }

  vector< int > ans(M, -1);
  for(int i = 0; i < A; i++) {
    for(auto &e : g[i]) {
      ans[e.second] = color[i][e.first] + 1;
    }
  }
  cout << ret << endl;
  for(int i = 0; i < M; i++) cout << ans[i] << " ";
  cout << endl;
}