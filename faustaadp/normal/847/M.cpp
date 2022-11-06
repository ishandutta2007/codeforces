#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,j,a[101010],hs;
char ta;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
		{
			cout<<a[n]<<"\n";
			return 0;
		}
	}
	cout<<a[n]+(a[2]-a[1])<<"\n";
}