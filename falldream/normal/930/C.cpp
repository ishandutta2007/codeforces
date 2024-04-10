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
int n,m,s[MN+5],f[MN+5],g[MN+5],a[MN+5],ans;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		int l=read(),r=read();
		++s[l];--s[r+1];	
	}
	for(int i=1;i<=m;++i) s[i]+=s[i-1];
	for(int i=1;i<=m;++i) a[i]=1e9;
	for(int i=1;i<=m;++i)
	{
		int l=0,r=i-1,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			if(s[i]>=a[mid]) res=mid,l=mid+1;
			else r=mid-1;	
		}
		f[i]=res;a[res+1]=min(a[res+1],s[i]);
	}
	for(int i=1;i<=m;++i) a[i]=1e9;
	for(int i=m;i;--i)
	{
		int l=0,r=m-i,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			if(s[i]>=a[mid]) res=mid,l=mid+1;
			else r=mid-1;	
		}
		g[i]=res;a[res+1]=min(a[res+1],s[i]);
		ans=max(ans,f[i]+g[i]+1);
	}
	cout<<ans;
	return 0;
}