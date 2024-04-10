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
ll a[200005],b[200005];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		a[0]=0;b[0]=0;
		For(i,1,n*2)	
		{
			int x=abs(read()),y=abs(read());
			if(x==0)	a[++a[0]]=y;else	b[++b[0]]=x;
		}
		double ans=0;
		sort(a+1,a+a[0]+1);sort(b+1,b+b[0]+1);
		For(i,1,n)	ans=ans+sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.20lf\n",ans);
	}
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/