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
#define M 17
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,Ans[M],id[M],vis[M],x,y,k,a[M][M],bit[M],Maxn;
long long f[M][N],K;
const long long inf=(long long)1e18;
void jia(long long &x,long long y)
{
	 x+=y; if (x>=inf) x=inf;
}
long long work()
{
	int i,j,k;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (i=0;i<n;++i)
	  for (j=0;j<Maxn;++j)
	    if(f[i][j])
	    {
	    	   if (Ans[i]!=-1) 
	    	   {
	    	   	   if ((j&(1<<Ans[i]))||((j&bit[Ans[i]])!=bit[Ans[i]])) continue;
	    	   	   jia(f[i+1][j|(1<<Ans[i])],f[i][j]);
	    	   	   continue;
	    	   }
	    	   for (k=0;k<n;++k) if (((j&(1<<k))==0)&&((j&bit[k])==bit[k])) jia(f[i+1][j|(1<<k)],f[i][j]);
        }
    return f[n][Maxn-1];
}
int main()
{
	scanf("%d%I64d%d",&n,&K,&m); K-=2000;
	for (;m--;)
	{
		 scanf("%d%d",&x,&y); --x; --y;
		 a[x][y]=1;
    } Maxn=(1<<n);
    for (k=0;k<n;++k)
    for (i=0;i<n;++i)
      for (j=0;j<n;++j)
        a[i][j]|=a[i][k]&a[k][j];
    for (i=0;i<n;++i) if (a[i][i]) { printf("The times have changed\n"); return 0; }
    for (i=0;i<n;++i) for (j=0;j<n;++j) if (a[j][i]) bit[i]|=(1<<j); 
    memset(Ans,-1,sizeof(Ans));
    memset(id,-1,sizeof(id));  if (work()<K) { printf("The times have changed\n"); return 0; }
    for (i=0;i<n-1;++i)
       for (j=0;j<n;++j)
         if (!vis[j])
         {
         	  Ans[j]=i;
         	  long long x=work();
         	  if (x<K) K-=x; else { vis[j]=1; id[i]=j; Ans[j]=i; break; }
         	  Ans[j]=-1;
         }
    for (i=0;i<n;++i) if (!vis[i]) id[n-1]=i;
    for (i=0;i<n;++i) printf("%d ",id[i]+1);
}