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
#define MN 100000
int n,m,ne[MN+5],la[MN+5],ans=0;
int main()
{
	n=read();m=read();ans=n-1;
	for(int i=1;i<=m;++i)
	{
		int k=read(),L=0;ans+=k-1;
		for(int j=1,x;j<=k;++j)
			x=read(),ne[L]=x,la[x]=L,L=x;
	}
	if(!la[1])
		for(int j=1;ne[j]==j+1;++j) ans-=2;	
	printf("%d\n",ans);
	return 0;
}