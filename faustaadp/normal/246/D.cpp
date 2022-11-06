#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,i,a[101010],ta,tb,d[101010],j,has;
vector<ll> v[101010];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	has=1e18;
	for(i=1;i<=n;i++)has=min(has,a[i]);
	for(j=1;j<=m;j++)
	{
		cin>>ta>>tb;
		if(a[ta]==a[tb])continue;
		v[a[ta]].pb(a[tb]);
		v[a[tb]].pb(a[ta]);
	}
	for(i=1;i<=100000;i++)
	{
		sort(v[i].begin(),v[i].end());
		for(j=0;j<v[i].size();j++)
			if(j==0||v[i][j]!=v[i][j-1])
				d[i]++;
		if(d[has]<d[i])
			has=i;
	}
	cout<<has<<"\n";
}