#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N;
  string S[50];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> S[i];

  vector< pair< int, int > > beet;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) if(S[i][j] == 'o') beet.emplace_back(i, j);
  }

  if(beet.empty()) {
    cout << "NO" << endl;
    return (0);
  }

  string T[100];
  for(int i = 0; i < 2 * N - 1; i++) T[i] = string(2 * N - 1, '.');
  T[N - 1][N - 1] = 'o';

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(S[i][j] == 'x') {
        bool latte = false;
        for(auto &p : beet) {
          int dy = i - p.first;
          int dx = j - p.second;
          bool malta = true;
          for(auto &q : beet) {
            int ny = q.first + dy;
            int nx = q.second + dx;
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            malta &= S[ny][nx] != '.';
          }
          if(malta) {
            latte = true;
            T[N + dy - 1][N + dx - 1] = 'x';
            break;
          }
        }
        if(!latte) {
          cout << "NO" << endl;
          return(0);
        }
      }
    }
  }

  cout << "YES" << endl;
  for(int i = 0; i < 2 * N - 1; i++) cout << T[i] << endl;
}