#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/
const int N=1e6+5;
int n,top,q[N],ans;
char s[N];
int main()
{
	scanf("\n%s",s+1);
	n=strlen(s+1);
	top=1;q[top]=1;
	For(i,2,n)
	{
		if(s[i]!=s[i-1])	q[++top]=1;else	q[top]=0;
	}
	if(s[n]==s[1])	top--,q[1]=0;
	int lx=0;
//	For(i,1,top)	write_p(q[i]);
	For(i,1,top)	if(q[i]==1)	lx++;else	ans+=lx/2+1,lx=0;
	ans+=lx/2;
	writeln(ans);
}