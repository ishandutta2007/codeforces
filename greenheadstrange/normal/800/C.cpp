#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
using namespace std;
ll ksm(ll a, ll b, ll c)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1, c);
	ns *= ns, ns %= c;
	if(b & 1) ns *= a, ns %= c;
	return ns;	
}
bool bpr[maxn];
int phi[maxn];
int n, m;
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
ll get(ll a, ll b)
{
	int ns = gcd(a, m);
	int nm = m / ns;
	a /= ns, b /= ns;
	int bk = 1;
	if(nm <= 2) bk = 1;
	else bk = ksm(a, phi[nm] - 1, nm);
	b *= bk, b %= m;
	return b;
} 
int size[maxn];
int dp[maxn], nx[maxn];
bool c[maxn];
int fr[maxn];
int dv[maxn], dcnt = 0;
int ans[maxn];
int main()
{
	memset(nx, -1, sizeof(nx));
	for(int i = 0; i < maxn; i++) phi[i] = i, bpr[i] = 1;

	for(int i = 2; i < maxn; i++)
	{
		if(!bpr[i]) continue;
		phi[i] = i - 1;
		for(int j = 2; j * i < maxn; j++)
			bpr[i * j] = 0, phi[j * i] /= i, phi[j * i] *= i - 1;
	}
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) c[i] = 1;
	for(int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		c[num] = 0;
	}
	for(int i = 0; i < m; i++)
		if(c[i]) size[gcd(i, m)]++;
	for(int i = 1; i <= m; i++)
		if(size[i]) dv[dcnt++] = i;
	for(int i = dcnt - 1; i >= 0; i--)
	{
		dp[i] = size[dv[i]], nx[i] = -1;
		for(int j = i + 1; j < dcnt; j++)
			if(size[dv[i]] + dp[j] > dp[i] && !(dv[j] % dv[i])) 
				nx[i] = j, dp[i] = size[dv[i]] + dp[j];
	}
	int mpl = -1;
	for(int i = 0; i < dcnt; i++)
		if(dp[i] > dp[mpl]) 
			mpl = i;
	if(mpl != -1) printf("%d\n", dp[mpl]);
	else printf("0\n");
	if(mpl == -1 || !dp[mpl]) return 0;
	
	int cnt = 0;
	while(mpl != -1)
	{
		for(int i = 0; i * dv[mpl] < m; i++)
			if(gcd(i * dv[mpl], m) == dv[mpl] && c[i * dv[mpl]]) 
				fr[cnt++] = i * dv[mpl];
		mpl = nx[mpl];
	}
	ans[0] = fr[0];
	for(int i = 1; i < cnt; i++) ans[i] = get(fr[i - 1], fr[i]);
	for(int i = 0; i < cnt; i++) printf("%d ", ans[i]);
	return 0;
}