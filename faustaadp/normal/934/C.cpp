#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[2020],d1[2020][2020],d2[2020][2020],j,hs;
ll dI(ll aa,ll bb)
{
	if(aa>bb)
		return 0;
	if(aa==bb)
		return 1;
	if(d1[aa][bb]==-1)
	{
		if(a[aa]==1)
			d1[aa][bb]=1+dI(aa+1,bb);
		else
		if(a[bb]==2)
			d1[aa][bb]=1+dI(aa,bb-1);
		else
			d1[aa][bb]=max(dI(aa+1,bb),dI(aa,bb-1));
	}
	return d1[aa][bb];
}
ll dD(ll aa,ll bb)
{
	if(aa>bb)
		return 0;
	if(aa==bb)
		return 1;
	if(d2[aa][bb]==-1)
	{
		if(a[aa]==2)
			d2[aa][bb]=1+dD(aa+1,bb);
		else
		if(a[bb]==1)
			d2[aa][bb]=1+dD(aa,bb-1);
		else
			d2[aa][bb]=max(dD(aa+1,bb),dD(aa,bb-1));
	}
	return d2[aa][bb];
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	memset(d1,-1,sizeof(d1));
	memset(d2,-1,sizeof(d2));
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			hs=max(hs,dI(1,i-1)+dD(i,j)+dI(j+1,n));
		}
	}
	cout<<hs<<"\n";
}