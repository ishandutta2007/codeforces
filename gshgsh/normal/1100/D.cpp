#include<algorithm>
#include<iostream>
#include<cassert>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int M=666,x[MAXN],y[MAXN],a,b;bool vis[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void opt(int x,int y){cout<<x<<' '<<y<<endl;int k=get(),a=get(),b=get();if(k==-1)exit(0);vis[::x[k]][::y[k]]=0;vis[a][b]=1;::x[k]=a,::y[k]=b;}
void go(int x,int y){while(a<x)opt(++a,b);while(a>x)opt(--a,b);while(b<y)opt(a,++b);while(b>y)opt(a,--b);}
void ssh(int&x,int&y,int dx,int dy){if(vis[x+dx][y+dy])x+=dx,opt(x,y),y+=dy,opt(x,y);else opt(x+=dx,y+=dy);}
int main()
{
	a=get(),b=get();For(i,1,M)x[i]=get(),y[i]=get(),vis[x[i]][y[i]]=1;go(500,500);
	int s1=0,s2=0,s3=0,s4=0;For(i,1,M)if(x[i]<500&&y[i]<500)s1++;else if(x[i]<500&&y[i]>500)s2++;else if(x[i]>500&&y[i]<500)s3++;else s4++;
	int dx=0,dy=0;if(s1<=166)dx=1,dy=1;if(s2<=166)dx=1,dy=-1;if(s3<=166)dx=-1,dy=1;if(s4<=166)dx=-1,dy=-1;
	int x=500,y=500;For(i,1,499)ssh(x,y,dx,dy);return 0;
}