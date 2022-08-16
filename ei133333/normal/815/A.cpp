#include<bits/stdc++.h>

using namespace std;

int main()
{
  int H, W;
  int mat[100][100];
  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) cin >> mat[i][j];
  }

  vector< string > dump;
  for(;;) {
    int latte = -1, malta = -1;
    for(int i = 0; i < H; i++) {
      bool flag = true;
      for(int j = 0; j < W; j++) flag &= mat[i][j] > 0;
      if(flag) latte = i;
    }
    for(int i = 0; i < W; i++) {
      bool flag = true;
      for(int j = 0; j < H; j++) flag &= mat[j][i] > 0;
      if(flag) malta = i;
    }
    if(latte == -1 && malta == -1) break;
    if(latte == -1) {
      for(int j = 0; j < H; j++) mat[j][malta]--;
      dump.emplace_back("col " + to_string(malta + 1));
    } else if(malta == -1) {
      for(int j = 0; j < W; j++) mat[latte][j]--;
      dump.emplace_back("row " + to_string(latte + 1));
    } else if(H > W) {
      for(int j = 0; j < H; j++) mat[j][malta]--;
      dump.emplace_back("col " + to_string(malta + 1));
    } else {
      for(int j = 0; j < W; j++) mat[latte][j]--;
      dump.emplace_back("row " + to_string(latte + 1));
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(mat[i][j] > 0) {
        cout << -1 << endl;
        return(0);
      }
    }
  }

  cout << dump.size() << endl;
  for(auto& s : dump) {
    cout << s << endl;
  }
}