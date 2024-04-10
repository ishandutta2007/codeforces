#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
LL a[maxn * 2];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; i += 1)
		scanf("%lld", a + i);
	sort(a, a + 2 * n);
	LL ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	for(int i = 1; i < n; i += 1)
		ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
	printf("%lld", ans);
}