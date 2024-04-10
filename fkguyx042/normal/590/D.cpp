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

#define N 155
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,f[N][N*N],a[N],s,l;
int main()
{
	  scanf("%d%d%d",&n,&k,&s);
	  s=min(s,n*(n-1)/2);
	  memset(f,60,sizeof(f));
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  f[0][s]=0;
	  for (i=1;i<=n;++i)
	    for (j=min(k,i);j;--j)
	       for (l=s-i+j;l>=0;--l)
	         f[j][l]=min(f[j][l],f[j-1][l+i-j]+a[i]);
	  int ans=(int)1e9;
	  for (i=0;i<=s;++i) ans=min(ans,f[k][i]);
	  printf("%d\n",ans);
}