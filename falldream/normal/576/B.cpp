#include<iostream>
#include<cstdio>
#include<cstring>
#define MN 100000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,p[MN+5],q[MN+5],top=0,sz,len=-1;
bool mark[MN+5];
int flag,only,odd;

void work(int x)
{
	int y=flag;
	for(;!mark[x];x=p[x],y=p[y])
		printf("%d %d\n",x,y),mark[x]=1;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) if(!mark[i])
	{
		sz=1;mark[i]=1;q[++top]=i;
		for(int j=p[i];!mark[j];j=p[j]) mark[j]=1,sz++;
		if(sz==2) flag=i;
		else if(sz==1) only=i;
		else if(sz&1) odd=true;
	}
	if(only) 
	{
		puts("YES");
		for(int i=1;i<=n;i++)if(i!=only) printf("%d %d\n",i,only);
		return 0;
	}
	if(odd||!flag)return 0*puts("NO");
	puts("YES");
	printf("%d %d\n",flag,p[flag]);
	memset(mark,0,sizeof(mark));
	mark[flag]=1,mark[p[flag]]=1;
	for(int i=1;i<=n;i++)if(!mark[i]) work(i);
	return 0;
}