#include<iostream>
#include<cstdio>
#define MN 1000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[MN+5][MN+5],q[MN+5],top,vis[MN*MN+5],now=0;
bool Solve(int x)
{
	++now;
	for(int i=1;i<=n;++i)
	{
		top=0;
		for(int j=1;j<=m;++j) if(a[i][j]>=x) q[++top]=j;
		for(int j=1;j<top;++j)
			for(int k=j+1;k<=top;++k)
				if(vis[(q[j]-1)*MN+q[k]]==now) return true;
				else vis[(q[j]-1)*MN+q[k]]=now;
	}
	return false;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();
	int l=0,r=1e9,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Solve(mid)) res=mid,l=mid+1;
		else r=mid-1;	
	}
	printf("%d\n",res);
	return 0;
}