#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,tb,tc,hz,tj,hs,nn,k;
ll fpb(ll aa,ll bb)
{
	if(bb==0)
		return aa;
	else
		return fpb(bb,aa%bb);
}
int main()
{
	cin>>n>>k;
	if(k==n||n==1||k==0)
	{
		cout<<"0 0\n";
		return 0;
	}
	else
	if(k>=ceil(double(n)/double(3)))
	{
		cout<<"1 "<<n-k<<"\n";
		return 0;
	}
	else
	{
		cout<<"1 "<<k*2<<"\n";
		return 0;
	}
}