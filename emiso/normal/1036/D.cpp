#include <bits/stdc++.h>

using namespace std;

int n[2], a[2][300030], ans = -1;
long long l1, l2;

int main() {
	for(int j = 0; j < 2; j++) {
		scanf("%d", &n[j]);
		for(int i = 0; i < n[j]; i++) {
			scanf("%d", &a[j][i]);
		}
	}
	
	int i = 0, j = 0;
	while(i < n[0] || j < n[1]) {
		if(l1 == l2) {
			ans++;
			l1 = l2 = 0;
		}
		if(i == n[0]) {
			l2 += a[1][j++];
		}
		else if(j == n[1]) {
			l1 += a[0][i++];
		}
		else {
			if(l1 < l2) {
				l1 += a[0][i++];
			} else {
				l2 += a[1][j++];
			}
		}
	}
	if(l1 == l2) {
		ans++;
		l1 = l2 = 0;
	}
	
	if(l1 || l2) puts("-1");
	else printf("%d\n", ans);
	
	return 0;
}