#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define maxn 200005
using namespace std;
int T;
int n, a[maxn], b[maxn];
void solve()
{
	int cnt;
	scanf("%d%d", &n, &cnt);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	for (int i = 2; i <= n; i++)
	{
		if(a[i] != a[i - 1] + 1) cnt--;
	}
	if(cnt >= 1) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}