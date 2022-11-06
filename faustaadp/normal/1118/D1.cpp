#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[202020],has;
ll cek(ll aa)
{
	ll ii,te1=0,K=0,H=0;
	for(ii=1;ii<=n;ii++)
	{
		te1++;
		if(te1>aa)
		{
			te1=1;
			K++;
		}
		H+=max(0LL,a[ii]-K);
	}
	return H;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	ll L=1,R=n,C;
	has=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C)>=m)
		{
			has=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	cout<<has<<"\n";
}