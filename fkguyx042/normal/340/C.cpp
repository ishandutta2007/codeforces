#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;


int n,a[100005];
LL sum,ss,SYC;


LL gcd(LL x,LL y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	sum=1ll*sum;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		SYC+=1ll*a[i]*(i-1)-ss;
		ss+=a[i];
	}
	sum+=2ll*SYC;
	LL x=gcd(sum,(LL)n);
	sum/=x;
	LL nn=n;nn/=x;
	printf("%I64d %I64d\n",sum,nn);
	return 0;
}