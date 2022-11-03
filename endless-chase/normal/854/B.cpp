#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	if(k==n||k==0)
	{
	cout<<"0"<<' '<<"0";
	return 0;
}
else
cout<<"1"<<' ';
	if(3*k<=n)
	{
	cout<<2*k;
	return 0;
}
if(3*k>n)
cout<<n-k;
return 0;
	
}