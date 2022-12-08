#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[200000];
bool flag;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%1d", &a[i]);
	}
	flag = 1;
	for (int i = k; i < n; ++i) {
		if (a[i] != a[i % k]) {
			flag = a[i % k] > a[i];
			break;
		}
	}
	if (flag) {
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			printf("%d", a[i % k]);
		}
		puts("");
	} else {
		for (int i = 0; i < k; ++i) {
			if (a[i] != 9) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			++a[k - 1];
			for (int i = k - 1; i >= 0; --i) {
				if (a[i] < 10) {
					break;
				}
				a[i] -= 10;
				++a[i - 1];
			}
			printf("%d\n", n);
			for (int i = 0; i < n; ++i) {
				printf("%d", a[i % k]);
			}
			puts("");
		} else {
			printf("%d\n", n + 1);
			++k;
			for (int i = 0; i < n; ++i) {
				putchar(i % k ? '0' : '1');
			}
			puts("");
		}
	}
    return 0;
}