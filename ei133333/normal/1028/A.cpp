#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;
  string S[115];

  cin >> N >> M;
  int sx = 1333, sy = 1333, gx = -1333, gy = -1333;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    for(int j = 0; j < M; j++) {
      if(S[i][j] == 'B') {
        sx = min(sx, j);
        sy = min(sy, i);
        gx = max(gx, j);
        gy = max(gy, i);
      }
    }
  }

  cout << (sy + gy + 2) / 2 << " " << (sx + gx + 2) / 2 << endl;
}