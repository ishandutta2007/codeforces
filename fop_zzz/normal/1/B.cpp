#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long	
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
char s[200001];
int n,q[200001],top;
inline void write(int x)
{
	top=0;
	while(x)
	{	
		q[++top]=(x-1)%26+1;if(x==1)	break;
		x=(x-1)/26;	
//		cout<<x<<' '<<q[top]<<endl;
	}
	Dow(i,1,top)	putchar('A'+q[i]-1);
}
inline void Solve1()
{
	int now=2,v=0;
	while(1)
	{
		v=v*10+s[now]-'0';
		if(s[now+1]=='C')	break;
		now++;
	}	

	int now1=now+2,v1=0,len=strlen(s+1);
	while(1)
	{
		v1=v1*10+s[now1]-'0';
		if(now1==len)	break;
		now1++;
	}
	write(v1);
	printf("%d\n",v);
}
inline void Solve2()
{	
	int now=1,v=0,v1=0;
	while(!isdigit(s[now]))	v=v*26+s[now]-'A'+1,++now;//cout<<"=="<<v<<endl;
	int len=strlen(s+1);
	while(1)	
	{
		v1=v1*10+s[now]-'0';
		if(now==len)	break;
		++now;
	}
	printf("R%dC%d\n",v1,v);
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read();
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		int flag=0;
		int len=strlen(s+1);
		For(i,1,len)	if(s[i]=='R')	flag=i;
		if(!isdigit(s[flag+1]))	{Solve2();continue;}
		For(i,flag+1,len)	if(s[i]=='C')	flag=-1;
		if(flag==-1)
		Solve1();
		else 	Solve2();
	}
}
/*
R228C494
*/