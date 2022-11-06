#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010101],b[1010101],hz,l,r,c,hs;
ll rmt(ll aa)
{
	ll ii;
	for(ii=1;ii<=n;ii++)
	{
		if(aa<=1899&&b[ii]==1)
			return 1;
		else
		if(aa>=1900&&b[ii]==2)
			return 0;
		aa+=a[ii];
	}
	hs=aa;
	return 2;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	hz=-10e17;
	l=-10e17;
	r=10e17;
	while(l<=r)
	{
	//	cout<<l<<" "<<r<<"\n"; 
		c=(l+r)/2;
		if(rmt(c)==0)
			r=c-1;
		else
		if(rmt(c)==1)
			l=c+1;
		else
		{
			hz=c;
			l=c+1;
		}
	}
//	cout<<hz<<"\n";
	rmt(hz);
	if(hz==-10e17)
		cout<<"Impossible\n";
	else
	if(hz==10e17)
		cout<<"Infinity\n";
	else
		cout<<hs<<"\n";
	
}