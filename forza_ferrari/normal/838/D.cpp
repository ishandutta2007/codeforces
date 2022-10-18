/*T1*/ 
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int n,m;
inline int pw(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
signed main() 
{
	//freopen("breeze.in","r",stdin);
	//freopen("breeze.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",pw(2,m)*pw(n+1,m-1)%mod*(n-m+1)%mod);
	return 0;
}