#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  bitset< 501 > bits[501];
  bits[0].set(0);
  
  cin >> N >> K;
  while(N--) {
    int C;
    cin >> C;
    for(int i = K; i >= C; i--) {
      if(bits[i - C].any()) {
        bits[i] |= (bits[i - C] << C) | bits[i - C];
      }
    }
  }
  
  cout << bits[K].count() << endl;
  for(int i = 0; i <= K; i++) {
    if(bits[K].test(i)) cout << i << " ";
  }
  cout << endl;
}