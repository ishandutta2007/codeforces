#include <bits/stdc++.h>

using namespace std;

const int vy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int vx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

string S[4];


bool is(int x, int y)
{
  if(x < 0 || y < 0 || x >= 4 || y >= 4) return(false);
  return(S[y][x] == 'x');
}

bool isEnd()
{
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 8; k++) {
        if(is(j, i) && is(j + vx[k], i + vy[k]) && is(j + vx[k] + vx[k], i + vy[k] + vy[k])) return(true);
      }
    }
  }
  return(false);
}

int main()
{


  for(int i = 0; i < 4; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(S[i][j] == '.') {
        S[i][j] = 'x';
        if(isEnd()) {
          cout << "YES" << endl;
          return(0);
        }
        S[i][j] = '.';
      }
    }
  }
  cout << "NO" << endl;
}