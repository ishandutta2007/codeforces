#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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

	int get(int pos) const {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) const {
		return get(r - 1) - get(l - 1);
	}
};

const int N = 333'333;

vector<int> a[N];
int par[N];
int sz[N];
int tin[N], tout[N];
int timer = 0;

vector<int> order[N];

void dfs(int v) {
	sz[v] = 1;
	tin[v] = timer++;
	for (int x : a[v]) {
		par[x] = v;
		dfs(x);
		sz[v] += sz[x];
	}
	tout[v] = timer;
}

void solve() {
	int n = nxt();
	vector<int> num(n);
	vector<int> place(n);
	for (int i = 0; i < n; ++i) {
		num[i] = nxt() - 1;
		place[num[i]] = i;
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
	}
	dfs(0);
	par[0] = -1;

	Fenwick f(n);
	for (int i = 0; i < n; ++i) {
		f.add(tin[i], 1);
	}

	long long days = 0;
	vector<char> in_stack(n);
	vector<int> st = {0};
	in_stack[0] = 1;
	int v = 0;
	while (place[v] > 0) {
		int u = place[v];
		if (f.get(tin[u], tout[u]) != 1) {
			break;
		}
		int x = u;
		while (!in_stack[x]) {
			in_stack[x] = 1;
			// cerr << par[x] + 1 << " --- " << x + 1 << "\n";
			order[par[x]].push_back(x);
			x = par[x];
		}
		if (x != st.back()) {
			cout << "NO\n";
			return;
		}
		while (x != u) {
			st.push_back(x = order[x].back());
		}
		st.pop_back();
		days += st.size();
		in_stack[u] = false;
		f.add(tin[u], -1);
		++v;
	}

	// check that everything is ok with v
	int u = place[v];
	if (!in_stack[u]) {
		while (!in_stack[u]) {
			order[par[u]].push_back(u);
			u = par[u];
		}
		if (u != st.back()) {
			cout << "NO\n";
			return;
		}
	}

	int h = 0;
	u = place[v];
	for (int x = u; x > 0; x = par[x]) {
		++h;
	}
	days += h;

	// check that everything is ok with above v
	for (int i = 0; i < n; ++i) {
		// cerr << i + 1 << ": ";
		// for (int x : order[i]) {
		// 	cerr << x + 1 << " ";
		// }
		// cerr << "\n";
		set<int> S(all(a[i]));
		for (int x : order[i]) {
			S.erase(x);
		}
		vector<int> rem(all(S));
		sort(all(rem), [&](int u, int v) {
			return num[u] < num[v];
		});
		order[i].insert(order[i].end(), all(rem));
	}

	vector<int> ans(n);
	function<void(int, int)> fill_ans = [&](int v, int cur) {
		// cerr << "ans[" << v + 1 << "] = " << cur + 1 << "\n";
		ans[v] = cur;
		cur += 1;
		for (int x : order[v]) {
			// cerr << v + 1 << " -> " << x + 1 << "\n";
			fill_ans(x, cur);
			cur += sz[x];
		}
	};
	fill_ans(0, 0);

	// check
	{
		auto cur = ans;
		vector<int> p(n, 0);
		vector<int> st = {0};
		deque<int> vals;
		vals.push_back(0);
		for (int i = 0; i < v; ++i) {
			while (p[st.back()] < (int)order[st.back()].size()) {
				int u = st.back();
				st.push_back(order[u][p[u]++]);
				vals.push_back(cur[st.back()]);
			}
			cur[st.back()] = i;
			st.pop_back();
			vals.pop_front();
		}
		while (p[st.back()] < (int)order[st.back()].size()) {
			int u = st.back();
			st.push_back(order[u][p[u]++]);
			vals.push_back(cur[st.back()]);
		}
		vals.pop_front();
		for (int i = 0; i < h; ++i) {
			cur[st[i]] = vals[i];
		}
		cur[st[h]] = v;
		// assert((int)vals.size() + 1 == (int)st.size());
		for (int i = h + 1; i < (int)st.size(); ++i) {
			cur[st[i]] = vals[i - 1];
		}
		// for (int x : cur) {
		// 	cerr << x + 1 << " ";
		// }
		// cerr << "\n";
		if (cur != num) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	cout << days << "\n";
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}