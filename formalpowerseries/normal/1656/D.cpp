#include<bits/stdc++.h>
using namespace std;
typedef __int128 LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const LL E=1;
LL n;
void Solve()
{
	n=read();
	if(n==1 || n==2 || n==4)	return void(puts("-1"));
	LL x=0;
	LL tmp=n;
	while(tmp%2==0)	tmp>>=1,++x;
	x=(E<<(x+1));
	if(x*(x+1)/2<=n)	write(x);
	else
	{
		for(LL i=1;i*i<=tmp;++i)
		{
			if(tmp%i==0)
			{
				if(i!=1 && (i&1) && i*(i+1)/2<=n)
				{
					write(i);goto ds;
				}
				LL j=tmp/i
				;if(j!=1&& (j&1) && j*(j+1)/2<=n)
				{
					write(j);goto ds;
				}
			}
		}puts("-1");
		return ;
	}
	ds:;
	puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}