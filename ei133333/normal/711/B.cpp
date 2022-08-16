#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, X[500][500];
  int x, y;

  cin >> N;

  if(N == 1) {
    cout << 1 << endl;
    return (0);
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> X[i][j];
      if(X[i][j] == 0) {
        x = j, y = i;
      }
    }
  }

  int64 val, sum;
  bool zero;

  for(int i = 0; i < N; i++) {
    zero = false;
    sum = 0;
    for(int j = 0; j < N; j++) {
      sum += X[i][j];
      zero |= X[i][j] == 0;
    }
    if(!zero) val = sum;
  }

  int64 curr = 0;
  for(int i = 0; i < N; i++) {
    curr += X[y][i];
  }

  if(val - curr <= 0) {
    cout << -1 << endl;
    return(0);
  }

  X[y][x] = val - curr;

  for(int i = 0; i < N; i++) {
    sum = 0;
    for(int j = 0; j < N; j++) {
      sum += X[i][j];
    }
    if(sum != val) {
      cout << -1 << endl;
      return(0);
    }
  }

  for(int i = 0; i < N; i++) {
    sum = 0;
    for(int j = 0; j < N; j++) {
      sum += X[j][i];
    }
    if(sum != val) {
      cout << -1 << endl;
      return(0);
    }
  }

  sum = 0;
  for(int i = 0; i < N; i++) {
    sum += X[i][i];
  }
  if(sum != val) {
    cout << -1 << endl;
    return(0);
  }

  sum = 0;
  for(int i = 0; i < N; i++) {
    sum += X[i][N - i - 1];
  }
  if(sum != val) {
    cout << -1 << endl;
    return(0);
  }
  cout << X[y][x] << endl;
}