#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,a[1010101],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		ll mi=1e18;
		has=0;
		for(i=n;i>=1;i--)
		{
			if(mi<a[i])
				has++;
			mi=min(mi,a[i]);
		}
		cout<<has<<"\n";
	}
}