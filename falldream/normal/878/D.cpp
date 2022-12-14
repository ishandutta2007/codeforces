#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,K,Q,a[15][MN+5],rk[20],now,kk;
bitset<4100> b[MN+12+5];
bool cmp(int x,int y){return a[x][now]>a[y][now];}
int main()
{
	n=read();K=kk=read();Q=read();	
	for(int i=1;i<=K;++i)
	{
		rk[i]=i;
		for(int j=1;j<=n;++j) a[i][j]=read();
		for(int j=0;j<1<<K;++j)
			b[i][j]=bool(j&(1<<i-1));
	}
	for(int i=1;i<=Q;++i)
	{
		int k=read(),x=read(),y=read();
		if(k==1) b[++K]=b[x]|b[y];
		else if(k==2) b[++K]=b[x]&b[y];
		else 
		{
			now=y;sort(rk+1,rk+kk+1,cmp);
			for(int i=1,j=0;;++i) 
				if(b[x][j|=1<<rk[i]-1]) {printf("%d\n",a[rk[i]][y]);break;}
		}
	}
	return 0;
}