#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j,a[1010][1010],b[1010][1010];
vector<pair<ll,ll> > isi;
void gagal()
{
	cout<<-1<<"\n";
	exit(0);
}
void upd(ll aa,ll bb)
{
	if(aa==n||bb==m)
		gagal();
	b[aa][bb]=0;
	b[aa+1][bb]=0;
	b[aa][bb+1]=0;
	b[aa+1][bb+1]=0;
	isi.pb(mp(aa,bb));
}
ll cak(ll aa,ll bb)
{
	if(a[aa][bb]==0)return 0;
	if(a[aa+1][bb]==0)return 0;
	if(a[aa][bb+1]==0)return 0;
	if(a[aa+1][bb+1]==0)return 0;
	b[aa][bb]=1;
	b[aa+1][bb]=1;
	b[aa][bb+1]=1;
	b[aa+1][bb+1]=1;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	ll ada=0;
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			if(cak(i,j))
				isi.pb(mp(i,j));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==1&&b[i][j]==0)
				gagal();
	ll sz=isi.size();
	cout<<sz<<"\n";
	for(i=0;i<sz;i++)
		cout<<isi[i].fi<<" "<<isi[i].se<<"\n";
}