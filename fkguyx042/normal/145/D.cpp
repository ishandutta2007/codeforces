#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>

#define lim 2005
#define N 100005

using namespace std;
set<int>st;
map<int,int>lucky;
int tot,a[N],Next[N],p[N],vis[lim],Q[lim];
int n,i,j,k,Rc;
long long f[N],g[N],h[N];
set<int>::iterator it;
long long sum=0,ans=0;
void dfs(long long x)
{
	 if (x>(int)1e9) return;
	 ++tot; lucky[x]=tot;
	 dfs(x*10+4); dfs(x*10+7);
}
long long cal(int x)
{
	  return 1ll*x*(x+1)/2;
}
void add(int x)
{
	  it=st.lower_bound(x);
	  if (it==st.begin()) sum+=cal(*it-x-1);
	  else 
	  {
	  	    int B=*it;
	  	    int A=*--it;
	  	    sum-=cal(B-A-1);
	  	    sum+=cal(x-A-1);
	  	    sum+=cal(B-x-1);
	  }
	  st.insert(x);
}
void del(int x)
{
	 while (*st.begin()<=x)
	 {
	    it=st.begin();
	    ++it;
	    sum-=cal(*it-*st.begin()-1);
	    st.erase(st.begin());
	 }
}
long long debug(int x,int y)
{
     	  return h[x]-h[x-y];
}
void pre()
{
	  for (i=1;i<=n;++i)
	  {
	  	  g[i]=g[i-1]+i;
	  	  h[i]=h[i-1]+g[i];
	  	  f[i]=f[i-1]+h[i-1];
	  }
}
int main()
{
  //freopen("pair.in","r",stdin);
  //freopen("pair.out","w",stdout);
  scanf("%d",&n);
  pre();
  for (i=1;i<=n;++i) scanf("%d",&a[i]);
  dfs(4); dfs(7);
  for (i=1;i<=n;++i) if (lucky[a[i]]) Q[++Rc]=i,p[i]=lucky[a[i]];
  int Last=0;
  Q[++Rc]=n+1;
  for (i=Rc-1;i;--i)
    Next[Q[i]]=vis[p[Q[i]]],vis[p[Q[i]]]=Q[i];
  for (i=1;i<=Rc;++i)
  {
  	  for (j=Q[i-1]+1;j<Q[i];++j)
      ans+=1ll*(j-Q[i-1])*g[n-j];
  }
  for (i=1;i<Rc;++i)
  {
  	  memset(vis,0,sizeof(vis));
  	  sum=0;
  	  st.clear(); st.insert(n+1);
  	   for (j=i;j<Rc;++j)
  	{
  		    if (!vis[p[Q[j]]])
  		       for (k=Next[Q[j]];k;k=Next[k])
  		            add(k);
  		    vis[p[Q[j]]]=1;
  		    del(Q[j]);
  		    ans+=1ll*(Q[i]-Q[i-1])*(Q[j+1]-Q[j])*sum;
  		    ans+=1ll*(Q[i]-Q[i-1])*debug(*st.begin()-Q[j]-1,Q[j+1]-Q[j]);
    }
   }
   printf("%I64d\n",ans);
}