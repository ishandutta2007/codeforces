#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;

  // d (km):           5
  // k (km):   2
  // a:                  1
  // b:                 4
  // t(s)          10

  auto calc = [&](int64 value) // value: 
  {
    int64 carDist = min(d, value * k);
    int64 carTime = max(0LL, t * (value - 1) + carDist * a);
    int64 walkTime = (d - carDist) * b;
    return(carTime + walkTime);
  };

  int64 low = 0, high = (d + k - 1) / k + 1;
  while(high - low > 1) {
    int64 mid = (low + high) / 2;
    if(calc(mid) - calc(mid - 1) < 0) low = mid;
    else high = mid;
  }
  cout << calc(low) << endl;
}