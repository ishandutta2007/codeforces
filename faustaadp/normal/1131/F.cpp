#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,p[202020],ki[202020],ka[202020],ta,tb,taa,tbb,nx[202020];
void gab(ll aa,ll bb)
{
	nx[ka[aa]]=ki[bb];
	ka[aa]=ka[bb];
	ki[bb]=ki[aa];
	p[aa]=bb;
}
ll car(ll aa)
{
	if(p[aa]==aa)return aa;
	else return p[aa]=car(p[aa]);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=n;i++)ki[i]=i;
	for(i=1;i<=n;i++)ka[i]=i;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		taa=car(ta);
		tbb=car(tb);
		//cout<<taa<<" "<<tbb<<"\n";
		gab(taa,tbb);
	}
	ll tem=ki[car(1)];
	for(i=1;i<=n;i++)
	{
		cout<<tem;
		tem=nx[tem];
		if(i<n)cout<<" ";
		else cout<<"\n";
	}
}