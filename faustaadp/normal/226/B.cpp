#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],p[101010],j;
unsigned ll jaw[101010];
ll q,x;
ll PF(ll aa,ll bb)
{
	bb=min(bb,n);
	return p[bb]-p[aa-1];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(i=1;i<=100000;i++)
	{
		unsigned ll hz=0;
		ll K=0; 
		ll X=1;
		for(j=2;j<=n;j+=X)
		{
			X*=i;
			K++;
			hz+=PF(j,j+X-1)*K;
		//	if(i==2)
		//	cout<<i<<" "<<j<<" "<<X<<"\n";
		}
		jaw[i]=hz;
	}
	cin>>q;
	while(q--) 
	{
		cin>>x;
		cout<<jaw[x];
		if(q)cout<<" ";
		else cout<<"\n";
	}
}