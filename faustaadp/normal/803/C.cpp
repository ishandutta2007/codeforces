#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,x,z,i,j,c;
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	x=k*(k+1LL)/2LL;
	if(x>n||k>1000000)
	{
		cout<<-1<<"\n";
		return 0;
	}
	for(i=1;i<=sqrt(n);i++)
	{
		if((n%i)!=0)continue;
		v.pb(i);
		v.pb(n/i);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		c=v[i];
		if((n/c)<x)continue;
		z=x*c;
		if(z>n)continue;
		if((n%c)!=0)continue;
		for(j=1;j<k;j++)
		{
			cout<<(j*c)<<" ";
			n-=(j*c);
		}
		cout<<n<<"\n";
		return 0;
	}
	cout<<-1<<"\n";
}