#include <bits/stdc++.h>
using namespace std;
 
void test_case() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> a(n, vector<int>(5));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 5; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	auto better = [&](int i, int j) {
		int cnt = 0;
		for(int k = 0; k < 5; ++k) {
			if(a[i][k] < a[j][k]) {
				++cnt;
			}
		}
		return cnt >= 3;
	};
	int best = 0;
	for(int i = 1; i < n; ++i) {
		if(better(i, best)) {
			best = i;
		}
	}
	bool ok = true;
	for(int i = 0; i < n; ++i) {
		if(i != best && better(i, best)) {
			ok = false;
		}
	}
	if(ok) {
		printf("%d\n", best + 1);
	}
	else {
		puts("-1");
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++) {
		test_case();
	}
}