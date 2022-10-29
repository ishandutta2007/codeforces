#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,k,Sum,A,x,l,r,Ans,mid;
int b[100001],p[100001];
inline bool cmp(int a,int b) { return a>b; }
inline int check(int x)
{  int LastA=A,i,j,Sum=0;
   for (i=x,j=1;i;i--,j++)
   {  LastA-=max(0,p[i]-b[j]);
      if (LastA<0) return -1;
      Sum+=min(p[i],b[j]);
   }
   return max(0,Sum-LastA);
}
int main()
{ scanf("%d%d%d",&n,&m,&A);
  for (i=1;i<=n;i++) scanf("%d",&b[i]);
  for (i=1;i<=m;i++) scanf("%d",&p[i]);
  sort(b+1,b+n+1,cmp);
  sort(p+1,p+m+1);
  l=0,r=min(m+1,n+1);
  for (;(l+r)>>1!=mid;)
  { mid=(l+r)>>1;
    x=check(mid);
    if (x>=0)
	 l=mid,Ans=x; else r=mid;
}
printf("%d %d\n",l,Ans);
}