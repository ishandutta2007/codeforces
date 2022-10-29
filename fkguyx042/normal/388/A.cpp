#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 105;

int n, cnt[N], tmp;

void init () {
	int a;
	tmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		tmp = max(a, tmp);
		cnt[a]++;
	}
}

void set(int x, int c) {
	if (x > tmp) return;

	if (c > x || cnt[x] == 0) {
		set(x+1, c);
	} else {
		cnt[x]--;
		set(x, c+1);
	}
}

int solve () {
	int ans = 0;
	for (int i = 0; i <= tmp; i++) {
		while (cnt[i]) {
			set(i, 0); 
			ans++;
		}
	}
	return ans;
}

int main () {
	memset(cnt, 0, sizeof(cnt));
	init();
	printf("%d\n", solve());
	return 0;
}