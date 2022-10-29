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
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,cost[N],fa[N];

long long a[N],b[N],sum[N];

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%I64d",&a[i]);
		for (i=1;i<=n;++i) scanf("%I64d",&b[i]),a[i]-=b[i];
		for (i=2;i<=n;++i) scanf("%d%d",&fa[i],&cost[i]);
		for (i=n;i>1;--i)
		{
				sum[i]+=a[i]; 
				if (sum[i]<0)
				{	
						if (1.*sum[i]*cost[i]<-1e18) 
						{
							puts("NO");
							return 0;
						}
						sum[fa[i]]+=sum[i]*cost[i];
						if(sum[fa[i]]<-1e18)
						{
								puts("NO");
								return 0;
						}
				}
				else 
				{
						sum[fa[i]]+=sum[i];
				}
		}
		if (sum[1]<0) puts("NO");
		else puts("YES");
}