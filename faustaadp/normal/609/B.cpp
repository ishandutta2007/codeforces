#include<bits/stdc++.h>
using namespace std;
long long n,k,x,t;
long long i,a[1000];
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[t]++;
	}
	//for(i=1;i<=n;i++)
	//	cout<<i<<" "<<a[i]<<"\n";
	for(i=1;i<=k;i++)
	{
		n=n-a[i];
		x=x+a[i]*n;
	}
	cout<<x<<endl;
}