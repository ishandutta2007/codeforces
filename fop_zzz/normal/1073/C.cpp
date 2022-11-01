#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
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
const int N=2e5+5;
int n,fx[N],fy[N],gx[N],gy[N],tx,ty;
char s[N];
inline bool check(int len)
{
	ll mx=1e11;
	For(i,1,n-len+1)//i~i+len-1
	{
		ll nx=fx[i-1]+gx[i+len],ny=fy[i-1]+gy[i+len];
		nx=abs(nx-tx);ny=abs(ny-ty);
		mx=min(mx,nx+ny);
	}
	return mx<=len;
}
int main()
{
	n=read();
	scanf("\n%s",s+1);
	tx=read(),ty=read();
	if(((tx+ty)&1)^(n&1))	{puts("-1");return 0;}
	For(i,1,n)
	{
		fx[i]=fx[i-1];fy[i]=fy[i-1];
		if(s[i]=='D')	fy[i]--;
		if(s[i]=='U')	fy[i]++;
		if(s[i]=='L')	fx[i]--;
		if(s[i]=='R')	fx[i]++;
	}
	Dow(i,1,n)
	{
		gx[i]=gx[i+1];gy[i]=gy[i+1];
		if(s[i]=='D')	gy[i]--;
		if(s[i]=='U')	gy[i]++;
		if(s[i]=='L')	gx[i]--;
		if(s[i]=='R')	gx[i]++;
	}
	int l=0,r=n,ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,r=mid-1;else	l=mid+1;
	}
	writeln(ans);
}