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
int n,m,q[MN+5],top,a[MN+5],b[MN+5];long long s[MN+5];
inline int mabs(int x){return x<0?-x:x;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=mabs(a[i]-a[i-1]);
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		q[top=0]=l;long long ans=0;
		for(int j=l+1;j<=r;++j)
		{	
			while(top&&b[j]>b[q[top]]) --top;
			q[++top]=j;s[top]=s[top-1]+1LL*(q[top]-q[top-1])*b[q[top]];
			ans+=s[top];
		}
		cout<<ans<<endl;
	}
	return 0;
}