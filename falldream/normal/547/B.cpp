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
int n,lt[MN+5],a[MN+5],rt[MN+5],s[MN+5],q[MN+5],top=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		while(top&&a[q[top]]>=a[i]) --top;
		lt[i]=q[top]+1;q[++top]=i;	
	}
	q[top=0]=n+1;
	for(int i=n;i;--i)
	{
		while(top&&a[q[top]]>=a[i]) --top;
		rt[i]=q[top]-1;q[++top]=i;
		s[rt[i]-lt[i]+1]=max(s[rt[i]-lt[i]+1],a[i]);
	}	
	for(int i=n;i;--i) s[i]=max(s[i],s[i+1]);
	for(int i=1;i<=n;++i) printf("%d ",s[i]);
	return 0;
}