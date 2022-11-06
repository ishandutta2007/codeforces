#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,ta,d[202020],las[202020],has,ma,hz,i,j;
vector<ll> L[202020];
vector<ll> R[202020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(d[ta]==0)
			L[i].pb(ta);
		d[ta]++;
		las[ta]=i;
	}
	for(i=1;i<=200000;i++)
		if(las[i])
			R[las[i]].pb(i);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<L[i].size();j++)
		{
			hz++;
			has+=d[L[i][j]];
			ma=max(ma,d[L[i][j]]);
		}
		for(j=0;j<R[i].size();j++)
		{
			hz--;
		}
		if(hz==0)
		{
			has-=ma;
			ma=0;
		}
	}
	cout<<has<<"\n";
}