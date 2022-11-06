#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,ta,has;
vector<pair<ll,ll> > isi;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		ll cst=0;
		while(ta>=1)
		{
			isi.pb(mp(ta,cst));
			cst++;
			ta/=2;
		}
		isi.pb(mp(0,cst));
	}
	sort(isi.begin(),isi.end());
	ll sz=isi.size();
	has=1e18;
	ll jum=0,hz=0;
	for(i=0;i<sz;i++)
	{
		if(i>0&&isi[i].fi==isi[i-1].fi)
		{
			jum++;
			hz+=isi[i].se;
		}
		else
		{
			jum=1;
			hz=isi[i].se;
		}
		if(jum==k)has=min(has,hz);
		//cout<<i<<" "<<isi[i].fi<<" "<<jum<<" "<<hz<<"\n";
	}
	cout<<has<<"\n";
}