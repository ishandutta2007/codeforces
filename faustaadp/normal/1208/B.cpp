#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[2020],x[2020],has,d[2020],te;
map<ll,ll> me;
ll cek(ll aa,ll bb)
{
	te++;
	ll ii;
	for(ii=1;ii<=n;ii++)
	{
		if(aa<=ii&&ii<=bb)
			continue;
		if(d[a[ii]]==te)
			return 0;
		d[a[ii]]=te;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=a[i];
	}
	sort(x+1,x+1+n);
	for(i=1;i<=n;i++)
		me[x[i]]=i;
	for(i=1;i<=n;i++)
		a[i]=me[a[i]];
	has=1e18;
	if(cek(0,0))
	{
		cout<<0<<"\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		ll L=i,R=n,C;
		while(L<=R)
		{
			C=(L+R)/2;
			if(cek(i,C))
			{
				has=min(has,(C-i+1));
				R=C-1;
			}
			else
				L=C+1;
		}
	}
	cout<<has<<"\n";
}