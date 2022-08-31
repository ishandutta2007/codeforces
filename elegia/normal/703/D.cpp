#include <cstdio>

#include <functional>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

const int N = 1000010;

int n, m;
int x[N], xsum[N], fw[N], ans[N];
map<int, int> lastIndex;
vector<pair<int, int> > queries[N];

int lowBit(int x) { return x & -x; }

void change(int k, int x) {
	for (; k <= n; k += lowBit(k))
		fw[k] ^= x;
}

int query(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret ^= fw[k];
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	partial_sum(x + 1, x + n + 1, xsum + 1, bit_xor<int>());
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		queries[r].push_back(make_pair(l, i));
	}
	for (int i = 1; i <= n; ++i) {
		map<int, int>::iterator it = lastIndex.find(x[i]);
		if (it != lastIndex.end()) {
			change(it->second, x[i]);
			change(i, x[i]);
			lastIndex[x[i]] = i;
		} else {
			change(i, x[i]);
			lastIndex.insert(make_pair(x[i], i));
		}
		int qi = query(i);
		for (auto&& q : queries[i])
			ans[q.second] = qi ^ query(q.first - 1) ^ xsum[i] ^ xsum[q.first - 1];
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}