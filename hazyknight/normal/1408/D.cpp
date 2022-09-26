#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 1000005;

int n,m,ans;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int MAX[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i = 1;i <= m;i++)
		scanf("%d%d",&c[i],&d[i]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i] <= c[j] && b[i] <= d[j])
				MAX[c[j] - a[i]] = max(MAX[c[j] - a[i]],d[j] - b[i] + 1);
	for (int i = 1000000;i >= 0;i--)
		MAX[i] = max(MAX[i],MAX[i + 1]);
	ans = 1e9;
	for (int i = 0;i <= 1000001;i++)
		ans = min(ans,i + MAX[i]);
	printf("%d\n",ans);
	return 0;
}