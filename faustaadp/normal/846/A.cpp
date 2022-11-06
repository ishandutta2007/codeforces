#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010],hs,hz,j;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
			hs++;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			hz=1;
			for(j=1;j<i;j++)
			{
				if(a[j]==0)
					hz++;
			}
			for(j=i+1;j<=n;j++)
			{
				if(a[j]==1)
					hz++;
			}
			hs=max(hs,hz);
		}
	}
	cout<<hs<<"\n";
}