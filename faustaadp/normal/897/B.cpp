#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,i,hs,te,hz,ha;
ll rmt(ll aa)
{
	ll ha=1;
	while(aa>0)
	{
		aa=aa/10;
		ha*=10;
	}
	return ha;
}
int main()
{
	cin>>n>>p;
//	cout<<rmt(100)<<"\n";
	for(i=1;i<=n;i++)
	{
		hz=i*rmt(i);
		te=i;
		ha=rmt(i);
		ha/=10;
		while(te>0)
		{
			hz+=(te%10)*ha;
			te/=10;
			ha/=10;
		}
		hs+=hz;
		hs=hs%p;
	//	cout<<hz<<"\n";
	}
	cout<<hs<<"\n";
}