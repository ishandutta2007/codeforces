#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j,a[101010],L[330],R[330],tem,z,has,k,I,J,ma[101010],mi[101010],cal1[101010],cal2[101010],bed[101010],te;
vector<ll> x;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>L[i]>>R[i];
		bed[L[i]-1]=1;
		bed[R[i]]=1;
	}
	bed[n]=1;
	for(i=1;i<=n;i++)mi[i]=1e18;
	for(i=1;i<=n;i++)ma[i]=-1e18;
	te=1;
	for(i=1;i<=n;i++)
	{
		mi[te]=min(a[i],mi[te]);
		ma[te]=max(a[i],ma[te]);
		if(mi[te]==a[i])cal1[te]=i;
		if(ma[te]==a[i])cal2[te]=i;
		if(bed[i]==1)te++;
	}
	for(i=1;i<te;i++)
		for(j=1;j<te;j++)
		{
			//if(i==j)continue;
			tem=a[cal2[j]]-a[cal1[i]];
			for(k=1;k<=m;k++)
			{
				z=0;
				if(L[k]<=cal1[i]&&cal1[i]<=R[k])z++;
				if(L[k]<=cal2[j]&&cal2[j]<=R[k])z--;
				if(z==1)tem++;
			}
			has=max(has,tem);
			if(has==tem)
			{
				I=i;
				J=j;
			}
		}
	cout<<has<<"\n";
	for(k=1;k<=m;k++)
	{
		z=0;
		if(L[k]<=cal1[I]&&cal1[I]<=R[k])z++;
		if(L[k]<=cal2[J]&&cal2[J]<=R[k])z--;
		if(z==1)x.pb(k);
	}
	ll XS=x.size();
	cout<<XS<<"\n";
	for(i=0;i<XS;i++)
		if(i<(XS-1))cout<<x[i]<<" ";
		else cout<<x[i]<<"\n";
}