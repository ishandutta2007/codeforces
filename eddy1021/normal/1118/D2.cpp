#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, m, a[N];
int main(){
  scanf("%lld%lld", &n, &m);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);
  sort(a, a+n);
  reverse(a, a+n);
  if(accumulate(a, a+n, 0LL) < m){
    puts("-1");
    exit(0);
  }
  auto okay = [&](LL day){
    LL gt=0;
    for(int i=0; i<n; i++)
      gt+=max(0LL, a[i]-i/day);
    return gt >= m;
  };
  LL bl=1, br=n, ba=br;
  while(bl <= br){
    LL bmid=(bl+br)>>1;
    if(okay(bmid)) ba=bmid, br=bmid-1;
    else bl=bmid+1;
  }
  printf("%lld\n", ba);
}