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
		ll a = read(), b = read(), c = read();
		bool ok = 0;
		while(1)
		{
			if(a < b) swap(a, b);
			if(c > a || b == 0 || a== 0) break;
			if((a - c) % b == 0)
			{
				ok = 1;
				break;
			}
			a %= b;
		}
		if(ok)	puts("YES");
		else puts("NO");
	}
}