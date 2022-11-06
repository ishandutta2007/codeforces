#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,a[4040][4040],p[4040][4040],c[4040][4040],d[2][4040],j,I;
void cari(ll aa,ll bb,ll cc,ll dd)
{
	if(aa>bb)return ;
	ll ce=(aa+bb)/2;
	//cc=max(cc,aa);
	ll ii,OPT=-1;
	d[I][ce]=1e18;
	for(ii=cc;ii<=dd;ii++)
	{
		if(d[I][ce]>(c[ce][ii]+d[1-I][ii+1]))
		{
			OPT=ii;
			d[I][ce]=c[ce][ii]+d[1-I][ii+1];
		}
	}
	cari(aa,ce-1,cc,OPT);
	cari(ce+1,bb,OPT,dd);
}

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	getchar();
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			char c;
			c=getchar();
			a[i][j]=c-'0';
			c=getchar();
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
	for(i=1;i<=n;i++)d[0][i]=1e18;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			c[i][j]=(p[j][j]-p[j][i-1]-p[i-1][j]+p[i-1][i-1])/2;
	for(i=1;i<=k;i++)
	{
		I=i%2;
		cari(1,n,1,n);
	}
	cout<<d[k%2][1]<<"\n";
}