#include<bits/stdc++.h>
using namespace std;
long long  n,a[2000110],i;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for(i=1;i<=n/2;i++)
	{
		if(i%2==1)
			swap(a[i],a[n-i+1]);
	}
	for(i=1;i<n;i++)
	{
		printf("%I64d ",a[i]);
	}
	printf("%I64d\n",a[n]);
}