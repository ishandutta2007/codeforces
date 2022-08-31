#include <bits/stdc++.h>

using namespace std;

int N, X[300000];

long long get(int p)
{
  long long sum = 0;
  for(int i = 0; i < N; i++) {
    sum += llabs((long long)p - X[i]);
  }
  return(sum);
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", &X[i]);
  }
  sort(X, X + N);

  if(N % 2 == 1 || get(X[N / 2 - 1]) <= get(X[N / 2])) {
    printf("%d\n", X[(N + 1) / 2 - 1]);
  } else {
    printf("%d\n", X[N / 2]);
  }
}