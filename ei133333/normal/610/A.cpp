#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N;
  cin >> N;
  if(N % 2 == 1LL) {
    cout << 0 << endl;
  } else {
    int64 low = 0, high = 1LL << 40;
    while(high - low > 0) {
      int64 mid = (low + high + 1) >> 1LL;
      if(mid + mid + mid + mid >= N) high = mid - 1;
      else low = mid;
    }
    cout << low << endl;
  }
}