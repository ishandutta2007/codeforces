#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, b[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		sort(b + 1, b + 1 + n);
		bool ok = false;
		for (int i = 2; i <= n; i++) {
			if (b[i] == b[i - 1]) {
				ok = true;
				break;
			}
		}		
		puts(ok ? "YES" : "NO");
	}	
	return 0;
}