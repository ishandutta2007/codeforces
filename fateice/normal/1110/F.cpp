#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,p,r[500010];
L f[2000010],g[2000010],w[500010];
vi a[500010],b[500010],c[500010],d[500010],e[500010];
int j,k,v;
inline void dfs(int i,L u)
{
    while(1)
    {
    if(k!=i)
      {
       if(a[i].size()==0)
         f[p+i-1]=u;
       else
         f[p+i-1]=1e18;
       r[i]=j-1;
       return;
      }
    a[i].pb(j);
    b[i].pb(v);
    L l=v;
    j++;
    if(j>n)
      k=0;
    else
      scanf("%d%d",&k,&v);
    dfs(j-1,u+l);
    }
}
inline void down(int i)
{
    g[i<<1]+=g[i];
    f[i<<1]+=g[i];
    g[i<<1|1]+=g[i];
    f[i<<1|1]+=g[i];
    g[i]=0;
}
inline void add(int i,int j,int k,int l,int r,int p)
{
    //if(i==1)
    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<r<<" "<<p<<" "<<f[i]<<"\n";
    if(l<=j && k<=r)
      {
       g[i]+=p;
       f[i]+=p;
      }
    else
      {
       down(i);
       if(l<=(j+k>>1))
         add(i<<1,j,j+k>>1,l,r,p);
       if(r>(j+k>>1))
         add(i<<1|1,(j+k>>1)+1,k,l,r,p);
       f[i]=min(f[i<<1],f[i<<1|1]);
      }
}
inline L minn(int i,int j,int k,int l,int r)
{
    if(l<=j && k<=r)
      return f[i];
    else
      {
       down(i);
       L p=1e18;
       if(l<=(j+k>>1))
         p=minn(i<<1,j,j+k>>1,l,r);
       if(r>(j+k>>1))
         p=min(p,minn(i<<1|1,(j+k>>1)+1,k,l,r));
       return p;
      }
}
inline void dfs2(int i)
{
    //cout<<i<<" "<<r[i]<<"!!\n";
    int j;
    for(j=0;j<c[i].size();j++)
      w[c[i][j]]=minn(1,1,p,d[i][j],e[i][j]);
    for(j=0;j<a[i].size();j++)
      {
       add(1,1,p,1,n,b[i][j]);
       add(1,1,p,a[i][j],r[a[i][j]],-2*b[i][j]);
       dfs2(a[i][j]);
       add(1,1,p,1,n,-b[i][j]);
       add(1,1,p,a[i][j],r[a[i][j]],2*b[i][j]);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	j=2;
	scanf("%d%d",&k,&v);
	for(p=1;p<n;p<<=1);
	dfs(1,0);
	for(i=p-1;i>0;i--)
	  f[i]=min(f[i<<1],f[i<<1|1]);
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d%d",&j,&k,&v);
       c[j].pb(i);
       d[j].pb(k);
       e[j].pb(v);
      }
    dfs2(1);
    for(i=1;i<=m;i++)
      printf("%lld\n",w[i]);
	return 0;
}