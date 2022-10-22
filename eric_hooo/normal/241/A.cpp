#include <bits/stdc++.h>
using namespace std;

int d[1010], s[1010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &s[i]);
	}
	int maxj = 0, tot = 0, ans = 0;
	for (int i = 0; i < n; i++){
		maxj = max(maxj, s[i]);
		tot += s[i];
		if (tot < d[i]){
			int times = (d[i] - tot + maxj - 1) / maxj;
			tot += maxj * times, ans += k * times;
		}
		tot -= d[i], ans += d[i];
	}
	printf("%d\n", ans);
	return 0;
}