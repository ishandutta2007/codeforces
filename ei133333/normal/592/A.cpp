#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string S[8];


  for(int i = 0; i < 8; i++) {
    cin >> S[i];
  }

  int latte = 10, malta = 10;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(S[i][j] == 'W') {
        bool f = true;
        for(int k = i - 1; k >= 0; k--) {
          f &= S[k][j] == '.';
        }
        if(f) latte = min(latte, i);
      } else if(S[i][j] == 'B') {
        bool f = true;
        for(int k = i + 1; k < 8; k++) {
          f &= S[k][j] == '.';
        }
        if(f) malta = min(malta, 7 - i);
      }
    }
  }

  if(latte <= malta) cout << "A\n";
  else cout << "B\n";
}