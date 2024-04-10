#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int cnt[1010];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	printf("%d\n", *min_element(cnt + 1, cnt + n + 1));
	return 0;
}