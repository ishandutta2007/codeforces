#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	for(int& x : a) {
		scanf("%d", &x);
	}
	pair<int,int> best{INT_MAX, INT_MAX};
	for(int i = 0; i + k < n; ++i) {
		int dist = a[i+k] - a[i];
		int middle = (a[i] + a[i+k]) / 2;
		best = min(best, make_pair(dist, middle));
	}
	printf("%d\n", best.second);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}