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

int n, a[2005], q[2005];
inline void Solve()
{
	n = read();
	int mi = read(); int mx = read();
	int top=0;
	a[1] = mi; a[n] = mx;
	For(i, 1, n)	if(i != mi && i != mx)	q[++ top] = i;
	For(i, 2, n-1)	a[i] = q[top--];
	int tm = n + 1, tmx = 0;
	For(i, 1, n/2) tm = min(tm, a[i]);
	For(i, n/2 + 1, n) tmx = max(tmx, a[i]);
	if(tm != mi || tmx != mx)	
	{
		puts("-1");
		return;
	}
	For(i, 1, n) write_p(a[i]);
	puts("");
}
int main()
{
	int T=read();
	while(T--)
		Solve();
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/