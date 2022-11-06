#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[10101010],j,k,tt,hz,hs;
int main()
{
	cin>>n;
	for(i=1;i<=n*2;i++)
		cin>>a[i];
	sort(a+1,a+1+n*2);
	hs=pow(10,18);
	for(i=1;i<=n*2;i++)
	{
		for(j=i+1;j<=n*2;j++)
		{
			hz=0;
			tt=1;
			for(k=1;k<=n*2;k++)
			{
				if(k==i||k==j)
					continue;
				tt=tt*-1;
				hz=hz+tt*a[k];
			}
			hs=min(hz,hs);
		}
	}
	cout<<hs<<"\n";
}