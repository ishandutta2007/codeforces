#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,m,has,z,a[1010][1010],p[1010],j;
vector<pair<ll,ll> > x;
void cek(ll aa)
{
	if(aa==z)
	{
		ll ii,jj,hz=0;
		for(ii=0;ii<n;ii++)
		{
			ll ma=0;
			for(jj=0;jj<z;jj++)
				ma=max(ma,a[(p[jj]+ii)%n][x[jj].se]);
		//	cout<<ii<<" "<<ma<<"\n";
			hz+=ma;
		}
		//cout<<hz<<"___\n";
		has=max(has,hz);
		return ;
	}
	else
	{
		ll ii;
		for(ii=0;ii<n;ii++)
		{
			p[aa]=ii;
			cek(aa+1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--)
	{
		x.clear();
		has=0;
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];
		for(i=1;i<=m;i++)
		{
			ll ma=0;
			for(j=0;j<n;j++)
				ma=max(ma,a[j][i]);
			x.pb(mp(ma,i));
		}
		z=min(m,4LL);
		sort(x.begin(),x.end());
		reverse(x.begin(),x.end());
		has=0;
		cek(0);
		cout<<has<<"\n";
	}
}