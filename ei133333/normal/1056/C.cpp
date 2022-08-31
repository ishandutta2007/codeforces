#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;

  cin >> N >> M;
  vector< int > p(2 * N);
  vector< int > other(2 * N, -1);
  for(int i = 0; i < 2 * N; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    other[x] = y;
    other[y] = x;
  }
  int T;
  cin >> T;
  vector< int > used(2 * N);
  if(T == 1) {

    for(int i = 0; i < N; i++) {
      int select = -1;
      for(int j = 0; j < 2 * N; j++) {
        if(used[j]) continue;
        if(~other[j] && p[other[j]] < p[j]) select = j;
      }
      if(select == -1) {
        for(int j = 0; j < 2 * N; j++) {
          if(used[j]) continue;
          if(select == -1 || p[j] > p[select]) select = j;
        }
      }
      cout << select + 1 << endl;
      used[select] = true;
      int x;
      cin >> x;
      --x;
      used[x] = true;
    }

  } else {


    for(int i = 0; i < N; i++) {
      int x;
      cin >> x;
      --x;
      used[x] = true;

      if(~other[x] && !used[other[x]]) {
        cout << other[x] + 1 << endl;
        used[other[x]] = true;

      } else {
        int select = -1;
        for(int j = 0; j < 2 * N; j++) {
          if(used[j]) continue;
          if(~other[j] && p[other[j]] < p[j]) select = j;
        }
        if(select == -1) {
          for(int j = 0; j < 2 * N; j++) {
            if(used[j]) continue;
            if(select == -1 || p[j] > p[select]) select = j;
          }
        }
        cout << select + 1 << endl;
        used[select] = true;
      }
    }


  }
}