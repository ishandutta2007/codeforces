#include <cstdio>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 110;

int n;
int a[N * 2];

int main() {
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n * 2; i += 2) {
		for (int j = n * 2 - 1; j > i; --j)
			if (a[j + 1] == a[i]) {
				++ans;
				swap(a[j], a[j + 1]);
			}
	}
	printf("%d\n", ans);
	return 0;
}