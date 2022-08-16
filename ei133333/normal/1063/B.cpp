#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using pi = pair< int, int >;

const int vy[] = {-1, 0, 1, 0};
const int vx[] = {0, 1, 0, -1};

int N, M, Y, X, A, B;
string S[2000];
int v[2000][2000];

int main() {
  cin >> N >> M >> Y >> X >> A >> B;
  --Y, --X;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  memset(v, -1, sizeof(v));

  queue< pair< int, int > > que;
  que.emplace(Y, X);
  v[Y][X] = 0;
  for(int i = 0; que.size(); i++) {
    queue< pair< int, int > > next_que;
    while(que.size()) {
      auto p = que.front();
      que.pop();
      if(v[p.first][p.second] != i) continue;
      for(int j = 0; j < 4; j += 2) {
        int ny = p.first + vy[j], nx = p.second + vx[j];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(S[ny][nx] == '*') continue;
        if(v[ny][nx] == -1 || v[ny][nx] == i + 1) {
          v[ny][nx] = i;
          que.emplace(ny, nx);
        }
      }
      for(int j = 1; j < 4; j += 2) {
        int ny = p.first + vy[j], nx = p.second + vx[j];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(S[ny][nx] == '*') continue;
        if(v[ny][nx] == -1) {
          v[ny][nx] = i + 1;
          next_que.emplace(ny, nx);
        }
      }
    }
    que = next_que;
  }
  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(v[i][j] == -1) continue;
      int dist = v[i][j] - abs(X - j);
      dist >>= 1;

      int latte = 0, malta = 0;
      if(j <= X) {
        latte += dist;
        latte += X - j;
        malta += dist;
      } else { // 
        latte += dist;
        malta += dist;
        malta += j - X;
      }
      if(latte <= A && malta <= B) {
        ++ret;
      }
    }
  }
  cout << ret << endl;
}