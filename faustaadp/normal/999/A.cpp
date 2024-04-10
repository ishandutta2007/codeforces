#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,a[101010],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]<=k)
		{
			a[i]=1e18;
			has++;
		}
		else
			break;
	}
	for(i=n;i>=1;i--)
	{
		if(a[i]<=k)
		{
			a[i]=1e18;
			has++;
		}
		else
			break;
	}
	cout<<has<<"\n";
}