#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int n,ans,m,st[200005];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		++st[min(u,v)];
	}
	for(int i=1;i<=n;++i)	if(!st[i])	++ans;
	int q=read();
	while(q-->0)
	{
		int op=read();
		if(op==1)
		{
			int u=read(),v=read();
			++st[min(u,v)];
			if(st[min(u,v)]==1)	--ans;
		}
		if(op==2)
		{
			int u=read(),v=read();
			--st[min(u,v)];
			if(st[min(u,v)]==0)	++ans;
		}
		if(op==3)	write(ans),puts("");
	}
	return 0;
}