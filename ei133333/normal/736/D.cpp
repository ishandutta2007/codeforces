#include <bits/stdc++.h>

using namespace std;

int main()
{
  int M, N, D, a[500000], b[500000];
  bitset< 4001 > matrix[2001];

  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    matrix[i][i + N] = true;
  }
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &a[i], &b[i]);
    --a[i], --b[i];
    matrix[a[i]][b[i]] = true;
  }

  for(int i = 0; i < N; i++) {
    int pos = -1;
    for(int j = i; j < N; j++) {
      if(matrix[j][i]) pos = j;
    }
    if(pos == -1) continue;
    swap(matrix[pos], matrix[i]);
    for(int j = 0; j < N; j++) {
      if(i != j && matrix[j][i] == 1) matrix[j] ^= matrix[i];
    }
  }
  for(int i = 0; i < M; i++) {
    if(!matrix[b[i]][a[i] + N]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
}