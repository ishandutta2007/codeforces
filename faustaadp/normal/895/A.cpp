#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,hs,i,a[1010],p[1010],hz1,hz2,j;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	hs=360;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
			hs=min(hs,abs(360-(p[j]-p[i-1])-(p[j]-p[i-1])));
	}
	cout<<hs<<"\n";
}