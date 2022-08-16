#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 L, R, K;
  cin >> L >> R >> K;
  bool first = false;
  for(int64 k = 1; k <= 1e18; k *= K) {
    if(L <= k && k <= R) {
      if(first++) cout << " ";
      cout << (int64)k;
    }
    if(k * K / K != k) break;
  }
  if(!first) cout << -1;
  cout << endl;
}