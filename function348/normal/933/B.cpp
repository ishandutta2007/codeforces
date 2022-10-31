#include<cstdio>
#include<iostream>
using namespace std;
long long p;
int k,len;
int a[10000];
int main()
{
	cin>>p>>k;
	while (p)
	{
		a[len]=p%k;if (a[len]<0) a[len]+=k;
		if (p>0) p=-p/k;else p=(-p+k-1)/k;
		len++;
	}
	cout<<len<<endl;
	for (int i=0;i<len;i++) printf("%d ",a[i]);
	return 0;
}