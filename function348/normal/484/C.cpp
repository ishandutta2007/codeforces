#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000010;
int n,m;
char s[N],t[N];
int a[N],b[N],c[N];
void multba()
{
	for (int i=1;i<=n;i++) c[i]=b[a[i]];
	for (int i=1;i<=n;i++) b[i]=c[i];
}
void multaa()
{
	for (int i=1;i<=n;i++) c[i]=a[a[i]];
	for (int i=1;i<=n;i++) a[i]=c[i];
}
void exp(int n)
{
	while (n)
	{
		if (n&1) multba();
		n>>=1;
		multaa();
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	while (m--)
	{
		int k,d;
		scanf("%d%d",&k,&d);
		int p=1;
		for (int i=1;i<=d;i++)
		for (int j=i;j<=k;j+=d)
			a[p++]=j;
		for (int i=k+1;i<=n;i++) a[i]=i;
		for (int i=1;i<=n;i++) a[i-1]=a[i];a[n]=a[0];
		for (int i=1;i<=n;i++) b[i]=i;
		exp(n-k+1);
		for (int i=1;i<=n;i++) t[(i+n-k)%n+1]=s[b[i]];
		for (int i=1;i<=n;i++) s[i]=t[i];
		for (int i=1;i<=n;i++) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}