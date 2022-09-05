#include <bits/stdc++.h>
using namespace std;
const int nax = 5005;
int cost[nax];
int would[nax]; // how much I have after the i-th day
int use[nax];
void calc_would(int n) {
	for(int i = 1; i <= n; ++i)
		would[i] = would[i-1] - use[i] + (cost[i] - use[i]) / 10;
}
int main() {
	#define money would[0]
	int n;
	scanf("%d%d", &n, &money);
	for(int i = 1; i <= n; ++i) scanf("%d", &cost[i]);
	calc_would(n);
	int tmp = would[n];
	for(int i = n; i >= 1; --i) {
		int czapa = min(cost[i] / 2, cost[i] % 10);
		tmp = min(tmp, would[i-1]);
		use[i] = min(czapa, tmp);
		tmp -= use[i];
	}
	for(int cnt = 10; cnt >= 1; --cnt) {
		calc_would(n);
		tmp = would[n];
		for(int i = n; i >= 1; --i) {
			while(use[i] + cnt <= cost[i] / 2) {
				if(would[i-1] - use[i] >= cnt && tmp >= cnt + 1) {
					use[i] += cnt;
					tmp -= cnt + 1;
				}
				else break;
			}
			tmp = min(tmp, would[i-1] - use[i]);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans += cost[i] - use[i];
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i) printf("%d ", use[i]);
	puts("");
}