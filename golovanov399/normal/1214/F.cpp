#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()
 
#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
struct Shit {
	int pos;
	int tp;
	int id;
 
	pair<int, int> asPair() const {
		return {pos, tp};
	}
 
	bool operator <(const Shit& ot) const {
		return asPair() < ot.asPair();
	}
};
 
struct Node {
	array<long long, 2> sum;
	int bal;
	int minbal;
	int maxbal;
};
 
Node empty_node = {
	{{0, 0}},
	0,
	0,
	0
};
 
Node merge(const Node& a, const Node& b) {
	return {
		{{a.sum[0] + b.sum[0], a.sum[1] + b.sum[1]}},
		a.bal + b.bal,
		min(a.minbal, a.bal + b.minbal),
		max(a.maxbal, a.bal + b.maxbal)
	};
}
 
struct SegTree {
	int n;
	vector<Node> a;
 
	SegTree(const vector<Shit>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n, empty_node);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i].sum = {{0, 0}};
			a[n + i].sum[ar[i].tp] += ar[i].pos;
			a[n + i].bal = ar[i].tp * 2 - 1;
			a[n + i].minbal = min(0, a[n + i].bal);
			a[n + i].maxbal = max(0, a[n + i].bal);
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}
 
	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return empty_node;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return merge(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}
 
	Node get(int l, int r) {
		return get(1, 0, n, l, r);
	}
 
	pair<int, int> findNonneg(int v, int l1, int r1, int l, int r, int thres) {
		if (l >= r1 || l1 >= r) {
			return {-1, 0};
		}
		if (l <= l1 && r >= r1) {
			if (a[v].minbal >= thres) {
				return {-1, a[v].bal};
			}
			if (v >= n) {
				return {l1, a[v].bal};
			}
		}
		int m = (l1 + r1) / 2;
		auto res = findNonneg(v + v, l1, m, l, r, thres);
		if (res.first == -1) {
			auto tmp = findNonneg(v + v + 1, m, r1, l, r, thres - res.second);
			tmp.second += res.second;
			return tmp;
		} else {
			return res;
		}
	}
 
	pair<int, int> findNonpos(int v, int l1, int r1, int l, int r, int thres) {
		if (l >= r1 || l1 >= r) {
			return {-1, 0};
		}
		if (l <= l1 && r >= r1) {
			if (a[v].maxbal <= thres) {
				return {-1, a[v].bal};
			}
			if (v >= n) {
				return {l1, a[v].bal};
			}
		}
		int m = (l1 + r1) / 2;
		auto res = findNonpos(v + v, l1, m, l, r, thres);
		if (res.first == -1) {
			auto tmp = findNonpos(v + v + 1, m, r1, l, r, thres - res.second);
			tmp.second += res.second;
			return tmp;
		} else {
			return res;
		}
	}
 
	int findLongest(int pos, int len) {
		if (get(pos, pos + 1).bal > 0) {
			auto tmp = findNonneg(1, 0, n, pos, pos + len, 0).first;
			if (tmp == -1) {
				return len;
			} else {
				return tmp - pos;
			}
		} else {
			auto tmp = findNonpos(1, 0, n, pos, pos + len, 0).first;
			if (tmp == -1) {
				return len;
			} else {
				return tmp - pos;
			}
		}
	}
};
 
const int L = 20;
const int N = 888888;
long long howmuch[L][N];
long long sums[L][N];
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
	int m = nxt(), n = nxt();
	vector<Shit> a(2 * n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), 0, i};
	}
	for (int i = 0; i < n; ++i) {
		a[n + i] = {nxt(), 1, i};
	}
 
	sort(all(a));
	for (int i = 0; i < 2 * n; ++i) {
		a.push_back({a[i].pos + m, a[i].tp, a[i].id});
	}
 
	SegTree tree(a);
	for (int i = 0; i < 2 * n; ++i) {
		howmuch[0][i] = tree.findLongest(i, 2 * n);
		// cerr << i << " " << howmuch[0][i] << ", ";
		auto tmp = tree.get(i, i + howmuch[0][i]).sum;
		sums[0][i] = abs(tmp[0] - tmp[1]);
	}
	// cerr << "\n";
	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			int idx = (j + howmuch[i - 1][j]) % (2 * n);
			howmuch[i][j] = howmuch[i - 1][j] + howmuch[i - 1][idx];
			sums[i][j] = sums[i - 1][j] + sums[i - 1][idx];
		}
	}
 
	pair<long long, int> ans = {LLONG_MAX, -1};
	for (int i = 0; i < 2 * n; ++i) {
		int len = 0;
		int cur = i;
		long long res = 0;
		for (int j = L - 1; j >= 0; --j) {
			if (len + howmuch[j][cur] > 2 * n) {
				continue;
			}
			len += howmuch[j][cur];
			res += sums[j][cur];
			cur = (cur + howmuch[j][cur]) % (2 * n);
		}
		if (len < 2 * n) {
			auto tmp = tree.get(cur, cur + 2 * n - len).sum;
			res += abs(tmp[0] - tmp[1]);
		}
		ans = min(ans, {res, i});
	}
 
	printf("%lld\n", ans.first);
	vector<int> answer(n);
	vector<int> st;
	int cur = ans.second;
	int need = a[cur].tp;
	for (int i = 0; i < 2 * n; ++i) {
		if (a[cur].tp == need) {
			st.push_back(a[cur].id);
		} else {
			if (!need) {
				answer[st.back()] = a[cur].id;
			} else {
				answer[a[cur].id] = st.back();
			}
			st.pop_back();
		}
		cur += 1;
		if (cur == 2 * n) {
			cur = 0;
		}
		if (st.empty()) {
			need = a[cur].tp;
		}
	}
 
	for (int x : answer) {
		printf("%d ", x + 1);
	}
	printf("\n");
 
	return 0;
}