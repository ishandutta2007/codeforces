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

#define N 5005
#define M 5005
#define seed 23333
#define Mo 998244353

using namespace std;
const long long INF=(long long)1e15;
int i,j,m,n,p,k;
long long f[N][N];
int a[N],b[N];
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
	  sort(b+1,b+n+1); b[0]=unique(b+1,b+n+1)-(b+1);
	  for (i=1;i<=n;++i) a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
	  for (i=0;i<=n;++i)
	    for (j=0;j<=b[0];++j) f[i][j]=INF;  
      f[0][0]=0;
      for (i=0;i<n;++i)
         for (j=0;j<=b[0];++j)
             if (f[i][j]!=INF)
        {
        	  if (j>=a[i+1]) f[i+1][a[i+1]]=min(f[i+1][a[i+1]],f[i][j]);
        	  else 
        	  {
        	  	  f[i+1][j]=min(f[i+1][j],f[i][j]+1);
        	  	  f[i+1][a[i+1]]=min(f[i+1][a[i+1]],f[i][j]+b[a[i+1]]-(j==0?0:b[j]));
        	  }
        }
      long long ans=n+5;
      for (i=0;i<=b[0];++i) ans=min(ans,f[n][i]); 
      printf("%d\n",ans);
}