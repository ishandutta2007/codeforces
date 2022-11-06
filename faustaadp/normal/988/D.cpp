#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],j,du[35],adaa,duaa;
vector<ll> malas[35];
bool ada(ll aa)
{
	ll L=1,R=n,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(a[C]==aa)
			return 1;
		else
		if(a[C]>aa)
			R=C-1;
		else
			L=C+1;
	}
	return 0;
}
bool mager(ll aa,ll bb)
{
	ll L=0,R=(ll)malas[aa].size()-1,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(malas[aa][C]==bb)
			return 1;
		else
		if(malas[aa][C]>bb)
			R=C-1;
		else
			L=C+1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	du[0]=1;
	for(i=1;i<=32;i++)
		du[i]=du[i-1]*2;	
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		//ada[a[i]]=1;
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		for(j=0;j<=30;j++)
			if(ada(a[i]+du[j]))
			{
				adaa=i;
				duaa=a[i]+du[j];
				malas[j].pb(a[i]);
				//punya[j][a[i]]=1;
			}
	for(i=1;i<=n;i++)
		for(j=0;j<=30;j++)
			if(mager(j,a[i]+du[j]))
			{
				cout<<3<<"\n";
				cout<<a[i]<<" "<<a[i]+du[j]<<" "<<a[i]+du[j+1]<<"\n";
				return 0;
			}
	if(adaa)
	{
		cout<<2<<"\n"<<a[adaa]<<" "<<duaa<<"\n";
		return 0;
	}
	cout<<1<<"\n"<<a[1]<<"\n";
	
}