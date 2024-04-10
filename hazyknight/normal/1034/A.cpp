#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

const int MAXN = 300005;
const int MAXM = 15000005;

int n,tot,G,ans;
int a[MAXN];
int prime[MAXM];
int id[MAXM];
int match[MAXM];

bool mark[MAXM];

void init()
{
	for (int i = 2;i <= 15000000;i++)
	{
		if (!mark[i])
		{
			prime[++tot] = i;
			id[i] = tot;
		}
		for (int j = 1;j <= tot && i * prime[j] <= 15000000;j++)
		{
			mark[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

void divide(int v)
{
	for (int i = 1;i <= tot && prime[i] * prime[i] <= v;i++)
	{
		if (v % prime[i] == 0)
			match[i]++;
		while (v % prime[i] == 0)
			v /= prime[i];
	}
	if (v != 1)
		match[id[v]]++;
}

int main()
{
	init();
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]),G = __gcd(G,a[i]);
	for (int i = 1;i <= n;i++)
		a[i] /= G;
	for (int i = 1;i <= n;i++)
		divide(a[i]);
	ans = n - match[1];
	for (int i = 2;i <= tot;i++)
		ans = min(ans,n - match[i]);
	if (ans == n)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}