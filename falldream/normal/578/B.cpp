#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,x,a[MN+5],pre[MN+5],suf[MN+5];
long long ans=0;
int main()
{
	n=read();k=read();x=read();
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]|(a[i]=read());
	for(int i=n;i;--i) suf[i]=suf[i+1]|a[i];
	for(int i=1;i<=n;++i) 
	{
		long long X=a[i];
		for(int j=1;j<=k;++j) X*=x;
		ans=max(ans,X|pre[i-1]|suf[i+1]);
	}
	cout<<ans;
	return 0;
}