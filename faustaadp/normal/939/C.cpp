#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[2010101],s,f,sel,hz,ma,hv;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	cin>>s>>f;
	sel=f-s;
	for(i=1;i<=sel;i++)
		hz+=a[i];
	ma=hz;
	hv=(s-(1-1))+3*n;
	hv%=n;
	if(hv==0)
		hv=n;
	for(i=1;i+sel<=2*n;i++)
	{
		hz-=a[i];
		hz+=a[i+sel];
	//	cout<<hz<<"\n";
		if(hz>ma)
		{
		//	cout<<"sd";
			ma=hz;
			hv=(s-((i+1)-1))+3*n;
			hv%=n;
			if(hv==0)
				hv=n;
		//	cout<<i<<"\n";
		}
		else
		if(hz==ma)
		{
			ll hl=(s-((i+1)-1))+3*n;
			hl%=n;
			if(hl==0)
				hl=n;
			if(hl<hv)
			{
				hv=hl;
			}
		}
	}
	cout<<hv<<"\n";
}