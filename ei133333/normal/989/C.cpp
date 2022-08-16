#include <bits/stdc++.h>

using namespace std;

int main() {
  int V[4];
  for(int i = 0; i < 4; i++) {
    cin >> V[i];
    --V[i];
  }

  int t[50][50];
  for(int i = 0; i < 50; i++) {
    for(int j = 0; j < 50; j++) {
      if(i < 25 && j < 25) t[i][j] = 0;
      else if(i < 25) t[i][j] = 1;
      else if(j < 25) t[i][j] = 2;
      else t[i][j] = 3;
    }
  }
  int sub = 0;
  for(int i = 1; i < 50; i += 2) {
    if(i == 25) ++i;
    for(int j = 1; j < 50; j += 2) {
      if(j == 25) ++j;
      ++sub;

      for(int k = 0; k < 4; k++) {
        if(t[i - 1][j] == k) continue;
        if(V[k] > 0) {
          --V[k];
          t[i][j] = k;
          break;
        }
      }

    }
  }
  string x = "ABCD";
  cout << 50 << " " << 50 << endl;
  for(int i = 0; i < 50; i++) {
    for(int j = 0; j < 50; j++) {
      cout << x[t[i][j]];
    }
    cout << endl;
  }
}