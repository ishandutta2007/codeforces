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

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

bool check(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b, int need) {
	long long cnt = 0;
	int j = (int)b.size() - 1;
	Fenwick f(need + 1);
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		while (j >= 0 && a[i].first + b[j].first >= need) {
			f.add(min(need, b[j--].second), 1);
		}
		cnt += f.get(need) - f.get(need - a[i].second - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (a[i].first + a[i].second >= need) {
			cnt -= 1;
		}
	}
	return cnt > 0;
}

const int N = 222222;
vector<int> a[N];

vector<int> getDist(int start, int n) {
	vector<int> dist(n, -1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : a[v]) {
			if (dist[x] > -1) {
				continue;
			}
			dist[x] = dist[v] + 1;
			q.push(x);
		}
	}
	return dist;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), k = nxt();
	vector<int> good;
	for (int i = 0; i < k; ++i) {
		good.push_back(nxt() - 1);
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	auto d1 = getDist(0, n);
	auto d2 = getDist(n - 1, n);

	vector<pair<int, int>> ar;
	for (int i : good) {
		ar.push_back({d1[i], d2[i]});
	}
	auto br = ar;
	for (auto& p : br) {
		swap(p.first, p.second);
	}
	sort(all(ar));
	sort(all(br));
	int l = 0, r = n + 2;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (check(ar, br, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << min(d2[0], r) << "\n";

	return 0;
}