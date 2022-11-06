#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,k,m,i,a[101010],j;
vector<ll> v[101010];

int main()
{
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		v[a[i]%m].pb(a[i]);
		if(v[a[i]%m].size()==k)
		{
			cout<<"Yes\n";
			for(j=0;j<v[a[i]%m].size();j++)
			{
				if(j==0)
					cout<<v[a[i]%m][j];
				else
					cout<<" "<<v[a[i]%m][j];
			}
			cout<<"\n";
			return 0;
		}
	}
	cout<<"No\n";
}