#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,m,i,nn,a[10][10101],ne[10],hs,l,r,c;
vector<ll> v[10];
void rmt(ll aa,ll bb,ll cc)
{
	if(bb>=ne[aa])
	{
	//	cout<<aa<<" "<<cc<<"\n";
		v[aa].pb(cc%m);
		return ;
	}
	rmt(aa,bb+1,cc+a[aa][bb+1]);
	rmt(aa,bb+1,cc);
}
int main()
{
	cin>>n>>m;
	nn=n/2;
	for(i=1;i<=nn;i++)
		cin>>a[0][i];
	for(i=nn+1;i<=n;i++)
		cin>>a[1][i-nn];
	ne[0]=nn;
	ne[1]=n-nn;
	rmt(0,0,0);
	rmt(1,0,0);
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	for(i=0;i<v[0].size();i++)
	{
		hs=max(hs,v[0][i]);
		l=0;
		r=v[1].size()-1;
		while(l<=r)
		{
			c=(l+r)/2;
			if(v[0][i]+v[1][c]<m)
			{
				hs=max(hs,v[0][i]+v[1][c]);
				l=c+1;
			}
			else
				r=c-1;
		}
	}
	cout<<hs<<"\n";
}