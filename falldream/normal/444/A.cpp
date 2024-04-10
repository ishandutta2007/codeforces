#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,v[505];double ans=0;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) v[i]=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),w=read();
		ans=max(ans,(double)(v[x]+v[y])/w);	
	}
	printf("%.10lf",ans);
	return 0;
}