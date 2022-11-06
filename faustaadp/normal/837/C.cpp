#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,i,j,x[1010],y[1010],hs;
ll rmt(ll aa, ll bb)
{
	bool bo=0;
	if(max(x[aa],x[bb])<=a&&y[aa]+y[bb]<=b) bo=1;
	if(max(x[aa],x[bb])<=b&&y[aa]+y[bb]<=a) bo=1;
	
	if(max(y[aa],x[bb])<=a&&x[aa]+y[bb]<=b) bo=1;
	if(max(y[aa],x[bb])<=b&&x[aa]+y[bb]<=a) bo=1;
	
	if(max(x[aa],y[bb])<=a&&y[aa]+x[bb]<=b) bo=1;
	if(max(x[aa],y[bb])<=b&&y[aa]+x[bb]<=a) bo=1;
	
	if(max(y[aa],y[bb])<=a&&x[aa]+x[bb]<=b) bo=1;
	if(max(y[aa],y[bb])<=b&&x[aa]+x[bb]<=a) bo=1;
	if(bo)
		hs=max(hs,x[aa]*y[aa]+x[bb]*y[bb]);
}
int main()
{
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			rmt(i,j);
//			cout<<i<<" "<<j<<" "<<hs<<"\n";
		}
	}
	cout<<hs<<"\n";
}