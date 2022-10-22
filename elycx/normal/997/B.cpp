#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
int n;
struct node
{
	int a, b;
}t[100][10000];
int cnt[100];
inline int cmp(node xx, node yy)
{
	return xx.a < yy.a; 
} 
signed main()
{
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 48; j++)
		{
			if(i + j > n) continue;
			int x = i * 4 + j * 9;
			t[x % 49][++cnt[x % 49]] = {x, n - i - j};
		}
	}
	for (int i = 0; i < 49; i++)
	{
		sort(t[i] + 1, t[i] + cnt[i] + 1, cmp);
		int last = -1;
		for (int j = 1; j <= cnt[i]; j++)
		{
			if(last * 49 + i > t[i][j].a + 49 * t[i][j].b) continue;
			ans += t[i][j].a / 49 + t[i][j].b - max(last, t[i][j].a / 49 - 1);
			last = t[i][j].a / 49 + t[i][j].b;
		} 
	}
	printf("%lld\n", ans);
	return 0;
}