#include<iostream>
#include<cstdio>
#define ll long long
#define MAXN 100000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'|ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ans,c;
int a[MAXN+5];
int main()
{
	n=read(),c=read();
	for(int i=1;i<=n;i++)
	   a[i]=read();
	ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]>c)
		{
			ans=1;
		}
		else
		    ans++;
	}	
	cout<<ans;
	return 0;
}