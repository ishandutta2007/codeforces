#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],d[2020202][2],has,ta;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[i]=(a[i-1]^ta);
		//cout<<i<<" "<<a[i]<<"\n";
	}
	for(i=0;i<=n;i++)
	{
		has+=d[a[i]][i%2];
		d[a[i]][i%2]++;
	}
	cout<<has<<"\n";
}