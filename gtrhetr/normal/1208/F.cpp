#include <bits/stdc++.h>
#define FR first
#define SE second
 
using namespace std;
 
typedef pair<int,int> pr;
 
inline pr merge(pr x,pr y) {
  int u=max(x.FR,y.FR),v=max(x.SE,y.SE);
  if (x.FR<u) v=max(x.FR,v);
  if (y.FR<u) v=max(y.FR,v);
  return pr(u,v);
}
 
pr a[1<<21];
 
void fwt1(int len) {
  for(int i=1;i<len;i<<=1)
    for(int j=0;j<len;j++)
      if (j&i) a[j^i]=merge(a[j^i],a[j]);
}
 
int b[1<<21];
 
void fwt2(int len) {
  for(int i=1;i<len;i<<=1)
    for(int j=0;j<len;j++)
      if (j&i) b[j^i]=max(b[j^i],b[j]);
}
 
int num[1000005];
 
int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
    scanf("%d",&num[i]);
    a[num[i]]=merge(a[num[i]],pr(i,0));
  }
  fwt1(1<<21);
  for(int i=0;i<(1<<21);i++) b[i]=a[i].SE;
  int ans=0;
  for(int i=1;i<n-1;i++) {
  	int s=num[i];
  	for(int j=20;j>=0;j--)
  	  if (!((s>>j)&1)&&b[s^num[i]^(1<<j)]>i) s^=(1<<j);
  	ans=max(ans,s);
  }
  printf("%d\n",ans);
  return 0;
}