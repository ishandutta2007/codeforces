#include <cstdio>

#include <vector>
#include <set>

using namespace std;

const int N = 100010;

int q;
vector<int> div[N];
set<int> vid[N];
bool vis[N];

bool pred(int k, int l, int r) {
	if (r < l)
		return false;
	set<int>::iterator it = vid[k].lower_bound(l);
	if (it == vid[k].end() || *it > r)
		return false;
	return true;
}

int main() {
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			div[j].push_back(i);
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			if (vis[x])
				continue;
			vis[x] = true;
			for (int d : div[x]) {
				vid[d].insert(x);
			}
		} else {
			int k, s;
			scanf("%d%d", &k, &s);
			s -= x;
			if (x % k != 0 || s <= 0) {
				puts("-1");
				continue;
			}
			int cur = 0;
			for (int i = 19; i >= 0; --i) {
				if (!((x >> i) & 1)) {
					int l = cur | (1 << i), r = cur + (1 << (i + 1)) - 1;
					r = min(r, s);
					if (pred(k, l, r))
						cur |= 1 << i;
				} else {
					int l = cur, r = cur + (1 << (i)) - 1;
					r = min(r, s);
					if (!pred(k, l, r))
						cur |= 1 << i;
				}
			}
			if (cur <= s && vid[k].count(cur))
				printf("%d\n", cur);
			else
				puts("-1");
		}
	}
	return 0;
}