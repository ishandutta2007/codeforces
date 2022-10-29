#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define jsb 1000000007
typedef long long LL;
LL a,b,ans=0;
int Pow(LL x,LL y)
{
	LL c=1;
	for(;y;y>>=1,x=x*x%jsb)if(y&1)c=c*1ll*x%jsb;
	return c;
}
int main()
{
	scanf("%I64d%I64d",&a,&b);LL nw=Pow(2,jsb-2);
	rep(k,1,a)
	{
		LL u=b*1ll*k%jsb;u=(u+1)%jsb;u=u*1ll*nw%jsb;
		u=u*1ll*b%jsb;u=u*1ll*(b-1)%jsb;
		ans=(ans+u)%jsb;
	}
	printf("%I64d\n",ans);
	return 0;
}