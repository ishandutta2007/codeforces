#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[1010],b[1010];
vector<ll> ba,ko;
vector<pair<ll,ll> > h;
ll tanya(ll aa,ll bb,ll cc,ll dd)
{
	cout<<"? "<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<endl;
	ll H;
	cin>>H;
	return H;
}
ll cek(ll aa,ll bb)
{
	return (tanya(aa,bb,aa,bb)%2);
}
ll cek1(ll aa,ll bb)
{
	return (tanya(bb,1,bb,aa)%2);
}
ll cek2(ll aa,ll bb)
{
	return (tanya(1,bb,aa,bb)%2);
}
int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)a[i]=tanya(i,1,i,n);
	for(i=1;i<=n;i++)b[i]=tanya(1,i,n,i);
	for(i=1;i<=n;i++)if((a[i]%2)==1)ba.pb(i);
	for(i=1;i<=n;i++)if((b[i]%2)==1)ko.pb(i);
	if(ba.size()==2&&ko.size()==2)
	{
		if(cek(ba[0],ko[0]))h.pb(mp(ba[0],ko[0]));
		if(cek(ba[0],ko[1]))h.pb(mp(ba[0],ko[1]));
		if(cek(ba[1],ko[0]))h.pb(mp(ba[1],ko[0]));
		if(cek(ba[1],ko[1]))h.pb(mp(ba[1],ko[1]));
	}
	else
	if(ba.size()==2)
	{
		ll L=1,R=n,C,H;
		while(L<=R)
		{
			C=(L+R)/2;
			if(cek1(C,ba[0]))
			{	
				H=C;
				R=C-1;
			}
			else
				L=C+1;
		}
		ko.pb(H);
		if(cek(ba[0],ko[0]))h.pb(mp(ba[0],ko[0]));
		if(cek(ba[1],ko[0]))h.pb(mp(ba[1],ko[0]));
	}
	else
	{
		ll L=1,R=n,C,H;
		while(L<=R)
		{
			C=(L+R)/2;
			if(cek2(C,ko[0]))
			{	
				H=C;
				R=C-1;
			}
			else
				L=C+1;
		}
		ba.pb(H);
		if(cek(ba[0],ko[0]))h.pb(mp(ba[0],ko[0]));
		if(cek(ba[0],ko[1]))h.pb(mp(ba[0],ko[1]));
	}
	cout<<"! "<<h[0].fi<<" "<<h[0].se<<" "<<h[1].fi<<" "<<h[1].se<<endl;
}