#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int Tc, a, b, c, m;
void solve()
{
	scanf("%d%d%d%d", &a, &b, &c, &m);
	if(b < c) swap(b, c);
	if(a < b) swap(a, b);
	int x = max(0, a - b - c - 1);
	if(a - 1 + b - 1 + c - 1 >= m && m >= x) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	Tc = read();
	while(Tc--) solve();
	return 0;
}