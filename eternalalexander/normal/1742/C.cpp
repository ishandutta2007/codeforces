#include <bits/stdc++.h>

char G[100][100];

void solve() {
	for (int i = 1; i <= 8; ++ i) scanf("%s",G[i] + 1);
	for (int i = 1; i <= 8; ++ i) {
		int flag = 1;
		for (int j = 1; j <= 8; ++ j) if (G[i][j] != 'R') flag = 0;
		if (flag) { puts("R"); return ; }
	}
	puts("B");
	
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}