#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i;
string s;
vector<ll> a;
bool b[1010101];
ll rmt(string zz)
{
	ll hh=0,ii;
	for(ii=zz.length()-1;ii>=0;ii--)
	{
		if(zz[ii]=='1')
			hh+=(1<<(zz.length()-1-ii));
	}
	return hh;
}
int main()
{
	cin>>n;
	s="1";
	while(1)
	{
		//a.pb(rmt(s));
		//cout<<rmt(s)<<"\n";
		if(rmt(s)<=100000)
			b[rmt(s)]=1;
		if(rmt(s)>10000000)
			break;
		s=s+"0";
		s="1"+s;
	}
	for(i=n;i>=1;i--)
	{
		if(n%i==0&&b[i]==1)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
}