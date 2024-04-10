#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,b,x,y,yy,i,hs;
double k;
ll rmt(ll xi,ll yi)
{
	ll h1=xi*(xi+1),h2;
	h1=h1/2;
	//cout<<h1<<endl;
	h1=h1*(yi+1);
	//cout<<h1<<endl;
	h2=yi*(yi+1);
	h2=h2/2;
	//cout<<h2
	h2=h2*(xi+1);
//	cout<<h1+h2<<endl;
	return h1+h2;
}
int main()
{
	cin>>m>>b;
	y=b;
	x=m*b;
	k=(double)y/(double)x;
	for(i=0;i<=x;i++)
	{
		yy=y-ceil((double)i*k);
	//	cout<<i<<" "<<yy<<" "<<rmt(i,yy)<<endl;
		hs=max(rmt(i,yy),hs);
	}
	x=b;
	y=m*b;
	k=y/x;
	for(i=0;i<=x;i++)
	{
		yy=y-ceil((double)i*k);
		hs=max(rmt(i,yy),hs);
	}
	cout<<hs<<endl;
}