#include <bits/stdc++.h>

using namespace std;

int n, x, freq[5], ans;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		freq[x]++;
	}
	
	ans = freq[4];
	
	ans += freq[3];
	freq[1] -= min(freq[1], freq[3]);
	
	ans += freq[2]/2;

	if(freq[2] % 2 == 1) {
		ans++;
		freq[1] -= min(freq[1], 2);
	}
	
	ans += freq[1] / 4;
	if(freq[1] % 4) ans++;
	
	printf("%d\n", ans);
	return 0;
}