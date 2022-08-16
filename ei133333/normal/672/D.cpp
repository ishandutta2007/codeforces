#include<bits/stdc++.h>
using namespace std;
typedef long long int64;


int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  
  map< int64, int64 > mp;
  
  for(int i = 0; i < N; i++) {
    int c;
    scanf("%d", &c);
    mp[c]++;
  }

 
  while(K > 0 && (--mp.end()) -> first - mp.begin() -> first > 1) {
    auto small = *mp.begin();
    auto small2 = *++mp.begin();

    auto big   = *--mp.end();
    auto big2  = *(--(--mp.end()));

    int64 distsmall = small2.first - small.first;
    int64 distbig   = big.first - big2.first;
    
    int64 count_sum = min((int64)K, min(distsmall * small.second, distbig * big.second));
    if(small == big2) count_sum /= 2;
    
    int64 nextSmallUp = count_sum / small.second;
    int64 nextBigDown = count_sum / big.second;
    
    int64 nextSmallUpUp_count = count_sum % small.second;
    int64 nextBigDownDown_count = count_sum % big.second;
    
    K -= count_sum;
    
    mp.erase(mp.begin());
    mp.erase(--mp.end());
    
    mp[small.first + nextSmallUp] += small.second - nextSmallUpUp_count;
    if(nextSmallUpUp_count > 0) mp[small.first + nextSmallUp + 1] += nextSmallUpUp_count;

    mp[big.first - nextBigDown] += big.second - nextBigDownDown_count;
    if(nextBigDownDown_count > 0) mp[big.first - nextBigDown - 1] += nextBigDownDown_count;
  }
  printf("%d\n", (--mp.end()) -> first - mp.begin() -> first);
}