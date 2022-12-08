#include <bits/stdc++.h>

using namespace std;

int t, n, a[200000];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		priority_queue<long long> h;
		long long sum = 0;
		for (int i = 0; i < n; ++i) sum += a[i];
		h.push(sum);
		int i = n - 1;
		while (!h.empty()) {
			long long cur = h.top();
			h.pop();
			if (cur < a[i]) break;
			if (cur == a[i]) --i; else {
				h.push(cur / 2);
				h.push(cur - cur / 2);
			}
		}
		puts(~i ? "NO" : "YES");
	}
	return 0;
}