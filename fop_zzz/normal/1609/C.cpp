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

const int N = 1e6+5;
int pri[N], bj[N], a[N], q[N], top, n, e;
int tot;
inline void Pre()
{
	int maxn = 1e6;
	For(i, 2, maxn)
	{
		if(!bj[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= maxn; ++j)
		{
			bj[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}
int main()
{
	int T = read();
	Pre();
	while(T --)
	{
		ll ans = 0;
		n = read(); e = read();
		For(i, 1, n)
			a[i] = read();
		For(j, 1, e)
		{
			int top = 0;
			for(int x = j; x <= n; x += e)
				q[++top] = a[x];
			int l = 0, las = 0, r = 0;
			For(i, 1, top)
			{
				if(q[i] != 1)
				{
					if(bj[q[i]])	l = i + 1, r = 0, las = i;
					else 
					{
						l = las + 1;
						r = i;
						ans --;
						las = i;
					}
				}
				// cout<<i <<' '<<l <<' '<<r<<' '<<max(0, (r - l+1))<<endl;
				if(l)	ans += max(0, (r - l+1));
			}
		}
		writeln(ans);
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