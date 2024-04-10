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

#define N 205
#define M 51005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,f[2][N/2][M],now,last,a[N],K;
void jia(int &x,int y)
{
	 x+=y; if (x>=Mo) x-=Mo;
}
int main()
{
	 scanf("%d%d",&n,&K);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 sort(a+1,a+n+1);
	 f[0][0][K]=1;
	 for (i=0;i<n;++i)
	 {
	 	  now^=1; last=now^1;
	 	  int zuo=min(i,n-i),Maxsum=500*zuo+K,cao=min(i+1,n-(i+1));
	 	  for (j=0;j<=zuo;++j)
	 	     for (k=0;k<=Maxsum;++k)
	 	        if (f[last][j][k])
	 	        {
	 	        	  if (j)
	 	        	  {
					     if (k-a[i+1]>=0)
					     jia(f[now][j-1][k-a[i+1]],1ll*f[last][j][k]*j%Mo);
					  }
					  jia(f[now][j][k],1ll*f[last][j][k]*(j+1)%Mo);
					  if (j+1<=cao)
					  jia(f[now][j+1][k+a[i+1]],f[last][j][k]);
					  f[last][j][k]=0;
				}
		  
	 }
	 int ans=0;
	 for (i=0;i<=K;++i) jia(ans,f[now][0][i]);
	 printf("%d\n",ans);
}