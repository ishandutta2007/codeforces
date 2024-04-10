#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<int> a[N];
double p[N];
double s[N];

struct Fenwick {
	int n;
	vector<double> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, double x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	double get(int pos) {
		double res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	double get(int l, int r) {
		return get(r - 1) - get(l - 1);
	}
};

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &p[i]);
		p[i] = 1 - p[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt(), v = nxt();
		a[u].push_back(v);
		a[v].push_back(u);
	}

	double ans = accumulate(p, p + n, 0.0);
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) {
			if (j > i) continue;
			ans -= p[i] * p[j];
		}
	}

	queue<int> qu;
	vector<int> idx(n, -1);
	vector<int> l(n, -1), r(n, -1), par(n, -1);
	qu.push(0);
	int cur = 0;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		idx[v] = cur++;
		for (int x : a[v]) {
			if (idx[x] == -1) {
				qu.push(x);
			} else {
				par[v] = x;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) {
			if (j == par[i]) continue;
			if (l[i] == -1) l[i] = idx[j];
			r[i] = idx[j];
		}
		++r[i];
	}

	Fenwick fenw(n);
	for (int i = 0; i < n; ++i) {
		fenw.add(idx[i], p[i]);
	}
	int q = nxt();
	while (q--) {
		int v = nxt();
		double prob;
		scanf("%lf", &prob);
		prob = 1 - prob;
		ans += prob - p[v];
		double sum = 0;
		if (par[v] != -1) {
			sum += p[par[v]];
		}
		if (l[v] != -1) {
			sum += fenw.get(l[v], r[v]);
		}
		ans -= (prob - p[v]) * sum;
		fenw.add(idx[v], prob - p[v]);
		p[v] = prob;
		printf("%.10lf\n", ans);
	}

	return 0;
}