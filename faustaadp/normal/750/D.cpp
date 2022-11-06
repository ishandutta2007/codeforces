#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,hs,i,a[1010],d[500][500],dx[10]={0,1,1,0,-1,-1,-1,0,1},dy[10]={0,0,1,1,1,0,-1,-1,-1};
bool b[500][500][10][40];
ll rct1(ll aa)
{
	if(aa==8)
		return 1;
	else
		return aa+1;
}
ll rct2(ll aa)
{
	if(aa==1)
		return 8;
	else
		return aa-1;
}
pair<ll,ll> jln(ll aa,ll bb,ll cc,ll dd)
{
	ll hh=a[dd],ii;
	ll xx=aa,yy=bb;
	for(ii=1;ii<=hh;ii++)
	{
		xx+=dx[cc];
		yy+=dy[cc];
		if(d[xx][yy]==0)
		{
			d[xx][yy]=1;
			hs++;
		}
	}
	return mp(xx,yy);
}
void rmt(ll aa,ll bb,ll cc,ll dd)
{
	if(b[aa][bb][cc][dd]==0&&dd<=n)
	{
		//cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<"\n";
		b[aa][bb][cc][dd]=1;
		pair<ll,ll> pp;
		pp=jln(aa,bb,cc,dd);
		rmt(pp.fi,pp.se,rct1(cc),dd+1);
		rmt(pp.fi,pp.se,rct2(cc),dd+1);
	}
	
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	rmt(200,200,1,1);
	cout<<hs<<"\n";
}