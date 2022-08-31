#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);

  long long V = 1LL;
  while(N--) {
    int C;
    scanf("%d", &C);
    long long A = __gcd(C, K);
    long long B = __gcd(V, A);
    V *= A / B;
  }
  puts(V == K ? "Yes" : "No");
}