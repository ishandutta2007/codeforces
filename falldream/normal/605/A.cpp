#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ans=0,f[MN+5];

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),mx=f[x-1];
		ans=max(ans,mx+1);
		f[x]=mx+1;
	}
	cout<<n-ans;
	return 0;
}