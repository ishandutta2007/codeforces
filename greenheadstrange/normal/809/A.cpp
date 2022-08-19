#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300005
using namespace std;
int n; 
int x[maxn];
int mode = 1000000007;
int pw[maxn];
int main()
{
	scanf("%d", &n);
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2, pw[i] %= mode;
	for(int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n);
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += x[i] * (long long)pw[i - 1], 
		ans -= x[i] * (long long)pw[n - i], 
		ans %= mode;
	ans += mode;
	ans %= mode;
	printf("%I64d\n", ans);
	return 0;
}