#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,bo,h1,h2,hz,hs,h3;
pair<ll,ll> a[1010];
bool cm(pair<ll,ll> aa,pair<ll,ll> bb)
{
	ll h1=aa.fi*bb.se;
	ll h2=aa.se*bb.fi;
	return h1<h2;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[i]=mp(ta,pow(2,i-1));
	}
	sort(a+1,a+1+n,cm);
	h1=10e17;
	while(hz<m)
	{
	//	cout<<hz<<"\n";
		bo=1;
		for(i=1;i<=n;i++)
		{
			if((m-hz)/a[i].se!=0)
			{
				if(bo)
				{
					bo=0;
					h2=i;
					h3=(m-hz)/a[i].se;
				}
			}
			else
			{
				h1=min(h1,hs+a[i].fi);
			}
			//v.pb(ceil((double)(m-hz)/(double)a[i].se)*a[i].fi);
		}
		hs+=a[h2].fi*h3;
		hz+=a[h2].se*h3;
	}
	cout<<min(h1,hs)<<"\n";
}