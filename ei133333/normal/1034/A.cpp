#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int LIM = 15000006;

int main() {
  int N, A[300000];
  int div[LIM + 1];
  for(int i = 1; i <= LIM; i++) {
    div[i] = i;
  }
  for(int i = 2; i <= LIM; i++) {
    if(div[i] == i) {
      for(int j = i + i; j <= LIM; j += i) div[j] = i;
    }
  }

  scanf("%d", &N);
  int gcd = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    gcd = __gcd(gcd, A[i]);
  }
  int beet[LIM + 1], add[LIM + 1] = {};
  memset(beet, -1, sizeof(beet));

  for(int i = 0; i < N; i++) {
    A[i] /= gcd;
    while(A[i] > 1) {
      if(beet[div[A[i]]] != i) {
        beet[div[A[i]]] = i;
        add[div[A[i]]]++;
      }
      A[i] /= div[A[i]];
    }
  }
  int ret = 1 << 30;
  for(int i = 2; i <= LIM; i++) {
    if(add[i] >= 1) ret = min(ret, N - add[i]);
  }
  if(ret == (1 << 30)) ret = -1;
  printf("%d\n", ret);
}