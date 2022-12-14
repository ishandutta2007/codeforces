#include<iostream>
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
int res[MN+5],a[MN+5],ans=0,n;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1,mn=0;i<=n;++i) 
	{
		res[i]=min(a[i],mn+i);
		mn=min(mn,a[i]-i);
	}
	for(int i=n,mn=n+1;i;--i)
	{
		ans=max(ans,min(res[i],mn-i));
		mn=min(mn,a[i]+i);	
	}
	printf("%d\n",ans);
	return 0;
}