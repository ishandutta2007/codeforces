// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
      cin >> mat[i];
    }
    int k = 0;
    vector<vector<int>> ct(2, vector<int>(3));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == '.') {
          continue;
        }
        ++ct[mat[i][j] == 'X'][(i + j) % 3];
        ++k;
      }
    }

    bool end = false;
    for (int x = 0; x < 3; ++x) {
      for (int y = 0; y < 3; ++y) {
        if (end || x == y) {
          continue;
        }
        if (ct[0][x] + ct[1][y] <= k / 3) {
          end = true;
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
              if (mat[i][j] == '.') {
                continue;
              }
              if ((i + j) % 3 == x) {
                mat[i][j] = 'X';
              }
              if ((i + j) % 3 == y) {
                mat[i][j] = 'O';
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << mat[i] << '\n';
    }
  }
}