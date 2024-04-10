#include <bits/stdc++.h>
using namespace std;

int p[200010];

int main () {
	int n, a, b, k; scanf("%d%d%d%d", &n, &a, &b, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	vector <int> all;
	for (int i = 0; i < n; i++) {
		int x = p[i];
		x = x % (a + b);
		if (x == 0) x = a + b;
		all.push_back((x + a - 1) / a - 1);
	}
	sort(all.begin(), all.end());
	int sum = 0;
	for (int i = 0; i < all.size(); i++) {
		sum += all[i];
		if (sum > k) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", n);
	return 0;
}