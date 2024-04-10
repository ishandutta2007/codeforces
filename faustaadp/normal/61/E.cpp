#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,a[1010101],R[1010101],has,ST[4040404];
pair<ll,ll> A[1010101];
void upd(ll aa,ll bb,ll cc,ll ee)
{
	if(aa==bb)ST[ee]=1;
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ce)
			upd(aa,ce,cc,ee*2);
		else
			upd(ce+1,bb,cc,ee*2+1);
		ST[ee]=ST[ee*2]+ST[ee*2+1];
	}
}
ll que(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(bb<cc||dd<aa)return 0;
	else
	if(cc<=aa&&bb<=dd)
		return ST[ee];
	else
	{
		ll ce=(aa+bb)/2;
		return que(aa,ce,cc,dd,ee*2)+que(ce+1,bb,cc,dd,ee*2+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)A[i]=mp(a[i],i);
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		R[A[i].se]=que(1,n,A[i].se,n,1);
		upd(1,n,A[i].se,1);
	}
	memset(ST,0,sizeof(ST));
	reverse(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		has+=R[A[i].se]*que(1,n,1,A[i].se,1);
		upd(1,n,A[i].se,1);
	}
	cout<<has<<"\n";
}