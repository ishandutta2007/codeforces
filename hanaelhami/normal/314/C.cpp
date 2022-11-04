#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS



const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int a[maxn] , fen[maxn] , sum[maxn] , dp[maxn];

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void add(int p , int val)
{
	for(p++; p < maxn; p += lb(p))
		ok(fen[p] += val);
}

int get(int p)
{
	int res = 0;
	for(p++; p > 0; p -= lb(p))
		ok(res += fen[p]);
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		ok(dp[i] = 1LL * (get(a[i]) + 1) * a[i] % mod);
		ok(dp[i] -= sum[a[i]]);
		ok(sum[a[i]] += dp[i]);
		add(a[i] , dp[i]);
		ok(res += dp[i]);
	}
	printf("%d\n", res);
}