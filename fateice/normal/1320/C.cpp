#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,f[4000010],g[4000010],p=1048576,ans=-2e9;
struct orz
{
    int p,a,b,c;
}x[400010];
inline bool cmp(orz a,orz b)
{
    return a.b<b.b || a.b==b.b && a.p<b.p;
}
inline void add(int i,int j,int k,int p,int x)
{
    if(j>=p)
      f[i]+=x,g[i]+=x;
    else
      {
       g[i<<1]+=g[i],f[i<<1]+=g[i];
       g[i<<1|1]+=g[i],f[i<<1|1]+=g[i];
       g[i]=0;
       add(i<<1|1,(j+k>>1)+1,k,p,x);
       if(p<=(j+k>>1))
         add(i<<1,j,j+k>>1,p,x);
       f[i]=max(f[i<<1],f[i<<1|1]);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&m,&t);
	f[p+p-1]=-2e9;
	for(i=1;i<=n;i++)
	  {
       scanf("%d%d",&j,&k);
       if(!f[p+j-1] || f[p+j-1]<-k)
         f[p+j-1]=-k;
      }
    for(i=p+p-2;i>=p;i--)
      if(!f[i] || f[i+1]>f[i])
        f[i]=f[i+1];
    for(i=p-1;i>0;i--)
      f[i]=max(f[i<<1],f[i<<1|1]);
	for(i=1;i<=m;i++)
	  scanf("%d%d",&x[i].b,&x[i].c),x[i].p=1;
	for(i=1;i<=t;i++)
	  scanf("%d%d%d",&x[i+m].a,&x[i+m].b,&x[i+m].c),x[i+m].p=2;
	sort(x+1,x+m+t+1,cmp);
	for(i=1;i<=m+t;i++)
	  if(x[i].p==1)
	    ans=max(ans,f[1]-x[i].c);
	  else
	    add(1,1,p,x[i].a+1,x[i].c);
	cout<<ans;
	return 0;
}