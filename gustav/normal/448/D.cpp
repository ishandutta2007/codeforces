#include <cstdio>
#include <cstring>

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;

int N, M;
llint K;

llint lt(llint n) {
  llint ret = 0;
  for (int i = 1; i <= N; ++i) 
    ret += min(n / i - (n % i == 0), (llint)M);
  return ret;
}

int main(void)
{
  cin >> N >> M >> K;
  --K;

  llint lo = 1, hi = (llint)N * M, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    if (lt(mid) > K) 
      hi = mid - 1;
    else 
      lo = mid;
  }
  
  cout << lo << endl;
  
  return 0;
}