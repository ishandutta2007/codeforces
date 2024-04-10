#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,a[1010],mi;	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta;
		a[ta]++;
	}
	mi=1e18;
	for(i=1;i<=n;i++)
	{
		mi=min(mi,a[i]);
	}
	cout<<mi<<"\n";
}