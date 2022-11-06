#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[202020],b[202020],l,r,c,hz;
bool rmt(ll aa)
{
	ll ii,hh=0;
	vector<ll> vv;
	for(ii=1;ii<=n;ii++)
	{
		if(a[ii]>=aa)
		{
			vv.pb(b[ii]);
		}
	}
	sort(vv.begin(),vv.end());
	if(vv.size()<aa)
		return 0;
	for(ii=0;ii<aa;ii++)
		hh+=vv[ii];
//	cout<<aa<<" "<<hh<<"\n";
	return hh<=m;
}
void rct(ll aa)
{
	ll ii,hh=0;
	vector<pair<ll,ll> > vv;
	for(ii=1;ii<=n;ii++)
	{
		if(a[ii]>=aa)
		{
			vv.pb(mp(b[ii],ii));
		}
	}
	sort(vv.begin(),vv.end());
	for(ii=0;ii<aa;ii++)
	{
		if(ii==aa-1)
			cout<<vv[ii].se<<"\n";
		else
			cout<<vv[ii].se<<" ";
	}
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	l=0;
	r=n;
	while(l<=r)
	{
		c=(l+r)/2;
		if(rmt(c))
		{
			hz=c;
			l=c+1;
		}
		else
			r=c-1;
	}
	cout<<hz<<"\n";
	cout<<hz<<"\n";
	rct(hz);
}