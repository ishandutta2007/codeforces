#include<bits/stdc++.h>

using namespace std;

int main()
{
  int W, H;
  string S[100];

  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
  }

  int sx[3] = {111, 111, 111};
  int sy[3] = {111, 111, 111};
  int gx[3] = {-11, -11, -11};
  int gy[3] = {-11, -11, -11};
  const string temp = "RGB";

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      auto dd = temp.find(S[i][j]);
      sx[dd] = min(sx[dd], j);
      sy[dd] = min(sy[dd], i);
      gx[dd] = max(sx[dd], j);
      gy[dd] = max(gy[dd], i);
    }
  }

  for(int i = 0; i < 3; i++) {
    if(sx[i] == 111) {
      cout << "NO" << endl;
      return (0);
    }
  }

  for(int i = 0; i < 3; i++) {
    for(int j = sy[i]; j <= gy[i]; j++) {
      for(int k = sx[i]; k <= gx[i]; k++) {
        if(S[j][k] != temp[i]) {
          cout << "NO" << endl;
          return (0);
        }
      }
    }
  }

  for(int i = 0; i < 3; i++) gx[i] -= sx[i];
  for(int i = 0; i < 3; i++) gy[i] -= sy[i];

  if(gx[0] == gx[1] && gx[1] == gx[2] &&
     gy[0] == gy[1] && gy[1] == gy[2]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}