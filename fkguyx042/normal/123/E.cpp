#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,size[N],vis[N],Q[N],x,y,fa[N],tot;
vector<int>v[N];
double xc[N],yc[N],be[N],sum[N],ed[N],ans,A[N],B[N],C[N],D[N];
void dfs(int x)
{
   int i; vis[x]=1;
   for (i=0;i<(int)v[x].size();++i)
   {
   	    int p=v[x][i];
   	    if (vis[p]) continue;
   	    fa[p]=x;
   	    dfs(p);
   	    size[x]+=size[p];
   	    be[x]+=be[p];
   	    ed[x]+=ed[p];
   }
   be[x]+=xc[x];
   ed[x]+=yc[x];
   size[x]++;
   sum[x]=2*size[x];
   tot=0; double Sum=0,Su=0,S=0;
   for (i=0;i<(int)v[x].size();++i) if (v[x][i]!=fa[x]) 
   {
   	     ++tot; A[tot]=sum[v[x][i]]; B[tot]=be[v[x][i]]; C[tot]=-A[tot]*B[tot]; D[tot]=ed[v[x][i]];
   	     Sum+=A[tot]; Su+=B[tot]; S+=C[tot];
   }
   if (x!=1)
   {
   	     ++tot; A[tot]=(n-size[x])*2; B[tot]=1-be[x]; C[tot]=-A[tot]*B[tot]; D[tot]=1-ed[x];
   	     Sum+=A[tot]; Su+=B[tot]; S+=C[tot];
   }
   for (i=1;i<=tot;++i)
   {
   	   double scc=((Sum-A[i])/2.+1)*xc[x];
   	   scc+=((Sum-A[i])/2.+1)*(Su-B[i]);
   	   scc+=(S-C[i])/2.;
   	   ans+=scc*D[i];
   }
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<n;++i)
	 {
	 	  scanf("%d%d",&x,&y);
	 	  v[x].push_back(y); v[y].push_back(x);
	 }
	 for (i=1;i<=n;++i)
	   scanf("%lf%lf",&xc[i],&yc[i]),xc[0]+=xc[i],yc[0]+=yc[i];
	 for (i=1;i<=n;++i) xc[i]/=xc[0],yc[i]/=yc[0];
	 dfs(1);
	 printf("%.10lf\n",ans);
}