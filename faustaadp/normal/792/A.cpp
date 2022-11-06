#include<bits/stdc++.h>
using namespace std;
long long n,i,a[2020202],mi=20000000000,hs;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n-1;i++)
	{
		mi=min(mi,abs(a[i+1]-a[i]));
	}
	for(i=0;i<n-1;i++)
	{
		if(abs(a[i+1]-a[i])==mi)
		{
			hs++;
		}
	}
	cout<<mi<<" "<<hs<<endl;
}