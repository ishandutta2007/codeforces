#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=303030;
LL n, a[2][N], sa[2][N];
LL rgt[2][N], lft[2][N];
LL sum_to_rgt(int row, int li, int ri, int til){
  if(li > ri) return 0;
  LL ret=rgt[row][li]-rgt[row][ri+1];
  //LL ret=rgt[row][ri]-rgt[row][li-1];
  ret-=(n+n-til)*(sa[row][ri]-sa[row][li-1]);
  return ret;
}
LL sum_to_lft(int row, int li, int ri, int til){
  if(li > ri) return 0;
  LL ret=lft[row][ri]-lft[row][li-1];
  ret-=(n+1-til)*(sa[row][ri]-sa[row][li-1]);
  return ret;
}
int main(){
  scanf("%lld", &n);
  for(int i=0; i<2; i++)
    for(int j=1; j<=n; j++){
      scanf("%lld", &a[i][j]);
      sa[i][j]=sa[i][j-1]+a[i][j];
    }
  for(int i=0; i<2; i++)
    for(int j=n, bns=n+n; j>=1; j--, bns--)
      rgt[i][j]=rgt[i][j+1]+bns*a[i][j];
  for(int i=0; i<2; i++)
    for(int j=1, bns=n+n; j<=n; j++, bns--)
      lft[i][j]=lft[i][j-1]+bns*a[i][j];
  LL ans=0, pre=0;
  for(int i=1, bns=0; i<=n; i++, bns+=2){
    if(i&1){
      {
        LL tans=pre;
        tans+=sum_to_rgt(0, i, n, bns+n-i);
        tans+=sum_to_lft(1, i, n, bns+n-i+1);
        ans=max(ans, tans);
      }
      pre+=a[0][i]*bns;
      pre+=a[1][i]*(bns+1);
    }else{
      {
        LL tans=pre;
        tans+=sum_to_rgt(1, i, n, bns+n-i);
        tans+=sum_to_lft(0, i, n, bns+n-i+1);
        ans=max(ans, tans);
      }
      pre+=a[1][i]*bns;
      pre+=a[0][i]*(bns+1);
    }
  }
  ans=max(ans, pre);
  printf("%lld\n", ans);
}