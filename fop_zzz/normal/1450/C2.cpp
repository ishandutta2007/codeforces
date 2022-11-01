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

char s[505][505];
int k,cnt,n;
inline bool check(int x,int y)
{
	if(x==y)	return 0;
	int cnt=0;
	For(i,1,n)
		For(j,1,n)
			if(s[i][j]=='X'&&(i+j)%3==x)	cnt++;
	For(i,1,n)
		For(j,1,n)
			if(s[i][j]=='O'&&(i+j)%3==y)	cnt++;	
	if(cnt<=k/3)
	{
		For(i,1,n)
			For(j,1,n)	if(s[i][j]=='X'&&(i+j)%3==x)	s[i][j]='O';
		For(i,1,n)
			For(j,1,n)	if(s[i][j]=='O'&&(i+j)%3==y)	s[i][j]='X';	
		For(i,1,n)	cout<<s[i]+1<<endl;
		return 1;
	}
	return 0;
}
int main()
{
	int T=read();
	while(T--)
	{
		k=0;
		n=read();
		For(i,1,n)	scanf("%s",s[i]+1);
		For(i,1,n)	For(j,1,n)	if(s[i][j]!='.')	k++;
		bool ok=0;
		For(mo,0,2)	{	For(mo1,0,2)	if(check(mo,mo1))	{ok=1;break;}if(ok)	break;}
	}
}