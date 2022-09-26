#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

const int n=250;

int t,a[n+10];

void work()
{
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	int m=a[225]>>1;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=i;j<n&&a[j]-a[i]<m;j++) cnt++;
		if(cnt>160) {puts("poisson");return;}
	}
	puts("uniform");
}

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		work();
	return 0;
}