#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=998244353;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int w,h;
int main()
{
	cin>>w>>h;
	cout<<binpow(2,w+h)<<endl;
	return Accepted;
}