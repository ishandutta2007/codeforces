#include<bits/stdc++.h>
using namespace std;
int a[22],b[22],x,n,ans;
int main()
{
	a[1]=4;b[1]=5;
	for (int i=2;i<=20;i++)
	{
		for (int j=1;j<i-1;j++)
		{
			a[i]++;
			if (a[j]&1) a[i]+=a[j];
			else a[i]+=b[j];
		}
		if (a[1]&1) a[i]+=b[1];
		else a[i]+=a[1];
		for (int j=1;j<i-1;j++)
		{
			a[i]++;
			if (a[j]&1) a[i]+=b[j];
			else a[i]+=a[j];
		} 
		a[i]++;b[i]=a[i]+5;a[i]+=4;
	}
	scanf("%d",&n);
	if (n<=2) 
	{
		printf("%d\n",1);
		return 0;
	}
	for (int i=1;i<=20;i++)
	{
		if (a[i]==n || b[i]==n) ans++;
	}
	printf("%d\n",ans);
	return 0;
}