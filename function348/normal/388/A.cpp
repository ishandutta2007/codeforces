#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[110],b[110];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int f=0,k=1;
		for (int j=1;j<=cnt;j++)
		if (b[j]<b[k]) k=j;
		if (cnt>=1)
		{
			if (b[k]<=a[i]) b[k]++,f=1;
		}
		if (!f) b[++cnt]=1;
	}
	cout<<cnt<<endl;
	return 0;
}