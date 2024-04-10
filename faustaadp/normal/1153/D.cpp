#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[303030],d[303030][2],BL[303030],ta,has=0;
vector<ll> v[303030];
ll depe(ll aa,ll bb)
{
	if(!BL[aa])return bb;
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=0;
		ll ii;
		if(bb==1)
		{
			if(a[aa]==0)
			{
				for(ii=0;ii<v[aa].size();ii++)
					d[aa][bb]+=depe(v[aa][ii],1);
			}
			else
			{
				ll sel=1e18;
				for(ii=0;ii<v[aa].size();ii++)
				{
					d[aa][bb]+=depe(v[aa][ii],0);
					sel=min(depe(v[aa][ii],1)-depe(v[aa][ii],0),sel);
				}
				d[aa][bb]+=sel;
			}
		}
		else
		{
			for(ii=0;ii<v[aa].size();ii++)
				d[aa][bb]+=depe(v[aa][ii],0);
		}
	}
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=n;i++)
	{
		cin>>ta;
		v[ta].pb(i);
		BL[ta]=1;
	}
	for(i=1;i<=n;i++)
		if(!BL[i])has++;
	memset(d,-1,sizeof(d));
	has-=depe(1,1);
	has++;
	//has=depe(1,1);
	cout<<has<<"\n";
}