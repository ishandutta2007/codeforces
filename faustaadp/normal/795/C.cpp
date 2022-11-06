#include<bits/stdc++.h>
using namespace std;
long long n,i;
int main()
{
	cin>>n;
	if(n%2==1)
	{
		cout<<7;
		n=n-3;
	}
	for(i=1;i<=n/2;i++)
	{
		cout<<1;
	}
	cout<<endl;
}