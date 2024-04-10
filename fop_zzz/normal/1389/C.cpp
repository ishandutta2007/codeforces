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

int ans;
char s[200005];
inline int Solve(int x1,int x2)
{
	int len=strlen(s+1);
	int now=x1,tans=0;
	For(i,1,len)
	{
		if(s[i]-'0'!=now)	tans++;
		else	if(now==x1)	now=x2;else	now=x1;
	}
	if((len-tans)%2==1&&x1!=x2)	tans=len+1;
	return tans;
}
signed main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		ans=Solve(0,0);
		For(i,0,9)	For(j,0,9)
			ans=min(ans,Solve(i,j));
		writeln(ans);
	}
}