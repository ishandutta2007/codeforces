#include<iostream>
#include<cstdio>
#define MX 823543
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,f[1<<7],g[1<<7];

int main()
{
	n=read();m=read();
	int len1=0,len2=0;
	for(int t=n-1;t;t/=7) ++len1;len1=max(len1,1);
	for(int t=m-1;t;t/=7) ++len2;len2=max(len2,1);
	for(int i=0;i<n&&i<MX;++i)
	{
		int s=0,flag=0;
		for(int t=i,l=1;l<=len1;++l,t/=7)
		{
			int x=t%7;
			if(s&(1<<x)) flag=1;
			else s|=1<<x;
		}
		if(!s) s=1;
		if(!flag) ++f[s];
	}
	for(int i=0;i<m&&i<MX;++i)
	{
		int s=0,flag=0;
		for(int t=i,l=1;l<=len2;++l,t/=7)
		{
			int x=t%7;
			if(s&(1<<x)) flag=1;
			else s|=1<<x;
		}
		if(!s) s=1;
		if(!flag) ++g[s];
	}
	long long ans=0;
	for(int i=0;i<1<<7;++i)
		for(int j=0;j<1<<7;++j)
			if(!(i&j)) ans+=1LL*f[i]*g[j];
	printf("%lld\n",ans);
	return 0;
}