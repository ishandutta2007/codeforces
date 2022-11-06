#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
char s[200005],t[200005];
int n,m;
int main()
{
	n=read();m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	int pla=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*')
		{
			pla=i;
			break;
		}
	}
	if(n>m+1)
	{
		puts("NO");
		return 0;
	}
	if(!pla)
	{
		if(n!=m)
		{
			puts("NO");
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=t[i])
			{
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
	else
	{
		for(int i=1;i<pla;i++)
		{
			if(s[i]!=t[i])
			{
				puts("NO");
				return 0;
			}
		}
		for(int i=n;i>pla;i--)
		{
			if(s[i]!=t[m-(n-i)])
			{
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
}