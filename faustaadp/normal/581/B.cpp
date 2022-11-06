#include<bits/stdc++.h>
using namespace std;
long long ma,n,i,a[100100],b[100100];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[n]=0;
	ma=a[n]+1;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]>=ma)
		{
			b[i]=0;
			ma=a[i]+1;
		}
		else
		{
			b[i]=ma-a[i];
		//	ma++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i==n)
			cout<<b[i]<<endl;
		else
			cout<<b[i]<<" ";
	}
	return 0;
}