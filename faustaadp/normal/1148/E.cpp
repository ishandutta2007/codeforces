#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],b[303030],hz,L,R,las,lz,j;
pair<ll,ll> A[303030];
vector<pair<pair<ll,ll>,ll> > isi;
vector<ll> isi1,isi2;
void gagal()
{
	cout<<"NO\n";
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		hz+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		hz-=b[i];
	}
	if(hz!=0)
		gagal();
	for(i=1;i<=n;i++)
		A[i]=mp(a[i],i);
	sort(A+1,A+1+n);
	sort(b+1,b+1+n);
	lz=0;
	for(i=1;i<=n;i++)
		if(b[i]>A[i].fi)
		{
			isi1.pb(i);
		}
		else
		if(b[i]<A[i].fi)
		{
			isi2.pb(i);
		}
	ll I1=isi1.size();
	ll I2=isi2.size();
	i=0;
	j=0;
	while(1)
	{
		while(i<I1&&A[isi1[i]].fi==b[isi1[i]])
			i++;
		while(j<I2&&A[isi2[j]].fi==b[isi2[j]])
			j++;
		//cout<<i<<" "<<j<<" "<<isi1[i]<<" "<<isi2[i]<<"\n";
		if(i>=I1||j>=I2)
			break;
		if(isi1[i]>isi2[j])
			gagal();
		ll tom;
		if(abs(b[isi1[i]]-A[isi1[i]].fi)<=abs(b[isi2[j]]-A[isi2[j]].fi))
			tom=abs(b[isi1[i]]-A[isi1[i]].fi);
		else
			tom=abs(b[isi2[j]]-A[isi2[j]].fi);
		isi.pb(mp(mp(A[isi1[i]].se,A[isi2[j]].se),tom));
		A[isi1[i]].fi+=tom;
		A[isi2[j]].fi-=tom;
	}
	//return 0;
	for(i=1;i<=n;i++)
		if(A[i].fi!=b[i])
			gagal();
	cout<<"YES\n";
	cout<<isi.size()<<"\n";
	for(i=0;i<isi.size();i++)
		cout<<isi[i].fi.fi<<" "<<isi[i].fi.se<<" "<<isi[i].se<<"\n";
}