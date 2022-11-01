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

int x[2005],y[2005];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		For(i,1,n)	x[i]=read(),y[i]=read();
		bool ok=0;
		For(i,1,n)
		{
			bool gg=0;
			For(j,1,n)	if(abs(x[j]-x[i])+abs(y[j]-y[i])>k)	gg=1;
			if(!gg)	ok=1;
		}
		if(ok)	puts("1");else	puts("-1");
	}
}