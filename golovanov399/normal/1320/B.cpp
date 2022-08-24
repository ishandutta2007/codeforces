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

const int N = 222222;
vector<int> a[N];
int d[N];
int cnt_nx[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[v].push_back(u);
	}

	int k = nxt();
	vector<int> p(k);
	for (int i = 0; i < k; ++i) {
		p[i] = nxt() - 1;
	}

	fill_n(d, n, 1e9);
	d[p.back()] = 0;
	queue<int> q;
	q.push(p.back());
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : a[v]) {
			if (d[x] > d[v] + 1) {
				d[x] = d[v] + 1;
				cnt_nx[x] = 1;
				q.push(x);
			} else if (d[x] == d[v] + 1) {
				cnt_nx[x] += 1;
			}
		}
	}

	int min_ans = 0, max_ans = 0;
	for (int i = 0; i < k - 1; ++i) {
		if (d[p[i]] != d[p[i + 1]] + 1) {
			min_ans += 1;
			max_ans += 1;
		} else if (cnt_nx[p[i]] > 1) {
			max_ans += 1;
		}
	}

	cout << min_ans << " " << max_ans << "\n";

	return 0;
}