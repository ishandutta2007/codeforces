#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')	{ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct edge{
	int from,to,w;
}e[100010];
int n,m,k;
bool b[100010];

bool cmp(edge x,edge y)
{
	return x.w<y.w;
}

int main()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
	   b[i]= false;
	for(int i=1;i<=m;i++)
	{
		e[i].from = read();
		e[i].to = read();
		e[i].w = read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		int x=read();
		b[x] = true;
	}
	for(int i=1;i<=m;i++)
	{
		if(b[e[i].from]&&b[e[i].to])
		   continue;
		if(!b[e[i].from]&&!b[e[i].to])
		   continue;
		cout<<e[i].w;
		return 0;
	}
	cout<<"-1";
    return 0;
}