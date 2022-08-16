#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;
  int64 A[300000], B[300000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
  scanf("%d", &M);
  for(int i = 0; i < M; i++) scanf("%lld", &B[i]);

  if(accumulate(A, A + N, 0LL) != accumulate(B, B + M, 0LL)) {
    puts("-1");
    return 0;
  }

  int x = 0, y = 0, z = 0;
  while(x < N || y < M) {
    int64 add1 = A[x++], add2 = 0;
    while(add1 != add2) {
      if(add1 < add2) add1 += A[x++];
      else add2 += B[y++];
    }
    ++z;
  }
  printf("%d\n", z);
}