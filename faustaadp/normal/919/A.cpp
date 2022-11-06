#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,m;
pair<ll,ll> a[1010101];
double d;
bool cem(pair<ll,ll> aa,pair<ll,ll> bb)
{
	return (aa.fi*bb.se)<(bb.fi*aa.se);
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		a[i]=mp(ta,tb);
	}
	sort(a+1,a+1+n,cem);
	d=(double)m*(double)a[1].fi/(double)a[1].se;
	cout<<fixed<<setprecision(8)<<d<<"\n";
}