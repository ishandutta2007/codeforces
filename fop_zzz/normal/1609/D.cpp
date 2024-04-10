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

int n, d, ans, Fa[10005], siz[100005], can, t[10005];
inline int Get(int x){return x==Fa[x]?x:Fa[x]=Get(Fa[x]);}
inline void Merge(int x, int y)
{
	int tx = Get(x), ty = Get(y);
	if(tx == ty)
	{
		can ++;
		return;
	}
	Fa[tx] = ty;
	siz[ty] += siz[tx];
	siz[tx] = 0;
}
int main()
{
	n = read();
	d = read();
	For(i, 1, n) Fa[i] = i, siz[i] = 1;
	For(i, 1, d)
	{
		int x = read(), y = read();
		Merge(x, y);
		For(i, 1, n) t[i] = siz[i];
		sort(t + 1, t + n + 1);
		ans = 0;

		Dow(i, n - can, n)	ans += t[i];//cout<<i<<"=>"<<t[i]<<endl;
		writeln(ans - 1);
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