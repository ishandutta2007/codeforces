#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, K;
  cin >> N >> K;

  int mat[100][100] = {{}};
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(mat[i][j]) continue;
      if(i == j && K > 0) {
        K--;
        mat[i][j] = true;
      } else if(K > 1) {
        K -= 2;
        mat[i][j] = mat[j][i] = true;
      }
    }
  }
  if(K == 0) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << -1 << endl;
  }
}