#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 calc(int64 limit)
{
  int64 poyo = 0;
  for(int64 alpha = 2; alpha < 1000000; alpha++) {
    int64 sign = alpha * alpha * alpha;
    // a^3k <= limit  sign
    poyo += limit / sign;
  }
  return(poyo);
}

int main()
{
  int64 M;
  cin >> M;

  // k + k + ^2k + ^3k (k  1,  > 1)
  // k(1 + a + a^2 + a^3)

  int64 low = 0, high = 1e+16;
  while(high - low > 0) {
    int64 mid = (low + high) / 2;
    if(calc(mid) >= M) high = mid;
    else               low  = mid + 1;
  }
  if(calc(low) == M) {
    cout << low << endl;
  } else {
    cout << -1 << endl;
  }
}