#include <cstdio>

#include <algorithm>
#include <limits>
#include <set>
#include <map>

using namespace std;

struct Node {
	int a, i;

	bool operator<(const Node& rhs) const { return a < rhs.a; }
};

const int N = 200010;

int n, ans = numeric_limits<int>::max(), ansc;
Node q[N];
set<int> avail;
int cnt[N], l[N], r[N];
bool f[N];

void rmv(int x) {
	if (--cnt[x] == 0)
		avail.erase(x);
}

void add(int x) {
	if (cnt[x]++ == 0)
		avail.insert(x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &q[i].a);
		q[i].i = i;
	}
	sort(q + 1, q + n + 1);
	for (int i = 1; i <= n; ++i) {
		int pos = q[i].i;
		f[pos] = true;
		if (f[pos - 1]) {
			rmv(r[pos - 1] - l[pos - 1]);
			l[pos] = l[pos - 1];
		} else
			l[pos] = pos;
		if (f[pos + 1]) {
			rmv(r[pos + 1] - l[pos + 1]);
			r[pos] = r[pos + 1];
		} else
			r[pos] = pos;
		r[l[pos]] = r[pos];
		l[r[pos]] = l[pos];
		add(r[pos] - l[pos]);
		if (avail.size() == 1) {
			if (cnt[*avail.begin()] > ansc) {
				ansc = cnt[*avail.begin()];
				ans = q[i].a + 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}