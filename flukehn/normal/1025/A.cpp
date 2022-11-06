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
int n,num[55];
char s[500005];
int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		num[s[i]-'a']++;
	}
	if(n==1)
	{
		puts("yes");
		return 0;
	}
	for(int i=0;i<26;i++)
	{
		if(num[i]>=2)
		{
			puts("yes");
			return 0;
		}
	}
	puts("no");
}