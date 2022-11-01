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

int T;
ll a[2005];
int main()
{
	int T=read();
	while(T--)
	{
		int n = read();
		int cnt = 0;
		ll ans = 0;
		For(i, 1, n)
			a[i] = read();
		For(i, 1, n)
			while(a[i] % 2 == 0)
				cnt ++, a[i] /= 2;
		For(i, 1, n)
			ans = max(ans, a[i]);
		ll sum = 0;
		For(i, 1, n) sum += a[i];
		ll tmp = ans;
		For(i, 1, cnt) 
			ans = ans * 2;
		writeln(ans + sum - tmp);
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