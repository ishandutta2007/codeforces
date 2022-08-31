#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define data jasdhjl

const int N = 10111;
int l[N*2], r[N*2];
int to_l[N*2], to_r[N*2];
using Bs = bitset<N>;
Bs data[N*2];
int sz = 1;

vector<int> to_add[N*2];

void pysh(int v, int left, int right) {
	l[v] = left;
	r[v] = right;
	if (left + 1 == right) {
		return;
	}
	int m = (left + right) / 2;
	to_l[v] = ++sz;
	pysh(to_l[v], left, m);
	to_r[v] = ++sz;
	pysh(to_r[v], m, right);
}

void build(int n) {
	pysh(1, 0, n);
}

void add(int v, int le, int ri, int x) {
	if (le >= r[v] || l[v] >= ri) {
		return;
	}
	if (le <= l[v] && ri >= r[v]) {
		to_add[v].push_back(x);
		return;
	}
	add(to_l[v], le, ri, x);
	add(to_r[v], le, ri, x);
}

int main() {
	int n = nxt(), q = nxt();
	build(n);
	while (q--) {
		int le = nxt() - 1, ri = nxt(), x = nxt();
		add(1, le, ri, x);
	}

	Bs ans;
	data[1].flip(0);
	for (int i = 1; i <= sz; ++i) {
		for (int x : to_add[i]) {
			data[i] |= (data[i] << x);
		}
		if (to_l[i]) {
			data[to_l[i]] = data[i];
			data[to_r[i]] = data[i];
		} else {
			ans |= data[i];
		}
	}

	vector<int> res;
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) {
			res.push_back(i);
		}
	}

	printf("%d\n", (int)res.size());
	for (int x : res) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}