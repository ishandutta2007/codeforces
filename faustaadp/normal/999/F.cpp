#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,k,i,ta,a[101010],b[101010],c[5050],d[5050][5050],has;
ll depe(ll aa,ll bb)
{
	if(bb==0)return 0;
	//cout<<aa<<" "<<bb<<"\n";
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=0;
		ll ii;
		for(ii=1;ii<=min(aa,k);ii++)
			d[aa][bb]=max(d[aa][bb],depe(aa-ii,bb-1)+c[ii]);
	}
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(i=1;i<=n*k;i++)
	{
		cin>>ta;
		a[ta]++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		b[ta]++;
	}
	for(i=1;i<=k;i++)cin>>c[i];
	memset(d,-1,sizeof(d));
	for(i=1;i<=100000;i++)
	{
		if(!a[i]||!b[i])continue;
		//cout<<a[i]<<" "<<b[i]<<"\n";
		has+=depe(a[i],b[i]);
	}
	cout<<has<<"\n";
}