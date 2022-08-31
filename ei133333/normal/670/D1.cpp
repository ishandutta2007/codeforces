#include <bits/stdc++.h>
using namespace std;
typedef long long int64;


int64 N, K, A[100000], B[100000];

bool calc(int64 mid)
{
  int64 dec = K;
  for(int i = 0; i < N; i++) {
    if(mid * A[i] > B[i]) {
      dec -= mid * A[i] - B[i];
      if(dec < 0) return(false);
    }
  }
  return(true);
}

int main()
{
  scanf("%I64d %I64d", &N, &K);
  for(int i = 0; i < N; i++) {
    scanf("%I64d", &A[i]);
  }
  for(int i = 0; i < N; i++) {
    scanf("%I64d", &B[i]);
  }
  int64 low = 0, high = 1LL << 31;
  while(high - low > 0) {
    int64 mid = (low + high + 1) / 2;
    if(calc(mid)) low = mid;
    else high = mid - 1;
  }
  printf("%I64d\n", low);
}