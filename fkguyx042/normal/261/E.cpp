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
#define M 3000005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,ans,l,r,vis[N],pri[N],A[M],f[M],up,Ans[M];
void dfs(int cnt,int x)
{
	 if (!cnt)
	 {
	   A[++A[0]]=x;
     }
     else 
     {
     	  dfs(cnt-1,x);
     	  while (r/x>=pri[cnt])
     	 {
     	 	  x*=pri[cnt];
     	 	  dfs(cnt-1,x);
     	 }
     }
 }
int main()
{
	  scanf("%d%d%d",&l,&r,&p);
	  for (i=2;i<=p;++i)
	    if (!vis[i])
	    {
	    	 pri[++pri[0]]=i;
	    	 for (j=i;j<=p;j+=i) vis[j]=1;
	    }
	  dfs(pri[0],1);
	  sort(A+1,A+A[0]+1);
	  memset(f,60,sizeof(f));
	  f[1]=0;
	  for (j=2;j<=p;++j)
	    for (i=1,up=1;i<=A[0]&&up<=A[0];++i)
	    {
	    	  for (;up<=A[0]&&1ll*A[i]*j>A[up];++up);
	    	  f[up]=min(f[up],f[i]+1);
	    	  if (f[up]+j<=p) Ans[up]=1;
	    }
	  for (i=1;i<=A[0];++i)
	    ans+=Ans[i]*(A[i]>=l);
	  printf("%d\n",ans);
}