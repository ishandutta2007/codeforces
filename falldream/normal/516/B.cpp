#include<iostream>
#include<cstdio>
#define MN 2000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int dis[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const char Dis[4]={'^','<','v','>'};
char st[MN+5][MN+5];
int n,m,le;

void Update(int x,int y)
{
	if(st[x][y]!='.') return;
	int from=-1;
	for(int k=0;k<4;++k)
	{
		int X=x+dis[k][0],Y=y+dis[k][1];
		if(X<1||Y<1||X>n||Y>m||st[X][Y]!='.') continue;
		if(from>=0) return; else from=k;
	}
	if(from==-1) return;le-=2;
	int X=x+dis[from][0],Y=y+dis[from][1];
	st[x][y]=Dis[from];st[X][Y]=Dis[(from+2)&3];
	for(int k=0;k<4;++k) 
	{
		x=X+dis[k][0];y=Y+dis[k][1];
		if(x<1||y<1||x>n||y>m||st[x][y]!='.') continue;
		Update(x,y);	
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) le+=st[i][j]=='.';
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) Update(i,j);
	if(le>0) puts("Not unique");
	else for(int i=1;i<=n;++i) puts(st[i]+1);	
	return 0;
}