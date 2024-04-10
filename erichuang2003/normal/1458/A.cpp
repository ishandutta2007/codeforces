#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n,m;

ll a[MAXN];
ll b[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	ll g = 0;
	for (int i = 1;i < n;i++)
		g = __gcd(g,abs(a[i + 1] - a[i]));
	for (int i = 1;i <= m;i++)
	{
		scanf("%lld",&b[i]);
		printf("%lld ",__gcd(g,a[1] + b[i]));
	}
	printf("\n");
	return 0;
}