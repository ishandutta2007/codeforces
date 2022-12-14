#include<iostream>
#include<cstdio>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int mp[MN+5][MN+5],n,m,mark[MN+5],flag=1;

void Mark(int x,int c)
{
	if(mark[x]&&mark[x]!=c) flag=0;
	if(mark[x]) return;mark[x]=c;
	for(int i=1;i<=n;++i) if(i!=x&&mark[i]!=2) 
	{
		if(mp[x][i]) Mark(i,c);
		else Mark(i,4-c);	
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read();
		mp[x][y]=mp[y][x]=1;	
	}
	for(int i=1;i<=n;++i)
	{
		int flag=1;
		for(int j=1;j<=n;++j) if(j!=i) flag&=mp[i][j];
		if(flag) mark[i]=2;	
	}
	for(int i=1;i<=n;++i) if(!mark[i]) 
		Mark(i,1);
	if(!flag)  return 0*puts("NO");
	puts("YES");
	for(int i=1;i<=n;++i) printf("%c",mark[i]+'a'-1);
	return 0;
}