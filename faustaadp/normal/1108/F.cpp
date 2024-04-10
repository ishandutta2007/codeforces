#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,has,p[202020],ta,tb,tc,awal,taa,tbb,j;
pair<ll,pair<ll,ll> > A[202020];
ll car(ll aa)
{
	if(p[aa]==aa)return aa;
	else
	{
		ll tem=car(p[aa]);
		p[aa]=tem;
		return tem;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	has=-(n-1);
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb>>tc;
		A[i]=mp(tc,mp(ta,tb));
	}
	awal=1;
	sort(A+1,A+1+m);
	for(i=1;i<=m;i++)
	{
		ta=A[i].se.fi;
		tb=A[i].se.se;
		taa=car(ta);
		tbb=car(tb);
		if(taa!=tbb)has++;
		if(i==m||A[i].fi!=A[i+1].fi)
		{
			for(j=awal;j<=i;j++)
			{
				ta=A[j].se.fi;
				tb=A[j].se.se;
				taa=car(ta);
				tbb=car(tb);
				if(taa!=tbb)p[taa]=tbb;
			}
			awal=i+1;
		}
	}
	cout<<has<<"\n";
}