#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#define MN 200000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge{int w,id;}e[MN+5],E[MN+5];
int num1=0,num2=0,Ans1[MN+5],Ans2[MN+5],n,m,x=2,y=3;
bool cmp(const edge&a,const edge&b){return a.w<b.w;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) 
	{
		int j=read();
		if(read()==1) e[++num1]=(edge){j,i};
		else E[++num2]=(edge){j,i};	
	}
	sort(e+1,e+n,cmp);sort(E+1,E+num2+1,cmp);
	for(int i=1;i<n;++i) Ans1[e[i].id]=1,Ans2[e[i].id]=i+1; 
	for(int i=1;i<=num2;++i)
	{
		if(E[i].w<e[y-1].w) return 0*puts("-1");
		Ans1[E[i].id]=x;Ans2[E[i].id]=y;
		if(++x==y) ++y,x=2;	
	}
	for(int i=1;i<=m;++i) printf("%d %d\n",Ans1[i],Ans2[i]);
	return 0;
}