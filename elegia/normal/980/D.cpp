#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>

typedef long long ll;

using namespace std;

const int N = 5010;

int n;
int a[N], prv[N], ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0)
			continue;
		for (int j = i - 1; j; --j) {
			if (a[j] == 0)
				continue;
			ll prod = (ll)a[i] * a[j];
			if (prod < 0)
				continue;
			ll s = sqrt(prod);
			while (s * s < prod)
				++s;
			if (s * s == prod) {
				prv[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool has0 = false;
		int cur = 0;
		for (int j = i; j <= n; ++j) {
			if (a[j] == 0) {
				has0 = true;
			} else {
				if (prv[j] < i)
					++cur;
			}
			++ans[cur ? cur : 1];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}