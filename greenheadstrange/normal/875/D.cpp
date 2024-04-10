#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define maxn 200005
using namespace std;
map<int, int> nx;
int a[maxn];
int nxs[31];
ll ans = 0;
int l[maxn], r[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = (ll)n * (ll)(n + 1) / 2;
	for(int i = n; i >= 1; i--)
	{
		int ns = n;
		if(nx[a[i]]) ns = min(ns, nx[a[i]] - 1);
		for(int k = 0; k < 31; k++)
			if(nxs[k] && (!(a[i] & (1 << k))))
				ns = min(ns, nxs[k] - 1);
		r[i] = ns;
		for(int k = 0; k < 31; k++)
			if(a[i] & (1 << k))
				nxs[k] = i;
		nx[a[i]] = i;
	}
	memset(nxs, 0, sizeof(nxs));
	for(int i = 1; i <= n; i++)
	{
		int ns = 1;
		for(int k = 0; k < 31; k++)
			if(!(a[i] & (1 << k)))
				ns = max(ns, nxs[k] + 1);
		l[i] = ns;
		for(int k = 0; k < 31; k++)
			if(a[i] & (1 << k))
				nxs[k] = i;
	}
	for(int i = 1; i <= n; i++)
		ans -= (i - l[i] + 1) * (ll)(r[i] - i + 1);
	printf("%I64d\n", ans);
	return 0;
}