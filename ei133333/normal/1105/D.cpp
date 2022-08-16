#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};

int main() {
  int N, M, P, speed[9];
  string S[1000];
  cin >> N >> M >> P;
  for(int i = 0; i < P; i++) cin >> speed[i];
  for(int i = 0; i < N; i++) cin >> S[i];


  vector< pair< int, int > > rest[10];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(isdigit(S[i][j])) {
        S[i][j] -= '1';
        rest[S[i][j]].emplace_back(i, j);
      }
    }
  }

  bool update = true;
  while(update) {
    vector< pair< int, int > > rest2[10];
    update = false;
    for(int i = 0; i < P; i++) {
      queue< pair< int, int > > que1;
      for(auto &p : rest[i]) que1.emplace(p.first, p.second);
      for(int p = 0; p < speed[i] && que1.size(); p++) {

        queue< pair< int, int > > que2;
        while(que1.size()) {
          auto q = que1.front();
          que1.pop();
          for(int j = 0; j < 4; j++) {
            int ny = q.first + vy[j], nx = q.second + vx[j];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(S[ny][nx] != '.') continue;
            S[ny][nx] = i;
            update = true;
            que2.emplace(ny, nx);
          }
        }
        que1.swap(que2);
      }

      while(que1.size()) {
        auto q = que1.front();
        que1.pop();
        bool f = false;
        for(int j = 0; j < 4; j++) {
          int ny = q.first + vy[j], nx = q.second + vx[j];
          if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
          if(S[ny][nx] != '.') continue;
          f = true;
        }
        if(f) rest2[S[q.first][q.second]].emplace_back(q.first, q.second);
      }
    }
    swap(rest, rest2);
  }

  vector< int > ans(10);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(S[i][j] == '#') continue;
      if(S[i][j] == '.') continue;
      ans[S[i][j]]++;
    }
  }

  for(int i =0 ; i < P; i++) cout << ans[i] << " ";
  cout << endl;

}