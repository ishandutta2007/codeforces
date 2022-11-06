#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010101],hs;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=2;i<n;i++)
	{
		if(a[i-1]<a[i]&&a[i]>a[i+1])
			hs++;
		else
		if(a[i-1]>a[i]&&a[i]<a[i+1])
			hs++;
	}
	cout<<hs<<"\n";
}