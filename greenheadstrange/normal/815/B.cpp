#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
using namespace std;
ll num[maxn];
ll fr[maxn];
ll mod = 1000000007;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns *= ns, ns %= mod;
	if(b & 1) ns *= a, ns %= mod;
	return ns;
}
ll jc[maxn], bjc[maxn];
ll zhs[maxn];
void work(int a)
{
	int ns = (a - 2) / 2;
	jc[0] = 1, bjc[0] = 1;
	for(int i = 1; i <= ns; i++)
		jc[i] = jc[i - 1] * i, jc[i] %= mod, bjc[i] = ksm(jc[i], mod - 2);
	for(int i = 0; i <= ns; i++)
		zhs[i] = jc[ns], zhs[i] %= mod, 
		zhs[i] *= bjc[i], zhs[i] %= mod,
		zhs[i] *= bjc[ns - i], zhs[i] %= mod;
	for(int i = 1; i <= a; i++)
		num[i] = zhs[(i - 1) >> 1];
	if(ns & 1)
		for(int i = 2; i <= a; i += 2)
			num[i] = -num[i];
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%I64d", &fr[i]);
	if(n == 1) 
	{
		printf("%d\n", fr[1]);
		return 0;
	}
	if(n & 1) 
	{
		work(n - 1);
		for(int i = n; i >= 1; i--)
			if(i & 1) num[i] -= num[i - 1];
			else num[i] += num[i - 1];
	}
	else work(n);

	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += num[i] * fr[i], ans %= mod;
	if(ans < 0) ans += mod;
	printf("%I64d\n", ans);
	return 0;
}