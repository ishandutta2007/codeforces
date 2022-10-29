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
int i,j,m,n,p,k,ans,x,y,vis[N],Q[N],tot;
vector<int>v[N],vec[N];
int work(int x)
{
	    Q[Q[0]=1]=x;
	    vis[x]=++tot;
	    int l=1,i;
	    for (l=1;l<=Q[0];++l)
	    {
	    	  int p=Q[l];
	    	  for (i=0;i<(int)v[p].size();++i)
	    	    if (!vis[v[p][i]])
	    	    {
	    	    	  int k=v[p][i];
	    	    	  Q[++Q[0]]=k;
	    	    	  vis[k]=tot;
	    	    }
	    }
	    for (l=1;l<=Q[0];++l)
	       for (i=0;i<(int)vec[Q[l]].size();++i)
	         if (vis[vec[Q[l]][i]]==tot) return 0;
	    return Q[0];
}
int main()
{
	  scanf("%d",&n);
	  scanf("%d",&m);
	  for (;m--;)
	  {
	      scanf("%d%d",&x,&y);
		  v[x].push_back(y);
		  v[y].push_back(x);
	  }
	  scanf("%d",&m);
	  for (;m--;)
	  {
	       scanf("%d%d",&x,&y);
		   vec[x].push_back(y);
		   vec[y].push_back(x);
	  }
	  for (i=1;i<=n;++i)
	    if (!vis[i])
	    {
	    	  ans=max(ans,work(i));
	    }
	  printf("%d\n",ans);
}