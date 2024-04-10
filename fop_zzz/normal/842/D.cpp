#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
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
int n,m,x,Now,son[15000001][2],tot[15000001],siz[15000001],cnt;
bool vis[500001];
int o[30];
inline void Insert(int x)
{
	For(i,0,27)	if(x&(1<<i))	o[i]=1;else o[i]=0;
//	Dow(i,0,27)	cout<<o[i];cout<<endl;
	int now=0;
	Dow(i,0,27)
	{
		if(!son[now][o[i]])	son[now][o[i]]=++cnt,siz[cnt]=(1<<i);
		now=son[now][o[i]];tot[now]++;//	cout<<now<<' '<<tot[now]<<' '<<i<<' '<<siz[now]<<endl;
	}
}
inline int Find(int x)
{
	int k=cnt;
//	For(i,1,k)	if(!son[i][1])		if(son[i][0])son[i][1]=++cnt,siz[cnt]=siz[i]/2;
	For(i,0,27)	if(x&(1<<i))	o[i]=1;else o[i]=0;
//	Dow(i,0,27)	cout<<o[i];cout<<endl;
	int now=0,v=0;
	Dow(i,0,27)
	{
		int ls=son[now][0],rs=son[now][1];
		if(o[i])	swap(ls,rs);	
//		if(now==27)	cout<<ls<<'!'<<rs<<endl;
		if(ls)
		{
			if(tot[ls]==siz[ls])	now=rs,v+=(1<<i);
			else	now=ls;
		}
		else return v;
//		cout<<i<<"=>"<<now<<' '<<ls<<' '<<rs<< ' '<<v<<' '<<tot[ls]<<' '<<siz[ls]<<' '<<tot[rs]<<' '<<siz[rs]<<endl;
	}
	return v;
}
int main()
{
	n=read();m=read();
	For(i,1,n)	
	{
		x=read();
		if(!vis[x])	Insert(x);
		vis[x]=1;
	}
	For(i,1,m)
	{
		Now^=read();
		printf("%d\n",Find(Now));
	}
}
/*
5 4 
0 1 5 6 7 
4
*/