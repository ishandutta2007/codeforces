#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
int v[N],d[N],a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch;
		while ((ch=getchar())<=32);
		d[i]=ch=='>';
	}

	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int now=1;
	while (1)
	{
		if (now<1||now>n) { printf("FINITE\n");return 0;}
		if (v[now]) { printf("INFINITE\n");return 0;}
		v[now]=1;
		if (d[now]) now+=a[now];else now-=a[now];
	}
	return 0;
}