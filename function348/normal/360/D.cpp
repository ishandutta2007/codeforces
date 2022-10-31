#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m,num,p,b,ans;
int a[N],c[N],f[N],tmp[N];
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
int exp(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;a=1LL*a*a%c;
	}
	return d;
}
int get(int a)
{
	for (int i=1;i<=num;i++) 
		if (exp(a,c[i],p)==1) return c[i];
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&b);
	for (int i=2;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		b=gcd(b,x);
	}
	for (int i=1;i*i<=(p-1);i++)
	if ((p-1)%i==0) 
	{
		c[++num]=i;
		if (i*i<p-1) c[++num]=(p-1)/i;
	}
	sort(c+1,c+1+num);
	for (int i=1;i<=n;i++) a[i]=exp(a[i],b,p);
	for (int i=1;i<=n;i++) a[i]=get(a[i]);
	sort(a+1,a+1+n);
	int m=0;
	for (int i=1;i<=n;i++)
	if (a[i]!=a[i-1]) tmp[++m]=a[i];
	for (int i=1;i<=m;i++) a[i]=tmp[i];n=m;
	for (int i=1;i<=n;i++)
	{
		f[i]=a[i];
		for (int j=1;j<i;j++)
		if (a[i]%a[j]==0) f[i]-=f[j];
		ans+=f[i];
	}
	printf("%d\n",ans);
	return 0;
}