#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, Q, M, A[200000];
int T[200000], L[200000], R[200000];

int main()
{
  scanf("%d %d %d", &N, &Q, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < Q; i++) {
    scanf("%d %d %d", &T[i], &L[i], &R[i]);
    --L[i], --R[i];
  }
  while(M--) {
    int X;
    scanf("%d", &X);
    --X;
    for(int i = Q - 1; i >= 0; i--) {
      if(L[i] <= X && X <= R[i]) {
        if(T[i] == 1) {
          if(X == L[i]) X = R[i];
          else X--;
        } else {
          X = R[i] + L[i] - X;
        }
      }
    }
    printf("%d ", A[X]);
  }
  putchar('\n');
}