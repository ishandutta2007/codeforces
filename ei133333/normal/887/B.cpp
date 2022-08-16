#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[3][6];

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 6; j++) {
      cin >> A[i][j];
    }
  }

  set< int > st;
  st.emplace(0);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 6; j++) {
      st.emplace(A[i][j]);
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 6; j++) {
      for(int k = 0; k < N; k++) {
        if(i == k) continue;
        for(int l = 0; l < 6; l++) {
          st.emplace(A[i][j] * 10 + A[k][l]);
        }
      }
    }
  }


  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 6; j++) {
      for(int k = 0; k < N; k++) {
        if(i == k) continue;
        for(int l = 0; l < 6; l++) {
          for(int m = 0; m < N; m++) {
            if(i == m || k == m) continue;
            for(int n = 0; n < 6; n++) {
              st.emplace(A[i][j] * 100 + A[k][l] * 10 + A[m][n]);
            }
          }
        }
      }
    }
  }


  int mid = 0;
  while(st.count(mid)) ++mid;
  cout << mid - 1 << endl;
}