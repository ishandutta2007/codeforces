#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[100005],len,k[100005];
int num[105],n,m;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		k[i]=read();
		len+=k[i];
	}
	for(int i=1;i<=n-len+1;i++)
	{
		memset(num,0,sizeof(num));
		for(int j=1;j<=len;j++)
		{
			num[a[i+j-1]]++;
		}
		bool ac=1;
		for(int j=1;j<=m;j++)
		{
			if(num[j]!=k[j]) ac=0;
		}
		if(ac)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}