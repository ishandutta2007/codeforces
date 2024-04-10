#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2005

using namespace std;
int i,j,m,n,p,k;
int l[N],r[N],mx[N],need[N],a[N],ans[N],vis[N];
bool check(int x)
{
	 memset(need,0,sizeof(need));
	 memset(a,0,sizeof(a));
	 memset(vis,0,sizeof(vis));
	 for (i=1;i<=n;++i) mx[i]=n,need[n]++;
	 for (i=1;i<=n;++i)
	 {
	 	  for (j=i;j<=n;++j) if (need[j]>j-i+1) return 0;
	 	  for (j=i;j<=n;++j) if (need[j]==j-i+1) break;
	 	  int id=0;
	 	  for (k=1;k<=n;++k) if (!vis[k]&&mx[k]<=j&&(!id||r[id]>r[k])) id=k;
	 	  a[i]=id; vis[id]=1;
	 	  for (k=mx[id];k<=n;++k) need[k]--;
	 	  for (j=1;j<=n;++j)
	 	    if (!vis[j]&&max(l[j],l[id])<=min(r[j],r[id])&&mx[j]==n)
	 	  {
	 	  	   mx[j]=min(i+x,n);
	 	  	   for (k=mx[j];k<n;++k) need[k]++;
	 	  }
	 }
	 return 1;
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]);
	 int l=0,r=n,mid=0;
	 while ((l+r)>>1!=mid)
	{
		mid=(l+r)>>1;
		if (check(mid)) 
		{
		  r=mid; for (i=1;i<=n;++i) ans[i]=a[i];
	    }
		else l=mid;
    }
    for (i=1;i<=n;++i) printf("%d ",ans[i]);
}