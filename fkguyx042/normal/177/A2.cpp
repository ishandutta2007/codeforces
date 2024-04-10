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

#define N 1005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N][N],vis[N][N],ans;
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i)
	    for (j=1;j<=n;++j) scanf("%d",&a[i][j]);
	  for(i=1;i<=n;++i) vis[i][(n+1)/2]=vis[(n+1)/2][i]=1;
	  for(i=1;i<=n;++i) vis[i][i]=vis[i][n-i+1]=1;
	  for (i=1;i<=n;++i) 
	    for (j=1;j<=n;++j) if (vis[i][j]) ans+=a[i][j];
	  printf("%d\n",ans);
}