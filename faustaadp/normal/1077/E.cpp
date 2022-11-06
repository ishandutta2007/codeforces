#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[202020],te,x[202020],j,has;
ll cek(ll aa,ll bb)
{
	ll L=aa+1,R=te,C,H=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(x[C]>=bb)
		{
			H=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	return H;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		te++;
		for(j=i;j<=(n+1);j++)
		{
			if(a[i]!=a[j]||j==(n+1))
			{
				i=j-1;
				break;
			}
			else
				x[te]++;
		}
	}
	sort(x+1,x+1+te);
	for(i=1;i<=n;i++)
	{
		ll tem=i,hz=0,las=0;
		for(j=1;j<=n;j++)
		{
			las=cek(las,tem);
			if(las==-1)break ;
			hz+=tem;
			tem*=2;
		}
		has=max(has,hz);
	}
	cout<<has<<"\n";
}