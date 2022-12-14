#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[MN+5][1<<16],from[MN+5][1<<16],n,a[MN+5],bit[MN+5],q[MN+5];
void R(int&x,int&y,int X,int Y){X<x?(x=X,y=Y):0;}
inline int abs(int x){return x<0?-x:x;}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(f,63,sizeof(f));f[0][0]=0;
	for(int i=1;i<59;++i)
		for(int j=0;j<16;++j) if(i%p[j]==0) bit[i]|=1<<j;
	for(int i=1;i<=n;++i) for(int j=0;j<1<<16;++j) if(f[i-1][j]<1e9)
		for(int k=1;k<59;++k) if(!(bit[k]&j)) R(f[i][j|bit[k]],from[i][j|bit[k]],f[i-1][j]+abs(k-a[i]),k);
	int mn=1e9,fr=0;
	for(int i=0;i<1<<16;++i) if(f[n][i]<mn) mn=f[n][i],fr=i;
	for(int i=n,j=fr;i;j^=bit[from[i--][j]]) q[i]=from[i][j];
	for(int i=1;i<=n;++i) printf("%d ",q[i]);
	return 0;	
}