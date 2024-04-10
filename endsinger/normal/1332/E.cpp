#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int zh(int t,int l,int r,int k)
{
	if(l%2!=r%2)
		return qp(r-l+1,t)*qp(2,mod-2)%mod;
	int x=t%2,y=l%2;
	if(x&&y)
	{
		if(k)
			return (qp(r-l+1,t)+1+mod)%mod*qp(2,mod-2)%mod;
		else
			return (qp(r-l+1,t)-1+mod)%mod*qp(2,mod-2)%mod;
	} 
	else
	{
		if(!k)
			return (qp(r-l+1,t)+1+mod)%mod*qp(2,mod-2)%mod;
		else
			return (qp(r-l+1,t)-1+mod)%mod*qp(2,mod-2)%mod;
	}
}
signed main()
{
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	int x=n*m/2,y=n*m-x;
	if(n*m%2==0)
	{
		cout<<(zh(x,l,r,0)*zh(y,l,r,0)%mod+zh(x,l,r,1)*zh(y,l,r,1)%mod)%mod<<endl;
	}
	else
	{
		cout<<qp(r-l+1,n*m)<<endl;
	}
	return 0;
}