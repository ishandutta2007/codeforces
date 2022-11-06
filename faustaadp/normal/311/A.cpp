#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	m-=n*(n-1)/2;
	if(m>=0)cout<<"no solution\n";
	else
	{
		for(i=1;i<=n;i++)
			cout<<i<<" "<<i*100000<<"\n";
	}
}