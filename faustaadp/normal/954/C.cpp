#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],lom;
map<ll,ll> me;
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<"YES\n1000000000 1\n";
		return 0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		if(me[abs(a[i]-a[i+1])]==0)
		{
			me[abs(a[i]-a[i+1])]=1;
			v.pb(abs(a[i]-a[i+1]));
		}
		if(a[i]==a[i+1])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	sort(v.begin(),v.end());
	if(v.size()>2)
	{
		cout<<"NO\n";
		return 0;
	}
	if(v[0]==1&&v.size()==1)
		cout<<"YES\n1000000000 1\n";
	else
	{
		if(v.size()==2&&v[0]!=1)
		{
			cout<<"NO\n";
			return 0;
		}
		lom=v[v.size()-1];
		for(i=1;i<n;i++)
		{
			if((a[i]+1==a[i+1]&&a[i]%lom==0)||(a[i]-1==a[i+1]&&a[i]%lom==1))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		cout<<"YES\n1000000000 "<<lom<<"\n";
				
	}
}