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

const int N = 5e5+5;

int n;
ll sum[N];
int k[N], vis[N], val[N], m[N], q[N], top ;
ll ans1, ans2;
inline bool cmp(int x,int y){return val[x] > val[y];}
inline void Solve(int size)
{
	For(i, 1, n) vis[m[i]] = 0, val[m[i]] = 0;
	top = 0;
	For(i, 1, n)
	{
		val[m[i]] += min(size, k[i]);
		if(!vis[m[i]])	q[++top] = m[i], vis[m[i]] = 1;
	}
	if(top < size) return;
	sort(q + 1, q + top + 1, cmp);
	ll tmp = 0;
	For(i, 1, size) tmp += val[q[i]];
	if(ans2 == 0 || tmp * ans2 > ans1 * size)	ans1 = tmp, ans2 = size;
}
inline void Out(int size)
{
	writeln(size);
	For(i, 1, n) vis[m[i]] = 0, val[m[i]] = 0;
	top = 0;
	For(i, 1, n)
	{
		val[m[i]] += min(size, k[i]);
		if(!vis[m[i]])	q[++top] = m[i], vis[m[i]] = 1;
	}
	sort(q + 1, q + top + 1, cmp);
	For(i, 1, size) write_p(q[i]);
}
int main()
{
	n = read();
	For(i, 1, n)
	{
		m[i] = read();
		k[i] = read();
		sum[m[i]] += k[i];
	}
	For(j, 1, 20)
		Solve(j);

	For(i, 1, n) vis[m[i]] = 0, val[m[i]] = 0;
	top = 0;
	For(i, 1, n)
	{
		val[m[i]] += k[i];
		if(!vis[m[i]])	q[++top] = m[i], vis[m[i]] = 1;
	}
	sort(q + 1, q + top + 1, cmp);
	ll tmp = 0;
	For(i, 1, top) 
	{
		tmp += val[q[i]];
		if(i <= 20)	continue;
		if(ans2 == 0 || tmp * ans2 > ans1 * i)	ans1 = tmp, ans2 = i;
	}

	Out(ans2);
}