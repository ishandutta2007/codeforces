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
#define K 16
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,x,y,cas,id[N],fa[N][K+5],deep[N],st[N];
int tot,imp[N],top,S[N],stack[N],Fa[N];
long long f[N][2]; 
vector<int>v[N],V[N];
void add(int x,int y) { v[x].push_back(y); }
void dfs(int x)
{
	   int i;
	   for (i=1;i<=K;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	   st[x]=++tot;
	   for (i=0;i<(int)v[x].size();++i)
	   {
	   	     int p=v[x][i];
	   	     if (fa[x][0]==p) continue;
	   	     fa[p][0]=x;
	   	     deep[p]=deep[x]+1;
	   	     dfs(p);
	   }
}
int getlca(int x,int y) 
{  if (deep[x]<deep[y]) swap(x,y); 
  int i,k=deep[x]-deep[y]; 
  for (i=K;i>=0;i--) 
   if (k>=(1<<i))  
   { k-=(1<<i); 
      x=fa[x][i]; 
    } 
   if (x==y) return x; 
  for (i=K;i>=0;i--) 
  if (fa[x][i]!=fa[y][i]) 
{  x=fa[x][i]; y=fa[y][i]; } 
return fa[x][0]; 
} 
void Add(int x,int y)
{
	 V[x].push_back(y);
}
inline bool cmp(int a,int b) {return st[a]<st[b]; }
void del() 
{ 
  S[++S[0]]=stack[top]; 
  Add(Fa[stack[top]],stack[top]); 
   top--; 
} 
void clear()
{
	for (i=1;i<=S[0];++i) V[S[i]].clear();
}	
void Dfs(int x)
{
     int i;
	 for (i=0;i<(int)V[x].size();++i)
	   Dfs(V[x][i]);
	 if (imp[x]==cas)
	 {
	      f[x][1]=0;
		  for (i=0;i<(int)V[x].size();++i) 
		   if(deep[V[x][i]]-deep[x]>1)
		     f[x][1]+=min(f[V[x][i]][1]+1,f[V[x][i]][0]);
		     else 
		     f[x][1]+=f[V[x][i]][0];
	 }
	 else 
	 {
	 	  f[x][0]=0; long long A=1;
	 	  for (i=0;i<(int)V[x].size();++i)
	 	    f[x][0]+=f[V[x][i]][0],A+=min(f[V[x][i]][0],f[V[x][i]][1]);
	 	  f[x][0]=min(f[x][0],A);
	 	  f[x][1]=0;  long long Min=(int)1e9;
	 	  for (i=0;i<(int)V[x].size();++i)
	 	    f[x][1]+=f[V[x][i]][0],Min=min(Min,f[V[x][i]][1]-f[V[x][i]][0]);
	 	  f[x][1]+=Min;
	 }
}
void work()
{
	  for (i=1;i<=id[0];++i) imp[id[i]]=cas;
	  sort(id+1,id+id[0]+1,cmp);
	  for (i=1;i<=id[0];++i) if (imp[fa[id[i]][0]]==cas) break;
	  if(i<=id[0]) { puts("-1"); return; }
	  if (id[1]!=1) id[++id[0]]=1;
	  sort(id+1,id+id[0]+1,cmp);
	  top=0; S[0]=0;
	  for (i=1;i<=id[0];++i)
	  {
	      int x=id[i];
		  if (!top) { stack[++top]=x; Fa[x]=0; continue; }
		  int lca=getlca(x,stack[top]);
		  while (top)
		  {
		     if (deep[stack[top]]<=deep[lca]) break;
			 if (deep[stack[top-1]]<deep[lca]) Fa[stack[top]]=lca;
			 del();
		  }
		  if (lca!=stack[top]) {Fa[lca]=stack[top]; stack[++top]=lca; }
		  Fa[x]=lca; stack[++top]=x;
	  }
	  while (top) del();
	  for (i=1;i<=S[0];++i) f[S[i]][0]=f[S[i]][1]=(int)1e9;
	  Dfs(1);
	  printf("%d\n",min(f[1][0],f[1][1]));
	  clear();
}
int main()
{
	  scanf("%d",&n);
	  for(i=1;i<n;++i)
	  {
	  	  scanf("%d%d",&x,&y);
	  	  add(x,y); add(y,x);
	  }
	  dfs(1);
	  scanf("%d",&m);
	  for(cas=1;cas<=m;++cas)
	  {
          for (i=0;i<=id[0];++i) scanf("%d",&id[i]);
          work();
      }
}