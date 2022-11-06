#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j;
vector<pair<ll,ll> > v;
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
	cin>>n>>m;
	if(m+1<n)
	{
		cout<<"Impossible\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(m==0)	break;
		for(j=i+1;j<=n;j++)
		{
			if(m==0)	break;
			if(fpb(i,j)!=1)
				continue;
			v.pb(mp(i,j));
			m--;
		}
	}
	if(m>0)
	{
		cout<<"Impossible\n";
		return 0;
	}
	cout<<"Possible\n";
	for(i=0;i<v.size();i++)
		cout<<v[i].fi<<" "<<v[i].se<<"\n";
}