#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,tc;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta>tc)
		{
			//cout<<ta<<" "<<tb<<"\n";
			cout<<"NO\n";
			return 0;
		}
		cin>>tb;
		tc=max(tb,tc);
	}
	if(tc<m)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
}