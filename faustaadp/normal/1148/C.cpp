#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,nn,i,a[303030],pos[303030];
vector<pair<ll,ll> > isi;
void tukar(ll aa,ll bb)
{
	swap(a[aa],a[bb]);
	pos[a[aa]]=aa;
	pos[a[bb]]=bb;
	isi.pb(mp(aa,bb));
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	nn=n/2;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		pos[a[i]]=i;
	for(i=1;i<=nn;i++)
	{
		if(pos[i]==i)
			continue;
		if(abs(i-pos[i])<nn)
		{
			if(pos[i]<=nn)
			{
				ll tom=pos[i];
				tukar(i,n);
				tukar(tom,n);
				tukar(i,n);
			}
			else
			{
				ll tom=pos[i];
				tukar(i,n);
				tukar(1,tom);
				tukar(1,n);
				tukar(1,tom);
				tukar(i,n);
			}
		}
		else
			tukar(i,pos[i]);
	}
	for(i=nn+1;i<=n;i++)
	{
		if(pos[i]==i)
			continue;
		ll tom=pos[i];
		tukar(1,i);
		tukar(1,pos[i]);
		tukar(1,i);
	}
	cout<<isi.size()<<"\n";
	for(i=0;i<isi.size();i++)
		cout<<isi[i].fi<<" "<<isi[i].se<<"\n";
	//for(i=1;i<=n;i++)
	//	cout<<a[i]<<"\n";
}