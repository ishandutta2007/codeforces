#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int a[MAXN];
int b[MAXN];

int solve(int d,int l,int r)
{
	if (l == r)
		return 0;
	int pl = l,pr = r;
	for (int i = l;i <= r;i++)
		if (a[i] >> d & 1)
			b[pr--] = a[i];
		else
			b[pl++] = a[i];
	for (int i = l;i <= r;i++)
		a[i] = b[i];
	if (pl == l || pr == r)
		return solve(d - 1,l,r);
	int L = solve(d - 1,l,pl - 1),R = solve(d - 1,pr + 1,r);
	return min(pl - l - 1 + R,r - pr - 1 + L);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",solve(30,1,n));
	return 0;
}