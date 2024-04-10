#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e11
#define pb push_back
#define mk make_pair
#define pa pair<int,int>
#define local freopen("[??]in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
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

int x[21],y[21],px[21],py[21],mxx,mxy,mix,miy,flag1,flag2,t;
int main()
{
	For(i,1,4)	x[i]=read(),y[i]=read();
	For(i,1,4)	px[i]=read(),py[i]=read();
	mxx=mxy=-1e9;
	For(i,1,4)	mxx=max(mxx,x[i]),mxy=max(mxy,y[i]);
	mix=miy=1e9;
	For(i,1,4)	mix=min(mix,x[i]),miy=min(miy,y[i]);
	For(i,1,4)
	For(j,1,4)
	{
		if(2*mix<=(px[i]+px[j])&&(px[j]+px[i])<=2*mxx&&2*miy<=py[j]+py[i]&&py[j]+py[i]<=2*mxy)
			flag1=1;

	}
	For(i,1,4)	t=x[i],x[i]=x[i]-y[i],y[i]=y[i]+t;
	For(i,1,4)	t=px[i],px[i]=px[i]-py[i],py[i]=py[i]+t;
	For(i,1,4)	t=x[i],x[i]=px[i],px[i]=t,t=y[i],y[i]=py[i],py[i]=t;
	mxx=mxy=-1e9;
	For(i,1,4)	mxx=max(mxx,x[i]),mxy=max(mxy,y[i]);
	mix=miy=1e9;
	For(i,1,4)	mix=min(mix,x[i]),miy=min(miy,y[i]);
	For(i,1,4)
	For(j,1,4)
	{
		if(2*mix<=(px[i]+px[j])&&(px[j]+px[i])<=2*mxx&&2*miy<=py[j]+py[i]&&py[j]+py[i]<=2*mxy)
			flag2=1;
	}
	if(flag1||flag2)	puts("YES");else	puts("NO");
}