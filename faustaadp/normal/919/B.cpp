#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,m,tt;
pair<ll,ll> a[1010101];
double d;
vector<ll> v;
void rmt(ll aa,string bb)
{
	if(bb.length()>8)
		return ;
	if(aa==0)
		v.pb(stoll(bb));
	ll ii;
	for(ii=0;ii<=aa;ii++)
		rmt(aa-ii,bb+char(ii+'0'));
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rmt(9,"1");
	rmt(8,"2");
	rmt(7,"3");
	rmt(6,"4");
	rmt(5,"5");
	rmt(4,"6");
	rmt(3,"7");
	rmt(2,"8");
	rmt(1,"9");
	sort(v.begin(),v.end());
	cin>>n;
	cout<<v[n-1]<<"\n";
}