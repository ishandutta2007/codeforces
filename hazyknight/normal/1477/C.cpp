#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5005;

int n;
int p[MAXN];

struct Vector
{
	ll x,y;
	
	Vector(ll X = 0,ll Y = 0)
	{
		x = X;
		y = Y;
	}
	
	Vector operator - (const Vector &p)
	{
		return Vector(x - p.x,y - p.y);
	}
}a[MAXN];

bool vis[MAXN];

ll dot(Vector a,Vector b)
{
	return a.x * b.x + a.y * b.y;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	p[1] = 1;
	vis[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		int l = p[i - 1];
		ll MAX = p[i - 1];
		for (int j = 1;j <= n;j++)
			if (!vis[j] && dot(a[j] - a[l],a[j] - a[l]) > dot(a[MAX] - a[l],a[MAX] - a[l]))
				MAX = j;
		p[i] = MAX;
		vis[MAX] = 1;
	}
	for (int i = 1;i <= n;i++)
		printf("%d ",p[i]);
	printf("\n");
	return 0;
}