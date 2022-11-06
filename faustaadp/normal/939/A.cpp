#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,f[101010];
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>f[i];
	for(i=1;i<=n;i++)
	{
		if(f[f[f[i]]]==i)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}