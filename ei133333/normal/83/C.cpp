#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int mod = 1e9 + 7;
const int INF = 1 << 30;

const int vy[] = {0, 1, 0, -1}, vx[] = {1, 0, -1, 0};


int main()
{

  int H, W, K;
  string S[50];
  int sy, sx, gy, gx;
  set< int > v[50][50] = {{}};

  cin >> H >> W >> K;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == 'S') sy = i, sx = j;
      if(S[i][j] == 'T') gy = i, gx = j;
    }
  }


  typedef tuple< string, int, int, int > Q;
  priority_queue< Q, vector< Q >, greater<> > que[2501];
  que[0].emplace("", sy, sx, 0);
  v[sy][sx].emplace(0);
  int last[50][50];
  memset(last, -1, sizeof(last));

  for(int z = 0; z < 2500; z++) {
    while(!que[z].empty()) {
      string s;
      int y, x, bit;
      tie(s, y, x, bit) = que[z].top();
      que[z].pop();
      if(y == gy && x == gx) {
        cout << s << endl;
        return (0);
      }
      vector< char > cc;
      for(int i = 0; i < 4; i++) {
        int ny = y + vy[i], nx = x + vx[i];
        if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        int beet = bit;
        if(islower(S[ny][nx])) {
          beet |= 1 << (S[ny][nx] - 'a');
          if(__builtin_popcount(beet) > K) continue;
          s.push_back(S[ny][nx]);
        }
        if(!v[ny][nx].count(beet)) {
          if(~last[ny][nx] && (last[ny][nx] & beet) == last[ny][nx]) {
          } else {
            last[ny][nx] = beet;
            v[ny][nx].emplace(beet);
            que[z + 1].emplace(s, ny, nx, beet);
          }
        }
        if(islower(S[ny][nx])) s.pop_back();

      }
    }
  }

  cout << -1 << endl;
}