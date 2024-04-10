#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,i,a[1010][1010],j;
pair<ll,ll> x[1010];
ll y[1010][1010],z[1010][1010];
ll Y[1010],Z[1010],te;
ll hey(ll aa,ll bb)
{
	ll H=max(Y[aa],Z[bb]);
//	return H;
	if(y[aa][bb]<z[aa][bb])
		H=max(H,(z[aa][bb]-y[aa][bb])+Y[aa]);
	else 
		H=max(H,(y[aa][bb]-z[aa][bb])+Z[bb]);
	return H;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
	{
		te=0;
		for(j=1;j<=m;j++)
			x[j]=mp(a[i][j],j);
		sort(x+1,x+1+m);
		for(j=1;j<=m;j++)
		{
			if(j>1&&x[j].fi==x[j-1].fi)
			{
				y[i][x[j].se]=te;
				continue;
			}
			te++;
			y[i][x[j].se]=te;
		}
		Y[i]=te;
	}
	for(i=1;i<=m;i++)
	{
		te=0;
		for(j=1;j<=n;j++)
			x[j]=mp(a[j][i],j);
		sort(x+1,x+1+n);
		for(j=1;j<=n;j++)
		{
			if(j>1&&x[j].fi==x[j-1].fi)
			{
				z[x[j].se][i]=te;
				continue;
			}
			te++;
			z[x[j].se][i]=te;
		}
		Z[i]=te;
	}
//	for(i=1;i<=n;i++)
//		for(j=1;j<=m;j++)
//			cout<<i<<" "<<j<<" "<<y[i][j]<<"\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(j<m)cout<<hey(i,j)<<" ";
			else cout<<hey(i,j)<<"\n";
}