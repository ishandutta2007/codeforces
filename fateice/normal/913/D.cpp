#include<bits/stdc++.h>
using namespace std;
int n,w,a[200010],t[200010],l,r,m,kk[200010];
struct orz
{
    int a,b;
}x[200010];
inline bool cmp(orz a,orz b)
{
    return a.a<b.a;
}
inline bool chk(int p)
{
    if(!p)
      return 1;
    int i,j,k;
    m=0;
    for(i=1;i<=n;i++)
      if(a[i]>=p)
        {
         x[++m].a=t[i];
         x[m].b=i;
        }
    if(m>=p)
      {
       sort(x+1,x+m+1,cmp);
       for(i=1,k=0;i<=p;i++)
         {
          k+=x[i].a;
          kk[i]=x[i].b;
         }
       if(k<=w)
         return 1;
      }
    return 0;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i],&t[i]);
	for(l=0,r=n;l<r;)
	  if(chk(l+r+1>>1))
	    l=(l+r+1>>1);
	  else
	    r=(l+r+1>>1)-1;
	chk(l);
	printf("%d\n%d\n",l,l);
	for(i=1;i<=l;i++)
	  printf("%d ",kk[i]);
	return 0;
}