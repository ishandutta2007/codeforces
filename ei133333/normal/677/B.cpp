#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int N, H, K;
 
  cin >> N >> H >> K;

  deque < int > A;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  
  int stock = 0;
  int ret = 0;
  
  while(true) {
    while(!A.empty()) {
      auto p = A.begin();
      if(stock + *p <= H) {
        stock += *p;
        A.pop_front();
      } else {
        break;
      }
    }

    int which = stock / K;
    ret += which;
    stock -= which * K;
    
    if(A.empty()) break;
    
    if(stock + *A.begin() > H) {
      ++ret;
      stock = 0;
    }
  }
  
  cout << ret + (stock != 0) << endl;
}