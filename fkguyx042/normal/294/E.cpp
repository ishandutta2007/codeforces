#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define N 5005

using namespace std;
long long i,j,m,n,p,k,x[N],y[N],w[N],size[N],Rel[N];
long long GG[N];
long long Sum[N];
vector<int>v[N],sum[N];
long long ans=(long long)1e17,ans1,ans2;
void dfs(long long x,long long f)
{
	 long long i,p; 
	 size[x]=Sum[x]=Rel[x]=0;
	 for (i=0;i<(int)v[x].size();++i)
	   if ((p=v[x][i])!=f)
	   {
	   	     dfs(p,x);
	   	     Sum[x]+=Sum[p]+1ll*sum[x][i]*size[p];
	   	     size[x]+=size[p];
	   }
	  ++size[x];
}
void Dfs(long long x,long long f,long long fa,long long Rp,long long len,long long &R)
{ 
  Rel[Rp]+=1ll*(size[Rp]-size[x])*size[x]*len;
  if (f==fa) R=min(R,Sum[x]),GG[x]=Sum[x];
  else R=min(R,GG[x]=GG[f]+1ll*len*(-size[x]+size[Rp]-size[x]));
  long long i;
  for (i=0;i<(int)v[x].size();++i)  
     if (v[x][i]!=f) Dfs(v[x][i],x,fa,Rp,sum[x][i],R);
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<n;++i) scanf("%d%d%d",&x[i],&y[i],&w[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]),sum[x[i]].push_back(w[i]),
	  sum[y[i]].push_back(w[i]);
	  for (i=1;i<n;++i)
	  {
	  	  ans1=ans2=(long long)1e17;
	  	  dfs(x[i],y[i]);
	  	  Dfs(x[i],y[i],y[i],x[i],0,ans1);
	  	  dfs(y[i],x[i]);
	  	  Dfs(y[i],x[i],x[i],y[i],0,ans2);
	      ans1=ans1*size[y[i]]+ans2*size[x[i]]+w[i]*size[x[i]]*size[y[i]]+Rel[x[i]]+Rel[y[i]];
	  	  if (ans1<ans) ans=ans1;
	  }
	  cout<<ans<<endl;
}