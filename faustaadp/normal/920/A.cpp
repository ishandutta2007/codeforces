#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,m,i,a[101010],hs,j,hz;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		hs=0;
		for(i=1;i<=n;i++)
		{
			hz=10e17;
			for(j=1;j<=m;j++)
			{
				hz=min(hz,abs(a[j]-i)+1);
			}
			hs=max(hs,hz);
		}
		cout<<hs<<"\n";
	}
}