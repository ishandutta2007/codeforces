#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <map>

#define LOG(FMT...) fprintf(stderr)

using namespace std;

typedef long long ll;

int n, m;
ll ans;
map<int, int> mp;

int main() {
	scanf("%d", &n);
	while (n--) {
		int a, x;
		scanf("%d%d", &a, &x);
		mp[a] = max(mp[a], x);
	}
	scanf("%d", &m);
	while (m--) {
		int a, x;
		scanf("%d%d", &a, &x);
		mp[a] = max(mp[a], x);
	}
	for (pair<int, int> pr : mp)
		ans += pr.second;
	printf("%lld\n", ans);
	return 0;
}