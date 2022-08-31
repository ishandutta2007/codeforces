#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
ll ans;
int x[N];
pair<int, int> a[N * 2];
int fw[N];

void change(int k) {
	for (; k <= n; k += k & -k)
		++fw[k];
}

int query(int k) {
	int ret = 0;
	for (; k; k -= k & -k)
		ret += fw[k];
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; ++i) {
		a[i] = make_pair(x[i], i);
		a[i + n] = make_pair(i, 0);
	}
	sort(a + 1, a + n * 2 + 1);
	for (int i = n * 2; i; --i) {
		if (a[i].second == 0)
			ans += query(min(n, x[a[i].first]));
		else
			change(a[i].second);
	}
	for (int i = 1; i <= n; ++i)
		if (x[i] >= i)
			--ans;
	printf("%lld\n", ans / 2);
	return 0;
}