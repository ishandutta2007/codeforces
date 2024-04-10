#include <bits/stdc++.h>

using namespace std;

int f[3], n, x, ans;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		f[x]++;
	}
	ans = min(f[1], f[2]);
	f[1] -= ans;
	ans += f[1] / 3;
	printf("%d\n", ans);
}