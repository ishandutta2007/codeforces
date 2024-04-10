#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,ma,h2;
pair<pair<ll,ll> ,ll> a[303030];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		a[i]=mp(mp(ta,-tb),i);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(-a[i].fi.se<=ma)
		{
			cout<<a[i].se<<" "<<h2<<"\n";
			return 0;
		}
		if(ma<-a[i].fi.se)
		{
			ma=-a[i].fi.se;
			h2=a[i].se;
		}
	}
	cout<<-1<<" "<<-1<<"\n";
}