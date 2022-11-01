#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define inf 1e18
#define sec second
#define fir first
#define pa pair<int,int>

using namespace std;

inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*f;
}
inline void write(ll x){if(x<0){x=-x;putchar('-');}if(x>=10)	write(x/10);putchar('0'+x%10);}
inline void writeln(ll x){write(x);puts("");}

ll n,x,y,cnt;
char s[500001];
int main()
{
	n=read();x=read();y=read();
	scanf("\n%s",s+1);
	For(i,1,n)	if(s[i]=='0'&&(i==1||s[i-1]!='0'))	cnt++;
	ll ans=0;
	ans=cnt*y;if(cnt>0)ans=min(ans,y+(cnt-1)*x);
	writeln(ans);
}