#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n,top;
int a[MAXN];
int b[MAXN];
int LOG[MAXN];
int S[MAXN];

ll f[MAXN];
ll g[MAXN];
ll MX[MAXN][20];

multiset<ll> Q;

ll Minf(int l,int r)
{
	int t = LOG[r - l + 1];
	return max(MX[r][t],MX[l + (1 << t) - 1][t]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	LOG[1] = 0;
	for (int i = 2;i <= n + 1;i++)
		LOG[i] = LOG[i >> 1] + 1;
	for (int i = 1;i <= n;i++)
	{
		while (top >= 1 && a[i] < a[S[top]])
			Q.erase(Q.find(g[S[top--]]));
		g[i] = Minf(S[top],i - 1) + b[i];
		S[++top] = i;
		Q.insert(g[i]);
		f[i] = *Q.rbegin();
		MX[i][0] = f[i];
		for (int j = 1;i - (1 << j) + 1 >= 0;j++)
			MX[i][j] = max(MX[i][j - 1],MX[i - (1 << (j - 1))][j - 1]);
	}
	printf("%lld\n",f[n]);
	return 0;
}