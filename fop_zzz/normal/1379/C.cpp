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

const int N=200005;
pa a[N];
int b[N];
int main()
{
	int T=read();
	while(T--)
	{	
		ll m=read(),n=read();
		For(i,1,n)	a[i].sec=read(),a[i].fir=read();
		sort(a+1,a+n+1);
		For(i,1,n)	b[i]=a[i].sec;
		sort(b+1,b+n+1);
		int tep=n;
		ll ans=0,rest=m,alr=0;
		Dow(i,1,n)	
		{
			while(tep&&b[tep]>a[i].fir)	
			{
				rest--,alr+=b[tep],tep--;
				if(rest==0)	ans=max(ans,alr);
			}
			if(a[i].sec<a[i].fir)	if(rest>=1)	ans=max(ans,a[i].sec+alr+(rest-1)*a[i].fir);
			if(a[i].sec>=a[i].fir)	if(rest>=0)	ans=max(ans,a[i].fir*rest+alr);
		}
		writeln(ans);
	}

}