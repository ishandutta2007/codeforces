#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int Q;
int S[1000001][10];

int f(int n)
{
  int mul = 1;
  while(n > 0) {
    if(n % 10 != 0) {
      mul *= n % 10;
    }
    n /= 10;
  }
  return (mul);
}

int g(int n)
{
  if(n < 10) return (n);
  return (g(f(n)));
}

int main()
{
  for(int i = 1; i <= 1000000; i++) {
    ++S[i][g(i)];
  }
  for(int i = 1; i <= 1000000; i++) {
    for(int j = 0; j < 10; j++) {
      S[i][j] += S[i - 1][j];
    }
  }
  scanf("%d", &Q);
  while(Q--) {
    int L, R, K;
    scanf("%d %d %d", &L, &R, &K);
    printf("%d\n", S[R][K] - S[L - 1][K]);
  }
}