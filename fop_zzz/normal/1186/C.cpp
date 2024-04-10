#pragma comment(linker, "/stack:200000000")
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
char a[N],b[N];
int ans,cnt;
int main()
{
	scanf("%s\n%s",a+1,b+1);
	int len1=strlen(a+1),len2=strlen(b+1);
	For(i,1,len2)	if(a[i]!=b[i])	cnt++;
	int delta=0;
	For(i,1,len2)	if(a[i]!=a[i+1])	delta^=1;
	if(cnt&1)	ans=0;else	ans=1;
	cnt=(cnt&1);
	For(i,2,len1-len2+1)
	{
		cnt^=delta;
		if(cnt==0)	ans++;
		if(a[i]!=a[i-1])	delta^=1;
		if(a[i+len2-1]!=a[i+len2])	delta^=1;
	}
	writeln(ans);
}