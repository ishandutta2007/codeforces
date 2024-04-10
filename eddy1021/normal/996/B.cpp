#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
LL n, a[N], b[N];
int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++)
    scanf("%lld", &a[i]);
  int ans=0;
  for(int i=0; i<n; i++){
    LL bl=0, br=1e9, ba=0;
    while(bl <= br){
      LL bmid=(bl+br)>>1;
      if(a[i]<=i+n*bmid) ba=bmid, br=bmid-1;
      else bl=bmid+1;
    }
    b[i]=ba;
    if(b[i]<b[ans]) ans=i;
  }
  printf("%d\n", ans+1);
}