#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, M, K, X, Y;
  cin >> N >> M >> K >> X >> Y;

  int64 grid[105][105] = {{}};

  int64 nokori = K;

  if(N > 2) {
    int64 repeatRow = K / M;
    int64 oneLoop = N - 1;
    int64 loop = repeatRow / (oneLoop * 2);
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        if(i == 1 || i == N) grid[i][j] = loop;
        else grid[i][j] = loop * 2;
      }
    }
    nokori -= loop * oneLoop * M * 2;
  } else {
    int64 repeatRow = K / M;
    int64 oneLoop = N;
    int64 loop = repeatRow / oneLoop;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        grid[i][j] = loop;
      }
    }
    nokori -= loop * oneLoop * M;
  }

  int64 a = numeric_limits< int64 >::max(), b = 0;

  vector< pair< int, int > > vv;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) vv.emplace_back(j, i);
  }
  for(int i = N - 1; i > 1; i--) {
    for(int j = 1; j <= M; j++) vv.emplace_back(j, i);
  }

  while(nokori > 0) {
    for(auto &pp : vv) {
      grid[pp.second][pp.first]++;
      nokori--;
      if(nokori == 0) break;
    }
  }


  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      a = min(a, grid[i][j]);
      b = max(b, grid[i][j]);
    }
  }

  cout << b << " " << a << " " << grid[X][Y] << endl;
}