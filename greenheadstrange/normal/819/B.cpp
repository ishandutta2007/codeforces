#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 2000005
#define ll long long
using namespace std;
int p[maxn], n;
ll ans[maxn]; // ans / 2
ll at[maxn], nt[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]), p[i + n] = p[i];
	for(int i = 1; i <= n * 2; i++)
	{
		int pl1 = i - p[i] + 1, pl2 = i;
		if(pl1 < 1) pl1 = 1;
		// a from pl1 to pl2 += p[i] - (i - a + 1)
		// a from pl1 to pl2 += a + (p[i] - i - 1)
		at[pl1]++, at[pl2 + 1]--, nt[pl1] += p[i] - i - 1, nt[pl2 + 1] -= p[i] - i - 1; 
	}
	ll na = 0, nn = 0;
	for(int i = 1; i <= n; i++)
		na += at[i], nn += nt[i], ans[i] = i * na + nn;
	int mpl = 1;
	for(int i = 1; i <= n; i++)
		if(ans[i] < ans[mpl]) mpl = i;
	printf("%I64d %d\n", ans[mpl] * 2, (n + 1 - mpl) % n);
	return 0;	
}