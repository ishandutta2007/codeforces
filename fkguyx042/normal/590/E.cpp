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

#define N 10000005
#define M 755
#define seed 23333
#define Mo 998244353

using namespace std;
int bit[M][M],fox[N];
struct Node{int ed,before;}b[N];
int i,j,m,n,p,k,End[N],tot=1,k1,son[N][2],fail[N],S[M],q[N],flag[M],ans,match[M];
int len[M],All,str[M],end[M],fa[N],a[M][M],Ans[M],vist[M],B[M][M],was[M][2],vis[M];
bool s[N];
char c[N];
void add(int x,int y)
{
	 b[++k1].ed=y; b[k1].before=fox[x]; fox[x]=k1;
}
void build_tree()
{ int l=1,r=0,i,j,k;
   for (i=0;i<2;i++)
     if (son[1][i])
     { fail[son[1][i]]=1; q[++r]=son[1][i];}else son[1][i]=1;
   for (;l<=r;l++)
   {  k=q[l];
     for (i=0;i<2;i++)
       if (son[k][i])
      { fail[son[k][i]]=son[fail[k]][i];
        q[++r]=son[k][i];
        } else son[k][i]=son[fail[k]][i];
   }
   for (i=2;i<=tot;++i) add(fail[i],i);
   q[r=1]=1;
   for (l=1;l<=r;++l)
   {
   	 k=q[l];
   	 if (End[fail[k]]) fa[k]=fail[k]; else fa[k]=fa[fail[k]];
   	 for (i=fox[k];i;i=b[i].before)
   	   q[++r]=b[i].ed;
   }
}
void doit(int x)
{
	  q[0]=0;
	  int i,j;
	  for (i=str[x],p=1;i<=end[x];++i)
	  {
	  	 p=son[p][s[i]];
	  	 q[++q[0]]=p;
     }
	  for (i=1;i<=q[0];++i)
	    for (j=q[i];j;j=fa[j])
		  if (a[x][End[j]]&&End[j]) break;
		  else a[x][End[j]]=1;
}
bool dfs(int num)
 {  int i;
   for (i=1;i<=n;++i)
    if (a[num][i]&&!flag[i])
     { 
       flag[i]=1;
        if (!match[i]||dfs(match[i]))
        { match[i]=num;
          return true;
          }
          }
     return false;
}
void dfs(int x,int y)
{
	 if (was[x][y]) return;
	 was[x][y]=1;
	 int i;
	 for (i=1;i<=n;++i)
	 {
	   if (!y&&a[x][i]) dfs(i,1);
	   if (y&&match[x]==i) dfs(i,0);
      }
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i)
	 {
	    scanf("%s",c);
/*	    if (n==750)
	    {
	    	  if (i==311) printf("%s\n",c);
	    	  if (i==414) printf("%s\n",c);
	    }
	    */
	    len[i]=strlen(c);
	    for (j=0,p=1;j<len[i];++j)
	    {
	    	  int ch=c[j]-'a';
	    	  if (!son[p][ch]) son[p][ch]=++tot; 
	    	  p=son[p][ch];
	    }
	    End[p]=i; 
	    str[i]=All+1;
	    for (j=0;j<len[i];++j) s[++All]=c[j]-'a';
	    end[i]=All;
    }
    build_tree();
	for (i=1;i<=n;++i) 
	doit(i);
	for (i=1;i<=n;++i) a[i][i]=0;
  //  if (n==750) printf("%d %d\n",a[311][414],a[414][311]);
  for (i=1;i<=n;++i)
    for (j=1;j<=n;++j) B[i][j]=a[j][i];
  memcpy(a,B,sizeof(a));
	for (i=1;i<=n;i++)
    { memset(flag,0,sizeof(flag)); if (dfs(i)) ans++; else vist[i]=1;  }
    printf("%d\n",n-ans); 
    for (i=1;i<=n;++i)
      if (vist[i]) dfs(i,0);
    memset(vis,0,sizeof(vis));
    for (i=1;i<=n;++i)
    {
    	  if (!vist[i]&&!was[i][0]) vis[i]=1;
    	  if (match[i]&&was[i][1])  vis[i]=1;
    }
    for (i=1;i<=n;++i) if (!vis[i]) Ans[++Ans[0]]=i;
    for (i=1;i<=Ans[0];++i) printf("%d ",Ans[i]);
    return 0;
}