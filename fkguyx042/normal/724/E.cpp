#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 10005
#define M 200005
#define seed 23333

using namespace std;
const long long inf=1e16;
int i,j,m,n,k,p[N],s[N],now,last,c;
long long f[2][N],ans;
int main()
{
		scanf("%d%d",&n,&c);
		for (i=1;i<=n;++i) scanf("%d",&p[i]);
		for (i=1;i<=n;++i) scanf("%d",&s[i]);
		memset(f,60,sizeof(f)); f[0][0]=0; 
		for (i=n;i;--i)
		{
				now^=1; last=now^1;
				memset(f[now],60,sizeof(f[now]));
				for (j=0;j<=n-i;++j)
					if (f[last][j]<inf)
					{
							f[now][j]=min(f[now][j],f[last][j]+s[i]+1ll*c*j);
							f[now][j+1]=min(f[now][j+1],f[last][j]+p[i]);
					}
		}
		ans=inf;
		for (i=0;i<=n;++i) ans=min(ans,f[now][i]);
		printf("%I64d\n",ans);
}