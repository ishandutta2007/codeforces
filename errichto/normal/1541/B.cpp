#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		for(int i = 1; i <= n; ++i) {
			// a[i] * a[j] == i + j
			for(int product = a[i]; product <= 2 * n; product += a[i]) {
				int j = product - i;
				if(i < j && j <= n && i + j == (long long) a[i] * a[j]) {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}