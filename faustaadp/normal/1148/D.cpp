#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],b[303030],las;
vector<pair<ll,ll> > A,B;
vector<ll> isiA,isiB,jaw;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)
		if(a[i]<b[i])
			A.pb(mp(b[i],i));
		else
		if(a[i]>b[i])
			B.pb(mp(b[i],i));
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	sort(B.begin(),B.end());
	las=1e18;
	for(i=0;i<A.size();i++)
	{
		if(las<=a[A[i].se])continue;
		isiA.pb(A[i].se);
		las=A[i].fi;
	}
	las=0;
	for(i=0;i<B.size();i++)
	{
		if(las>=a[B[i].se])continue;
		isiB.pb(B[i].se);
		las=B[i].fi;
	}
	if(isiA.size()>isiB.size())
		jaw=isiA;
	else
		jaw=isiB;
	ll js=jaw.size();
	cout<<js<<"\n";
	for(i=0;i<js;i++)
		if(i<(js-1))
			cout<<jaw[i]<<" ";
		else
			cout<<jaw[i]<<"\n";
}