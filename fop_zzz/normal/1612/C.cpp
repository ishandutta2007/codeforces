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

int main()
{
	int T = read();
	while(T--)
	{
		ll k = read(), x = read();
		ll ans = 0;
		if(1LL * k * (k + 1) / 2 < x)
		{
			x -= k * (k + 1) / 2;
			int l = 1, r = k - 1;
			ans = k - 1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(1LL * (k - 1 + (k - mid)) * mid / 2 >= x) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			writeln(k + ans);
		}else 
		{
			int l = 1, r = k;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(1LL * (1 + mid) * mid / 2 >= x) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			writeln(ans);
		}
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