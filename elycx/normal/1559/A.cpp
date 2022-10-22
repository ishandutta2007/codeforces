#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100005
using namespace std;
int T, n, a[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = a[1];
	for (int i = 2; i <= n; i++) ans &= a[i];
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}