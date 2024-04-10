#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,a[101010],ta,tb,q,hz;
struct tree
{
	ll fpb,mi,jumi;
} ST[404040];
ll FPB(ll aa,ll bb)
{
	if(bb==0)return aa;
	else return FPB(bb,aa%bb);
}
void upd(ll aa,ll bb,ll ee)
{
	if(aa==bb)
	{
		ST[ee].fpb=a[aa];
		ST[ee].mi=a[aa];
		ST[ee].jumi=1;
	}
	else
	{
		ll ce=(aa+bb)/2;
		upd(aa,ce,ee*2);
		upd(ce+1,bb,ee*2+1);
		ST[ee].mi=min(ST[ee*2].mi,ST[ee*2+1].mi);
		ST[ee].fpb=FPB(ST[ee*2].fpb,ST[ee*2+1].fpb);
		ST[ee].jumi=0;
		if(ST[ee].mi==ST[ee*2].mi)ST[ee].jumi+=ST[ee*2].jumi;
		if(ST[ee].mi==ST[ee*2+1].mi)ST[ee].jumi+=ST[ee*2+1].jumi;
	}
}
ll quemi(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(bb<cc||dd<aa)return 1e18;
	else
	if(cc<=aa&bb<=dd)return ST[ee].mi;
	else
	{
		ll ce=(aa+bb)/2;
		return min(quemi(aa,ce,cc,dd,ee*2),quemi(ce+1,bb,cc,dd,ee*2+1));
	}
}
ll quefpb(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(bb<cc||dd<aa)return 0;
	else
	if(cc<=aa&bb<=dd)return ST[ee].fpb;
	else
	{
		ll ce=(aa+bb)/2;
		return FPB(quefpb(aa,ce,cc,dd,ee*2),quefpb(ce+1,bb,cc,dd,ee*2+1));
	}
}
pair<ll,ll> quejumi(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(bb<cc||dd<aa)return mp(0,1e18);
	else
	if(cc<=aa&bb<=dd)return mp(ST[ee].jumi,ST[ee].mi);
	else
	{
		ll ce=(aa+bb)/2;
		pair<ll,ll> L=quejumi(aa,ce,cc,dd,ee*2),R=quejumi(ce+1,bb,cc,dd,ee*2+1);
		ll tempe=0,mii=min(L.se,R.se);
		if(L.se==mii)tempe+=L.fi;
		if(R.se==mii)tempe+=R.fi;
		return mp(tempe,mii);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	upd(1,n,1);
	cin>>q;
	while(q--)
	{
		cin>>ta>>tb;
		hz=tb-ta+1;
		if(quemi(1,n,ta,tb,1)==quefpb(1,n,ta,tb,1))hz-=quejumi(1,n,ta,tb,1).fi;
		cout<<hz<<"\n";
	}
}