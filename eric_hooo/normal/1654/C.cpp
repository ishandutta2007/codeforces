#include <bits/stdc++.h>
using namespace std;

multiset <long long> all;
queue <long long> q;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long S = 0; all.clear();
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			all.insert(x), S += x;
		}
		while (!q.empty()) q.pop();
		q.push(S);
		int cut = 0;
		while (!q.empty()) {
			long long x = q.front(); q.pop();
			if (all.count(x)) all.erase(all.find(x));
			else {
				if (cut == n - 1) {
					printf("NO\n");
					goto END;
				}
				cut++;
				q.push(x >> 1), q.push(x + 1 >> 1);
			}
		}
		printf("YES\n");
		END:;
	}
	return 0;
}