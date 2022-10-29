#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005

using namespace std;
const int inf=(int)1e9+7;
int Rp[N],f[N],last[N],vis[N],Ans[N],id[N],sum[N];
int i,j,m,n,p,k,a[N],b[N],c[N],rid;
bool check(int st,int ed)
{
	  return (sum[a[ed]-1]-sum[a[st]]>=f[ed]-f[st]-1);
}
int main()
{
	  scanf("%d",&n);
	  a[1]=-inf;
	  for (i=2;i<=n+1;++i) 
	  {
	     scanf("%d",&a[i]);
	     if (a[i]!=-1) c[++c[0]]=a[i];
	  }
	  a[n+2]=inf; n+=2; c[++c[0]]=-inf; c[++c[0]]=inf;
	  scanf("%d",&m);
	  for (i=1;i<=m;++i)
	  {
	  	scanf("%d",&b[i]);
	  	c[++c[0]]=b[i];
	  }
	  sort(c+1,c+c[0]+1);
	  c[0]=unique(c+1,c+c[0]+1)-(c+1);
	  memset(id,60,sizeof(id)); id[0]=0;
	  for (i=1;i<=n;++i)
	    if (a[i]!=-1) a[i]=lower_bound(c+1,c+c[0]+1,a[i])-c;
	  for (i=1;i<=m;++i)
	    b[i]=lower_bound(c+1,c+c[0]+1,b[i])-c;
	  sort(b+1,b+m+1);
	  for (i=1;i<=m;++i) sum[b[i]]=1;
	  for (i=1;i<=c[0];++i) sum[i]+=sum[i-1];
	  int L=0;
	  for (i=1;i<=n;++i)
	    if (a[i]!=-1)
	    {
	    	   int l=0,r=L+1,mid=0;
	    	   for (;(l+r)>>1!=mid;)
	    	   {
	    	   	  mid=(l+r)>>1;
	    	   	  if (Rp[mid]<a[i]) l=mid; else r=mid;
	    	   }
	    	   if (l==L) ++L;
	    	   Rp[l+1]=a[i]; id[l+1]=i;
	    	   f[i]=l+1; last[i]=id[l];
	    }
	    else 
	    {
	    	  int l=L;
	    	  for (j=m;j;--j)
	    	  {
	    	      while (Rp[l]>=b[j]) --l;
	    	      if (l==L) ++L;
	    	      Rp[l+1]=b[j]; id[l+1]=i;
	    	  }
	    }
	    int rel=m;
	    for (rid=n;rid;)
	    	 if (a[last[rid]]!=-1) rid=last[rid];
	    	 else 
	    	 {
	    	 	  int sum=0;
	    	 	  for (j=last[rid];j;--j)
	    	 	    if (a[j]==-1) ++sum;
	    	 	    else  if (a[j]<a[rid]&&sum>=f[rid]-f[j]-1&&check(j,rid)) 
	    	 	    {
	    	 	    	   while (b[rel]>=a[rid]) --rel;
	    	 	    	   for (k=last[rid],sum=f[rid]-f[j]-1;k&&sum;--k)
	    	 	    	      if (a[k]==-1) 
							   {
							   	   while (rel&&b[rel]==b[rel+1]) --rel;
							       vis[rel]=1,Ans[k]=b[rel],--sum,--rel;
							   }
	    	 	    	   break;
	    	 	    }
	    	 	    rid=j;
	    	 }
	    for (i=2;i<n;++i) if (a[i]!=-1) printf("%d ",c[a[i]]);
	    else  if (Ans[i]) printf("%d ",c[Ans[i]]);
	    else  for (j=1;j<=m;++j) if (!vis[j]) { printf("%d ",c[b[j]]); vis[j]=1; break; }
}