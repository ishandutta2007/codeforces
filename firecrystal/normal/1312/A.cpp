#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		if (n % m == 0) puts("YES");
		else puts("NO");
	}
}