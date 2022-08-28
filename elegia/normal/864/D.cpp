#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <vector>

#define LOG(FMT) fprintf(stderr, FMT...)

using namespace std;

const int N = 200010;

int n, q, head = 1;
int a[N];
int cnt[N];
bool f[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (++cnt[a[i]] > 1)
			++q;
	}
	printf("%d\n", q);
	for (int i = 1; i <= n; ++i) {
		while (cnt[head])
			++head;
		if (cnt[a[i]] > 1) {
			if (a[i] < head && !f[a[i]]) {
				f[a[i]] = true;
				continue;
			}
			--cnt[a[i]];
			a[i] = head;
			++cnt[head];
		}
	}
	printf("%d", a[1]);
	for (int i = 2; i <= n; ++i)
		printf(" %d", a[i]);
	putchar('\n');
	return 0;
}