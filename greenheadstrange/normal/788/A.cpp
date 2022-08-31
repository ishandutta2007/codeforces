#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005 
#define ll long long
using namespace std;
ll ans = -2147483647;
ll a[maxn];
ll sum[maxn];
ll b[maxn];
ll ex1[maxn], ex2[maxn]; // 1 : 1 2 : -1
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	for(int i = 1; i < n; i++)
		ans = max(ans, abs(a[i] - a[i + 1]));
	for(int i = 1; i < n; i++)
		b[i] = abs(a[i] - a[i + 1]);
	for(int i = n - 1; i >= 1; i--)
		ex1[i] = max(b[i], b[i] + ex2[i + 1]), ex2[i] = max(-b[i], -b[i] + ex1[i + 1]), 
		ans = max(ans, ex1[i]);
	printf("%I64d\n", ans);
	return 0;
}