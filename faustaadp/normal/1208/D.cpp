#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,p[202020],a[202020],x[202020];
vector<pair<ll,ll> > isi;
map<ll,ll> me;
ll nx[202020];
ll pv[202020];
ll ST[808080];
void upd(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(aa==bb)
	{
		ST[ee]=dd;
		if(dd==0)
		{
			ll ki=pv[aa];
			ll ka=nx[aa];
			nx[ki]=ka;
			pv[ka]=ki;
		}
	}
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ce)
			upd(aa,ce,cc,dd,ee*2);
		else
			upd(ce+1,bb,cc,dd,ee*2+1);
		ST[ee]=ST[ee*2]+ST[ee*2+1];
	}
}
void cari(ll aa,ll bb,ll cc,ll ee)
{
	if(aa==bb)
	{
		x[i]=nx[aa];
	}
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ST[ee*2])
			cari(aa,ce,cc,ee*2);
		else
			cari(ce+1,bb,cc-ST[ee*2],ee*2+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ll hz=0;
	for(i=1;i<=n;i++)
	{
		nx[i-1]=i;
		pv[i]=i-1;
		hz+=i;
		cin>>a[i];
		upd(0,n,i,i,1);
	}
	for(i=n;i>=1;i--)
	{
		cari(0,n,a[i],1);
		//cout<<pv[x[i]]<<"\n";
		upd(0,n,x[i],0,1);
	}
	for(i=1;i<=n;i++)
		if(i<n)
			cout<<x[i]<<" ";
		else
			cout<<x[i]<<"\n";
	// do
	// {
	// 	for(i=1;i<=n;i++)
	// 		cout<<p[i]<<" ";	
	// 	cout<<"\n";
	// 	cout<<cek()<<"\n\n";
	// 	for(i=1;i<=n;i++)
	// 	{
	// 		isi.pb(mp(p[n],x[n]));
	// 	}
	// }
	// while(next_permutation(p+1,p+1+n));
	// sort(isi.begin(),isi.end());
	// for(i=0;i<isi.size();i++)
	// 	cout<<isi[i].fi<<" "<<isi[i].se<<"__\n";
}