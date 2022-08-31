#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, C[100000];
  bool v[100000] = {};

  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  long long all = accumulate(C, C + N, 0LL);
  long long ret = 0;
  for(int i = 0; i < N; i++) {
    ret += 1LL * C[i] * C[(i + 1) % N];
  }

  while(K--) {
    int K;
    scanf("%d", &K);
    if(!v[--K]++) all -= C[K];
    long long rev = all;
    if(!v[(K + 1) % N]) rev -= C[(K + 1) % N];
    if(!v[(K + N - 1) % N]) rev -= C[(K + N - 1) % N];
    ret += rev * C[K];
  }
  printf("%I64d\n", ret);
}