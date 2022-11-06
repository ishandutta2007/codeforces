#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[101010],c[101010],te,has,ta,tb,beli;
pair<ll,ll> A[101010];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)A[i]=mp(c[i],i);
	te=1;
	sort(A+1,A+1+n);
	while(m--)
	{
		has=0;
		cin>>ta>>tb;
		beli=min(tb,a[ta]);
		has+=beli*c[ta];
		tb-=beli;
		a[ta]-=beli;
		while(tb>0)
		{
			if(te==(n+1))break;
			beli=min(tb,a[A[te].se]);
			has+=beli*c[A[te].se];
			tb-=beli;
			a[A[te].se]-=beli;
			if(a[A[te].se]==0)te++;
			//cout<<"A "<<tb<<" "<<te<<" "<<A[te].se<<<<"\n";
		}
		if(tb>0)has=0;
		cout<<has<<"\n";
	//	if(te==(n+1))break;
	}
	//cout<<has<<"\n";
}