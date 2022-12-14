#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 2000000000
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int s[200050];
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(s[i]&1)
		{
			if(i==n||s[i+1]==0)
			{
			   printf("NO");
		       return 0;
			}
			s[i+1]--;
		}
	}
	printf("YES");
	return 0;
}