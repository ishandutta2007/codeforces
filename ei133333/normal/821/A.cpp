#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  int mat[50][50];

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> mat[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(mat[i][j] == 1) continue;
      bool flag = false;
      for(int k = 0; k < N; k++) {
        for(int l = 0; l < N; l++) {
          if(mat[i][j] == mat[i][k] + mat[l][j]) {
            flag = true;
          }
        }
      }
      if(!flag) {
        cout << "No" << endl;
        return(0);
      }
    }
  }

  cout << "Yes" << endl;
}