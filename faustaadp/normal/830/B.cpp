#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[101010],pos,has,j,isi;
vector<ll> v[101010];
ll BIT[101010];
void upd(ll aa,ll bb)
{
	ll ii;
	for(ii=aa;ii<=n;ii+=(ii&(-ii)))
		BIT[ii]+=bb;
}
ll que(ll aa)
{
	ll ii,H=0;
	for(ii=aa;ii>0;ii-=(ii&(-ii)))
		H+=BIT[ii];
	return H;
}
void pindah(ll aa)
{
	// cout<<aa<<"\n";
	// cout<<aa<<" "<<que(aa)<<"  "<<pos<<" "<<que(pos)<<"\n";
	if(pos<=aa)
		has+=(que(aa)-que(pos));
	else
		has+=(que(aa)-que(pos)+isi);
	// cout<<i<<" "<<has<<"_\n";
	isi--;
	// if(i!=1)
	upd(aa,-1);
	pos=aa;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	isi=n;
	for(i=1;i<=n;i++)
	{
		upd(i,1);
		cin>>a[i];
		v[a[i]].pb(i);
	}
	has=1;
	pos=1;
	for(i=1;i<=100000;i++)
	{
		if(v[i].empty())continue;
		ll L=0,R=v[i].size()-1,C;
		ll mulai=0;
		while(L<=R)
		{
			C=(L+R)/2;
			if(pos<=v[i][C])
			{
				mulai=C;
				R=C-1;
			}
			else
				L=C+1;
		}
		for(j=mulai;j<v[i].size();j++)
			pindah(v[i][j]);
		for(j=0;j<mulai;j++)
			pindah(v[i][j]);
	}
	cout<<has<<"\n";
}