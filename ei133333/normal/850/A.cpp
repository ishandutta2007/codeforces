#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N, A[1000][5];

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 5; j++) scanf("%d", &A[i][j]);
  }

  int ret = N;
  bool alive[1000] = {};

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) if(i != j) for(int k = 0; k < 5; k++) A[j][k] -= A[i][k];
    int sum = 0;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      for(int k = j + 1; k < N; k++) {
        if(i == k) continue;
        sum += (A[j][0] * A[k][0] + A[j][1] * A[k][1] + A[j][2] * A[k][2] + A[j][3] * A[k][3] + A[j][4] * A[k][4]) > 0;
      }
    }
    if(sum > 0) alive[i] = true, --ret;
    for(int j = 0; j < N; j++) if(i != j) for(int k = 0; k < 5; k++) A[j][k] += A[i][k];
  }

  printf("%d\n", ret);
  for(int i = 0; i < N; i++) {
    if(!alive[i]) printf("%d\n", i + 1);
  }
}