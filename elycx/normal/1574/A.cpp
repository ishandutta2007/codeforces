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
int Tc, n;
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) printf("()");
	printf("\n");
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j < i; j++) printf("()");
		printf("(())");
		for (int j = i + 2; j <= n; j++) printf("()");
		printf("\n");
	}
}
int main()
{
	Tc = read();
	while(Tc--) solve();
	return 0;
}