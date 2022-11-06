#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,hz,has,x[101010];
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		hz+=ta;
		v.pb(hz);
	}
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
	{
		if(i==0||v[i]!=v[i-1])x[i]=1;
		else 
		{
			x[i]=x[i-1]+1;
			has=max(has,x[i]);
		}
		has=max(has,x[i]);
	}
	has=n-has;
	cout<<has<<"\n";
}