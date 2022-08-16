#include<bits/stdc++.h>
using namespace std;
signed main()
{
  int H, W;
  scanf("%d %d", &H, &W);
  bool mas[500][500] = {{}};
  for(int i = 0; i < H; i++) {
    string S;
    cin >> S;
    for(int j = 0; j < W; j++) {
      mas[i][j] = S[j] == '.';
    }
  }

  int yoko[501][501] = {{}}, tate[501][501] = {{}};
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W - 1; j++) {
      if(mas[i][j] && mas[i][j + 1]) yoko[i + 1][j + 1]++;
      yoko[i + 1][j + 1] += yoko[i + 1][j];
    }
  }
  for(int i = 0; i < W; i++) {
    for(int j = 0; j < H - 1; j++) {
      if(mas[j][i] && mas[j + 1][i]) tate[i + 1][j + 1]++;
      tate[i + 1][j + 1] += tate[i + 1][j];
    }
  }

  int Q;
  scanf("%d", &Q); // O(10^8)
  while(Q--) {
    int r1, r2, c1, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    int ret = 0;
    for(int i = r1; i <= r2; i++) {
      ret += yoko[i][c2 - 1] - yoko[i][c1 - 1];
    }
    for(int i = c1; i <= c2; i++) {
      ret += tate[i][r2 - 1] - tate[i][r1 - 1];
    }
    printf("%d\n", ret);
  }
}