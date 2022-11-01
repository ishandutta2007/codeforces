#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define int ll
#define inf 1e17
#define pb push_back
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
ll mo=1e9+7;
ll n,k,s[5001][5001],r_fac[5001],rev_r[5001],fac[5001],rev[5001],ans;
inline ll C(int n,int m)
{
	return r_fac[m];
}
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo) 	if(y&1)	sum=sum*x%mo;return sum;}
signed main()
{
	n=read();k=read();
	s[1][1]=1;
	For(i,2,k)
		For(j,1,i)	s[i][j]=(s[i-1][j]*j+s[i-1][j-1])%mo;
	fac[0]=1;
	For(i,1,k)	fac[i]=fac[i-1]*i%mo;
	
	r_fac[1]=n;
	For(i,2,k)	r_fac[i]=r_fac[i-1]*(n-i+1)%mo;
	
	rev[k]=ksm(fac[k],mo-2);
	Dow(i,0,k-1)	rev[i]=(rev[i+1]*i+1)%mo;
	
	rev_r[k]=ksm(r_fac[k],mo-2);
	Dow(i,0,k-1)	rev_r[i]=rev_r[i+1]*(n-i-1)%mo;
	
	For(i,1,k)	
	{
		ans=(ans+s[k][i]*C(n,i)%mo*ksm(2,n-i)%mo)%mo;
	}
	writeln(ans);
}