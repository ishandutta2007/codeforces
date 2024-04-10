#include<bits/stdc++.h>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
#define gc getchar
inline ll read()
{
	ll t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

ll n,x1,x2,tep;
struct st{ll v,num;}	a[500001];
bool f;
inline bool cmp(st x,st y){return x.v<y.v;}
int main()
{
	n=read();x1=read();x2=read();
	For(i,1,n)	
		a[i].v=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	Dow(i,1,n)
		if(a[i].v*(n-i+1)>=x1)	{tep=i;break;}
	Dow(i,1,tep-1)
	{
		if(a[i].v*(tep-i)>=x2)
		{
			puts("Yes");
			write_p(n-tep+1);writeln(tep-i);
			For(j,tep,n)	write(a[j].num),putchar(' ');puts("");
			For(j,i,tep-1)	write(a[j].num),putchar(' ');puts("");
			return 0;
		}
	}
	swap(x1,x2);
	tep=0;
	Dow(i,1,n)
		if(a[i].v*(n-i+1)>=x1)	{tep=i;break;}
	Dow(i,1,tep-1)
	{
		if(a[i].v*(tep-i)>=x2)
		{
			puts("Yes");
			write(tep-i);putchar(' ');writeln(n-tep+1);
			For(j,i,tep-1)	write(a[j].num),putchar(' ');puts("");
			For(j,tep,n)	write(a[j].num),putchar(' ');puts("");
			return 0;
		}
	}
	puts("No");
} 
/*
4 32 20
21 11 11 12
*/