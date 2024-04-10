#include <stdio.h>
#include <bits/stdc++.h>

 
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) printf("2\n");
		else printf("%lld\n", i*1ll*(i+1)*1ll*(i+1) - (i-1));
	}
}


int main() {
    solve();
}