#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int s = 0;
		LL sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), s = max(s, a[i]), sum += a[i];		
		LL t = s * (n - 1ll) - sum;
		if (t < 0) {
			t += (-t + n - 2) / (n - 1) * (n - 1);
		}
		printf("%lld\n", t);
	}	
	return 0;
}