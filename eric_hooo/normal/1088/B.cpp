#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int now = 0, base = 0;
	for (int i = 0; i < k; i++){
		printf("%d\n", now == n ? 0 : a[now] - base);
		if (now == n) continue;
		base += a[now] - base, now++;
		while (now < n && a[now] == a[now - 1]) now++;
	}
	return 0;
}