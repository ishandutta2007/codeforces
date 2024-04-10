#include <bits/stdc++.h>
using namespace std;

char a[1000010], b[1000010];

int main(){
	scanf("%s%s", a, b);
	int n = strlen(a), m = strlen(b);
	int cnt = 0;
	int tot = 0;
	for (int i = 0; i < m; i++){
		if (a[i] != b[i]) cnt ^= 1;
		if (i && b[i - 1] != b[i]) tot ^= 1;
	}
	int ans = cnt & 1 ? 0 : 1;
	for (int i = 0; i < n - m; i++){
		cnt ^= tot;
		if (a[i] != b[0]) cnt ^= 1;
		if (a[i + m] != b[m - 1]) cnt ^= 1;
		ans += cnt & 1 ? 0 : 1;
	}
	printf("%d\n", ans);
	return 0;
}