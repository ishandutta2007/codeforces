#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
int n,m;
struct edge{int x,y,v,c,num;}	e[200001];
inline bool cmp(edge x,edge y){if(x.v==y.v)	return x.c>y.c;else return x.v<y.v;}
inline bool cmp1(edge x,edge y){return x.num<y.num;}
int main()
{
	n=read();m=read();
	For(i,1,m)
	{
		e[i].v=read();e[i].c=read();e[i].num=i;
	}
	sort(e+1,e+m+1,cmp);
	int now=1,use=3,can=1;
	For(i,1,m)
	{
		if(e[i].c==1)
		{
			e[i].x=now;e[i].y=++now;
		}
		else
		{
			if(now<3)	{puts("-1");return 0;}
			else
			{
				if(can==0)	use++,can=use-2;	
				if(use>now)	{puts("-1");return 0;}	
				e[i].x=use;e[i].y=can;
				can--;
			}
		}
	}
	sort(e+1,e+m+1,cmp1);
	For(i,1,m)	cout<<e[i].x<<' '<<e[i].y<<endl;
}