#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,k,i,a[3030],tem[3030],L,R,C,has;
ll cek(ll aa)
{
	ll ii,H=0;
	for(ii=1;ii<=aa;ii++)tem[ii]=a[ii];
	sort(tem+1,tem+1+aa);
	if(aa%2==0)
	{
		for(ii=2;ii<=aa;ii+=2)
			H+=tem[ii];
	}
	else
	{
		for(ii=1;ii<=aa;ii+=2)
			H+=tem[ii];
	}
	//cout<<aa<<" "<<H<<" "<<k<<"\n";
	return (H<=k);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	//for(i=1;i<=n;i++)cek(i);
	L=0;
	R=n;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			has=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	cout<<has<<"\n";
}