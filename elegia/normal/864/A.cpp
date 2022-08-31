#include <cstdio>
#include <cstdlib>

#include <algorithm>

#define LOG(FMT) fprintf(stderr, FMT...)

using namespace std;

const int N = 110;

int n, a, b, cnt, ca, cb, x;
int f[N];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (!f[x]) {
			f[x] = ++cnt;
			if (cnt == 1)
				a = x;
			else if (cnt == 2)
				b = x;
			else {
				puts("NO");
				return 0;
			}
		} else if (f[x] == 1)
			++ca;
		else
			++cb;
	}
	if (cnt == 2 && ca == cb) {
		printf("YES\n%d %d\n", a, b);
	} else
		puts("NO");
	return 0;
}