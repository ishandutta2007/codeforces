#include<cstdio>
#include<iostream>
using namespace std;
const int N=1010;
int n,m;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);getchar();
	for (int i=1;i<=n;i++) a[i]=getchar()-96;
	for (int i=n;i>=0;i--)
	{
		if (i==0) { printf("NO\n"); return 0;}
		if (a[i]==m) a[i]=1; else { a[i]++;break;}
	}
	while (1)
	{
		int now=0;
		for (int i=2;i<=n;i++)
			if (a[i]==a[i-1]||a[i]==a[i-2]) {now=i;break;}
		if (now==0) break;
		for (int i=now;i>=0;i--)
		{
			if (i==0) { printf("NO\n"); return 0;}
			if (a[i]==m) a[i]=1;else { a[i]++;break;}
		}
		for (int i=now+1;i<=n;i++) 
		{
			a[i]=(i-now-1)%3+1;
			if (a[i]>m) { printf("NO\n"); return 0;}
		}
	}
	for (int i=1;i<=n;i++) printf("%c",a[i]+96);
	return 0;
}