#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ax,ay,tx,ty,bx,by,X[MN+5],Y[MN+5];
double f[MN+5][4],ans=1e18;
inline long long sqr(int x){return 1LL*x*x;}
double dist(int x,int y,int X,int Y){return sqrt(sqr(x-X)+sqr(y-Y));}
inline void R(double&x,double y){y<x?x=y:0;}
int main()
{
	ax=read();ay=read();bx=read();by=read();tx=read();ty=read();
	n=read();
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read();
	for(int i=0;i<=n;++i) for(int j=0;j<4;++j) f[i][j]=1e18; 
	f[0][3]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<4;++j) if(f[i-1][j]<1e18)
		{
			R(f[i][j&2],f[i-1][j]+((j&1)?dist(ax,ay,X[i],Y[i]):dist(tx,ty,X[i],Y[i]))+dist(tx,ty,X[i],Y[i]));
			R(f[i][j&1],f[i-1][j]+((j&2)?dist(bx,by,X[i],Y[i]):dist(tx,ty,X[i],Y[i]))+dist(tx,ty,X[i],Y[i]));
			R(f[i][j],f[i-1][j]+2*dist(tx,ty,X[i],Y[i]));
		}
	for(int i=0;i<3;++i) R(ans,f[n][i]);
	printf("%.10lf",ans);
	return 0;
}