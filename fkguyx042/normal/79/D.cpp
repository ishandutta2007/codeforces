#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 

#define N 20005
#define M 2000005
using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,f[M],a[N],b[N],val[N],c[N],sum[55][55],cnt,l,x,dist[N],vis[N],Q[N];
void work(int x)
{
	 memset(vis,0,sizeof(vis)); dist[x]=0;
	 Q[Q[0]=1]=x; vis[x]=1;
	 int L,i,p;
	 for (L=1;L<=Q[0];++L)
	 {
	 	  int p=Q[L];
	 	  for (i=1;i<=l;++i)
	 	  {
	 	  	  if (p+val[i]<=n&&!vis[p+val[i]]) vis[p+val[i]]=1,Q[++Q[0]]=p+val[i],dist[Q[Q[0]]]=dist[p]+1;
	 	  	  if (p-val[i]>0&&!vis[p-val[i]]) vis[p-val[i]]=1,Q[++Q[0]]=p-val[i],dist[Q[Q[0]]]=dist[p]+1;
	 	  }
	 }
	 for (i=1;i<=n;++i) if (b[i]) sum[c[x]][c[i]]=dist[i];
}
int main()
{
	 scanf("%d%d%d",&n,&k,&l); ++n;
	 for (i=1;i<=k;++i) scanf("%d",&x),a[x]++; 
	 for (i=1;i<=n;++i) { b[i]=a[i]^a[i-1]; if (b[i]) c[i]=cnt++; }
	 for (i=1;i<=l;++i) scanf("%d",&val[i]);
	 for (i=1;i<=n;++i) if (b[i]) work(i);
	 memset(f,60,sizeof(f)); 
	 f[0]=0; int Maxn=(1<<cnt);
	 for (i=0;i<Maxn;++i)
	   if (f[i]<inf)
	     for (j=0;j<cnt;++j) if (!(i&(1<<j)))
	       for (k=j+1;k<cnt;++k) if (!(i&(1<<k))&&sum[j][k])
		     f[i|(1<<j)|(1<<k)]=min(f[i|(1<<j)|(1<<k)],f[i]+sum[j][k]);
	 if (f[Maxn-1]>inf) printf("-1\n");
	 else printf("%d\n",f[Maxn-1]);
}