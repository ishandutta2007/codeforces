#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[1010],b[1010],hs,hz,j,k,hv;
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(j=1;j<=m;j++)
		cin>>b[j];
	hs=LLONG_MAX;
	for(i=1;i<=n;i++)
	{
		hz=LLONG_MAX;
		hz=-hz;
		for(j=1;j<=m;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(k!=i)
				{
					hv=a[k]*b[j];
					hz=max(hz,hv);
				}
			}
		}
		hs=min(hs,hz);
	}
	cout<<hs<<"\n";
}