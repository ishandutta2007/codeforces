#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 105

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,a[N];

long long f[N][M];

const long long inf=(long long)1e18;

int main()
{
		memset(f,60,sizeof(f));
		scanf("%d",&n); 
		for (i=0;i<n;++i)
		{
				scanf("%d",&a[i]);
				a[i]/=1000;
		}
		f[0][0]=0;
		for (i=0;i<n;++i)
			for (j=0;j<M;++j)
				if (f[i][j]<inf)
				{
						if (j+a[i]<M) f[i+1][j+a[i]]=min(f[i+1][j+a[i]],f[i][j]+a[i]*10);
						if (a[i]*10<=j) f[i+1][j-a[i]*10]=min(f[i+1][j-a[i]*10],f[i][j]);
						else f[i+1][0]=min(f[i+1][0],f[i][j]+(a[i]*10-j));
				}
		long long ans=(long long)1e18;
		for (i=0;i<M;++i)
			ans=min(ans,min((long long)2e16,f[n][i])*100);
		printf("%I64d\n",ans);
}