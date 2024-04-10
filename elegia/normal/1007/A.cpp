#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int n;
int a[N];
bool vis[N];

int main() {
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	for (; l <= n; ++l) {
//		if (vis[l])
//			continue;
		while (a[l] == a[r] && r <= n)
			++r;
		if (r > n)
			break;
		++ans;
		vis[r] = true;
		++r;
	}
	printf("%d\n", ans);
	return 0;
}