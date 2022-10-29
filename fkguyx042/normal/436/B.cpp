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

#define N 2005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,x,type,h,sum[2][N],Sum[2][N],ans[N],Left[N][N],Right[N][N],up[N][N];
char c[N];
int main()
{
	  scanf("%d%d%d",&n,&m,&k);
	  for (i=1;i<=n;++i)
	{
		   scanf("%s",c);
		   for (j=1;j<=m;++j) if (c[j-1]=='U') up[i][j]=1;
		   else if (c[j-1]=='L') Left[i][j]=1;
		   else if (c[j-1]=='R') Right[i][j]=1;
    }
      for (j=1;j<=m;++j)
         for (i=1;i<=n;++i) if (up[i][j]&&(i%2==1)) ++ans[j];
      for (j=1;j<=m;++j)
      {
         for (i=j;i>=1;--i)
            ans[j]+=Right[j-i+1][i];
      }
      for (j=1;j<=m;++j)
      {
      	  for (i=j;i<=m;++i)
      	       ans[j]+=Left[1+i-j][i];
      }
      for (i=1;i<=m;++i) printf("%d ",ans[i]);
}