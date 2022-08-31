#include<bits/stdc++.h>

using namespace std;

const int vy[] = {1, 0, -1, 0};
const int vx[] = {0, 1, 0, -1};


int main()
{
  int H, W;
  string S[100];

  cin >> H >> W;
  int sy, sx;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == 'S') {
        sy = i;
        sx = j;
      }
    }
  }

  string d;
  cin >> d;

  vector< int > order{0, 1, 2, 3};
  int ret = 0;
  do {
    int y = sy, x = sx;
    for(auto c : d) {
      c -= '0';
      y += vy[order[c]];
      x += vx[order[c]];
      if(y < 0 || x < 0 || y >= H || x >= W) break;
      if(S[y][x] == '#') break;
      if(S[y][x] == 'E') {
        ++ret;
        break;
      }
    }
  } while(next_permutation(begin(order), end(order)));
  cout << ret << endl;
}