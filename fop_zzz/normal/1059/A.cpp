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

int n,L,k;
int l[200005],r[200005],ans;
int main()
{
	n=read();L=read();k=read();
	r[0]=0;
	For(i,1,n)
	{
		l[i]=read();r[i]=l[i]+read();
	}
	l[n+1]=L;
	For(i,1,n+1)	ans+=(l[i]-r[i-1])/k;
	cout<<ans<<endl;
}