#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],j,has,z,d[2020202];
ll cek(ll aa)
{
	if(d[aa]==-1)
	{
		ll L=1,R=n,C,H=-2;
		while(L<=R)
		{
			C=(L+R)/2;
			if(a[C]<aa)
			{
				H=a[C];
				L=C+1;
			}
			else
				R=C-1;
		}
		d[aa]=H;
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	memset(d,-1,sizeof(d));
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(i!=1&&a[i-1]==a[i])continue;
		for(j=a[i]*2;j<=2000000;j+=a[i])
		{
			z=cek(j);
			if(z==-2||j-a[i]>=z)continue;
		//	cout<<a[i]<<" "<<j<<" "<<z<<"\n";
			has=max(has,z-(j-a[i]));
		}
	}
	cout<<has<<"\n";
}