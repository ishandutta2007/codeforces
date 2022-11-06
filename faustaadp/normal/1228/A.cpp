#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,l,r,has,i;
ll cek(ll aa)
{
	string z=to_string(aa);
	sort(z.begin(),z.end());
	ll ii,sz=z.length();
	for(ii=1;ii<sz;ii++)
		if(z[ii]==z[ii-1])
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	has=-1;
	cin>>l>>r;
	for(i=l;i<=r;i++)
	{
		if(cek(i))
			has=i;
	}
	cout<<has<<"\n";
}