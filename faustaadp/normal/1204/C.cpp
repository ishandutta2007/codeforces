#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[1010101],m,k,gab[1010101],j;
string s;
ll jar[110][110];
vector<ll> isi[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				jar[i][j]=1e18;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ll jum=0,cal=0;
		for(j=0;j<n;j++)
			if(s[j]=='1')
			{
				jar[i][j+1]=1;
			//	v[i].pb(j+1);
				//cout<<i<<" "<<j+1<<"\n";
				//isi[j+1].pb(i);
			}
	}
	ll ii;
	for(ii=1;ii<=n;ii++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				jar[i][j]=min(jar[i][j],jar[i][ii]+jar[ii][j]);
	cin>>m;
	for(i=1;i<=m;i++)
		cin>>a[i];
	ll akh=1;
	gab[1]=1;
	gab[m]=1;
	for(i=2;i<=m;i++)
	{
		//cout<<a[akh]<<" "<<a[i]<<"___"<<" "<<jar[a[akh]][a[i]]<<" "<<i-akh<<"_"<<a[i-1]<<"\n";
		if((jar[a[akh]][a[i]]!=(i-akh))||(a[i]==a[akh]))
		{
			gab[i-1]=1;
			akh=i-1;
		}
	}
	for(i=1;i<=m;i++)
		if(gab[i])
			k++;
	//k=m-k;
	cout<<k<<"\n";
	for(i=1;i<=m;i++)
		if(gab[i])
			cout<<a[i]<<" ";
}