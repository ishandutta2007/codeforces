#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,m,i,ta,tb,has,j;
string s[101010],z;
unordered_map<string,ll> co;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		co[s[i]]=ta;
	}
	for(i=1;i<=k;i++)
	{
		vector<ll> v;
		ll mi=1e18;
		cin>>ta;
		for(j=0;j<ta;j++)
		{
			cin>>tb;
			v.pb(tb);
			mi=min(mi,co[s[tb]]);
		}
		for(j=0;j<ta;j++)
			co[s[v[j]]]=mi;
	}
	for(i=1;i<=m;i++)
	{
		cin>>z;
		has+=co[z];
	}
	cout<<has<<"\n";
}