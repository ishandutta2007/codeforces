#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
typedef long long LL;
using namespace std;
void read(LL &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
int n,m;
int f[123456],a[123456];
const int p=1000000007;
int calc(int n,int m)
{
	return (f[n]-2+f[m])%p;
}
int main()
{
	scanf("%d%d",&n,&m);
	f[1]=2;f[2]=4;
	for (int i=3;i<=max(n,m);i++)
		f[i]=(f[i-2]+f[i-1])%p;
	int ans=calc(n,m);
	if (ans<0) ans+=p;
	printf("%d\n",ans);
	return 0;
}