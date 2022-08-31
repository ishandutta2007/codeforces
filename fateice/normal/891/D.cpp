#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,u[500010],v[500010],fa[500010],s[500010],w[500010],x[500010],y[500010],f[500010],g[500010],ff[500010],gg[500010],h1[500010],h2[500010],b[500010],c[500010],S,T;
vector<int> a[500010];
L p;
inline void dfs(int i)
{
	int j;
	s[i]=1;
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=fa[i])
	    {
		 fa[a[i][j]]=i;
		 dfs(a[i][j]);
		 s[i]+=s[a[i][j]];
		 if(!w[a[i][j]] && !w[i])
		   w[i]=a[i][j],w[a[i][j]]=i;
		}
}
inline void dfs2(int i)
{
	int j;
	if(w[i]==fa[i])
	  x[i]=1;
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=fa[i])
	    {
		 dfs2(a[i][j]);
		 if(w[i]==fa[i])
		   x[i]+=x[w[a[i][j]]];
		}
}
inline void dfs3(int i)
{
	int j;
	if(w[i] && w[i]!=fa[i])
	  x[i]=1;
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=fa[i])
	 	if(w[i] && w[i]!=fa[i] && a[i][j]!=w[i])
		  x[i]+=x[w[a[i][j]]];
	if(i>1 && w[i] && w[i]!=fa[i])
	  x[i]+=x[w[fa[i]]];
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=fa[i])
		dfs3(a[i][j]);
}
inline int sum(int i,int j)
{
	if(fa[i]==j)
	  return s[i];
	else
	  return n-s[j];
}
inline void dfs4(int i)
{
	int j;
	b[i]=1;
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=w[i])
	    dfs4(w[a[i][j]]);
}
inline void dfs5(int i)
{
	int j;
	c[i]=1;
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=w[i])
	    dfs5(w[a[i][j]]);
}
inline void dfs6(int i)
{
	int j;
	f[i]=b[i];
	f[0]+=b[i];
	g[i]=c[i];
	g[0]+=c[i];
	ff[i]=(b[i] && !c[i]);
	ff[0]+=ff[i];
	gg[i]=(c[i] && !b[i]);
	gg[0]+=gg[i];
	h1[i]=(i==S);
	h2[i]=(i==T);
	for(j=0;j<a[i].size();j++)
	  if(a[i][j]!=fa[i])
	    {
		 dfs6(a[i][j]);
		 f[i]+=f[a[i][j]];
		 g[i]+=g[a[i][j]];
		 ff[i]+=ff[a[i][j]];
		 gg[i]+=gg[a[i][j]];
		 h1[i]+=h1[a[i][j]];
		 h2[i]+=h2[a[i][j]];
		}
}
inline int get(int i,int j,int f[])
{
	if(fa[i]==j)
	  return f[i];
	else
	  return f[0]-f[j];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k;
	scanf("%d",&n);
	if(n&1)
	  {
	   printf("0\n");
	   return 0;
	  }
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&u[i],&v[i]);
	   a[u[i]].push_back(v[i]);
	   a[v[i]].push_back(u[i]);
	  }
	dfs(1);
	for(i=1,k=0;i<=n;i++)
	  k+=!w[i];
	if(k>2)
	  {
	   printf("0\n");
	   return 0;
	  }
	if(!k)
	  {
	   dfs2(1);
	   dfs3(1);
	   for(i=1;i<n;i++)
	     if(w[u[i]]==v[i])
	       p+=(L)x[u[i]]*x[v[i]];
	     else
	       p+=(L)sum(u[i],v[i])*sum(v[i],u[i]);
	   printf("%I64d\n",p);
	  }
	else
	  {
	   for(i=1;i<=n;i++)
	     if(!w[i])
	       if(!S)
	         S=i;
	       else
	         T=i;
	   dfs2(1);
	   dfs3(1);
	   dfs4(S);
	   dfs5(T);
	   dfs6(1);
	   h1[0]=h2[0]=1;
	   for(i=1;i<n;i++)
	     if(w[u[i]]==v[i])
	       {
			if(get(u[i],v[i],h1) && get(u[i],v[i],h2))
			  {}
			else if(get(v[i],u[i],h1) && get(v[i],u[i],h2))
			  swap(u[i],v[i]);
			else
			  continue;
			if(b[v[i]] && c[v[i]])
			  p+=(L)x[v[i]]*(get(u[i],v[i],ff)+get(u[i],v[i],gg));
		    else if(b[v[i]])
			  p+=(L)x[v[i]]*get(u[i],v[i],g);
		    else if(c[v[i]])
			  p+=(L)x[v[i]]*get(u[i],v[i],f);
		   }
		 else
		   if(get(u[i],v[i],h1) && get(v[i],u[i],h2))
		     p+=(L)get(u[i],v[i],f)*get(v[i],u[i],g);
		   else if(get(u[i],v[i],h2) && get(v[i],u[i],h1))
		     p+=(L)get(u[i],v[i],g)*get(v[i],u[i],f);
	   printf("%I64d\n",p);
	  }
	return 0;
}