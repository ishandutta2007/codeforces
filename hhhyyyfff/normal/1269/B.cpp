#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[2000], b[2000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		int diff = (b[0] - a[i] + m) % m;
		bool flag = 1;
		for (int j = 1; j < n; ++j) {
			if ((b[j] - a[(i + j) % n] + m) % m != diff) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d\n", diff);
			return 0;
		}
	}
    return 0;
}