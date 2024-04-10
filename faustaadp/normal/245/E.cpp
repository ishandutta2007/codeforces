#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
ll n,i,has=1e18;
ll cek(ll aa)
{
	ll ii,H=aa,org=aa;
	for(ii=0;ii<n;ii++)
	{
		if(s[ii]=='+')org++;
		else org--;
		if(org<0)return 1e18;
		H=max(H,org);
	}
	return H;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<=2000;i++)
		has=min(has,cek(i));
	cout<<has<<"\n";
}