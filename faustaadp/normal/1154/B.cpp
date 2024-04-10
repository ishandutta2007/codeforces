#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[110],j;
ll cek(ll aa,ll bb)
{
	ll ii;
	for(ii=1;ii<=n;ii++)
		if((abs(a[ii]-bb)==aa)||(a[ii]==bb))
			continue;
		else 
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=0;i<=200;i++)
		for(j=0;j<=200;j++)
		{
			if(cek(i,j))
			{
				cout<<i<<"\n";
				return 0;
			}
		}
	cout<<-1<<"\n";
}