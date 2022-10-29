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

#define N 105
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,now[26],vis[N],len[N],rel;
char c[N][N],s[N][N];
void work(int x,int y)
{
	  int i,j;
	  for (i=0;i<strlen(c[x]);++i) if (now[c[x][i]-'a']) break;
	  for (j=len[y]-1;j>=0;--j) s[y][i+j]=s[y][j];
	  for (j=0;j<i;++j) s[y][j]=c[x][j];
	  len[y]+=i;
	  for (i=strlen(c[x])-1;i>=0;--i) if (now[c[x][i]-'a']) break;
	  for (j=i+1;j<strlen(c[x]);++j) s[y][len[y]++]=c[x][j];
	  vis[x]=1;
	  for (i=0;i<len[y];++i) now[s[y][i]-'a']=1;
}
void ins(int x)
{
	 int i;
	 memset(now,0,sizeof(now));
	 ++rel; len[rel]=strlen(c[x]);
	 for (i=0;i<len[rel];++i) s[rel][i]=c[x][i];
	 for (i=0;i<len[rel];++i) now[s[rel][i]-'a']=1;
	 vis[x]=1;
}
int main()
{
	 scanf("%d",&n);
	 rel=0;
	 for (i=1;i<=n;++i) scanf("%s",c[i]);
	 for (;;)
	 {
	 	   for (i=1;i<=n;++i)
	 	      if (!vis[i]) 
	 	    { 
	 	          for (j=0;j<strlen(c[i]);++j)
	 	             if (now[c[i][j]-'a']) break;
	 	          if (j==strlen(c[i])) continue;
	 	          work(i,rel); 
	 	          break;
	 	    }
	 	   if (i<=n) continue;
	 	   for (i=1;i<=n;++i)
	 	     if (!vis[i])
	 	     {
	 	     	   ins(i);
				   break;
			 }
		   if (i>n) break;
	 }
	 for (i=1;i<=rel;++i) for (j=0;j<len[i];++j) printf("%c",s[i][j]);
}