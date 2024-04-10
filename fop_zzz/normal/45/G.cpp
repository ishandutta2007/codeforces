#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=6000*3001;
bool flag=0;
int n,sum,tot,pri[N/10];
int a[6005];
bool bj[N];
inline void Solve(int x)
{
	For(i,1,n)	if(a[i]==0)	a[i]=1;
	Dow(i,1,n)	if(x>=i)	
	{
		if(flag&&i==3)	
		{
			x-=3;
			a[1]=2;a[2]=2;
		}
		else	x-=i,a[i]=2;
	}
	For(i,1,n)	write_p(a[i]);
}
inline void self_check()
{
	For(i,1,3)
	{
		int s=0;
		For(j,1,n)	if(a[j]==i)	s+=j;
		if(bj[s])	puts("WA");
	}
	puts("OK");
}
int main()
{
	n=read();
	if(n==2)	
	{
		puts("1 1");
		return 0;
	}
	sum=n*(n+1)/2;
	For(i,2,sum)
	{
		if(!bj[i])	pri[++tot]=i;
		for(int j=1;j<=tot;++j)
		{
			if(i*pri[j]>sum)	break;
			bj[i*pri[j]]=1;
			if(i%pri[j]==0)	break;
		} 
	}
	if(sum&1)	
	{
		if(!bj[sum-2])	{Solve(2);return 0;}
		a[3]=3,flag=1,sum-=3;
	}
	For(i,2,sum/2)	if(!bj[i]&&!bj[sum-i])	{Solve(i);break;}	
//	self_check();
}