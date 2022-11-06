#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,hs,hz,j,hv,ta;
vector<ll> a;
ll fpb(ll aa,ll bb)
{
	if(bb==0)
		return aa;
	else
		return fpb(bb,aa%bb);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	a.pb(0);
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta==1)
			hv++;
		else
			a.pb(ta);
	}
	//cout<<n<<" "<<hv<<"\n";
	hs=10e17;
	if(hv>0)
		hs=n-hv;
	n=a.size()-1;
	for(i=1;i<=n;i++)
	{
		hz=0;
		for(j=i;j<=n;j++)
		{
			hz=fpb(a[j],hz);
			if(hz==1)
			{
				hs=min(hs,j-i-1+n);
				break;
			}
		}
	}
	if(hs>10e16)
		hs=-1;
	cout<<hs<<"\n";
}