#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
long long n,m;
int main()
{
	cin>>n>>m;
	cout<<(binpow(2*n+2,m)*(n+1-m)%mod)*binpow(n+1,mod-2)%mod<<endl;
	return 0;
}