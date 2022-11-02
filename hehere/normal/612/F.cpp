#include <bits/stdc++.h>
using namespace std;

#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)						\
	{cerr << #a << " = {";						\
	for(int qwq = (st); qwq <= (n); ++qwq) {	\
		if(qwq == (st)) cerr << a[qwq];			\
		else cerr << ", " << a[qwq];			\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)

const int maxN = 2000 + 5;
int s, n, m, a[maxN];
vector<int> p[maxN];
vector<int> f[maxN], g[maxN];

void initialize() {
	ios::sync_with_stdio(false);
	cin >> n >> s; s--;
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<int> t(a, a + n);
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(int i = 0; i < n; ++i) a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
	m = t.size();
	for(int i = 0; i < n; ++i) p[a[i]].push_back(i);
	p[0].push_back(s);
	f[0].push_back(0);
	g[0].push_back(-1);
}

int cyc(int x, int y) {
	return y < x ? y + n - x : y - x;
}
int cont(int x, int y) {
	return cyc(y, x);
}
int sp(int x, int y) {
	return min(cyc(x, y), cont(x, y));
}
template<typename T> bool chmin(T &x, const T &y) { return y < x ? x = y, true : false; }

int solve() {
	for(int st = 1; st <= m; ++st) {
		int sz = p[st].size();
		f[st].assign(sz, maxN * maxN);
		g[st].assign(sz, -1);
		for(int i = 0; i < sz; ++i) {
			int pre = i - 1, post = i + 1;
			if(pre == -1) pre = sz - 1;
			if(post == sz) post = 0;
			for(int j = 0; j < (int)p[st - 1].size(); ++j) {
				chmin(f[st][i], f[st - 1][j] + sp(p[st - 1][j], p[st][pre]) + cont(p[st][pre], p[st][i]))
					&& (g[st][i] = j);
				chmin(f[st][i], f[st - 1][j] + sp(p[st - 1][j], p[st][post]) + cyc(p[st][post], p[st][i]))
					&& (g[st][i] = j);
			}
		}
//		display(st);
//		displayv(p[st]);
//		displayv(f[st]);
//		displayv(g[st]);
	}
	return *min_element(f[m].begin(), f[m].end());
}

void psp(int x, int y) {
	if(cyc(x, y) <= cont(x, y)) printf("+%d\n", cyc(x, y));
	else printf("-%d\n", cont(x, y));
}

void print(int st, int i) {
	if(st == 0) return;
	int j = g[st][i];
	print(st - 1, j);
	int sz = p[st].size();
	int pre = i - 1, post = i + 1;
	if(pre == -1) pre = sz - 1;
	if(post == sz) post = 0;
	int cpre = f[st - 1][j] + sp(p[st - 1][j], p[st][pre]) + cont(p[st][pre], p[st][i]);
	int cpost = f[st - 1][j] + sp(p[st - 1][j], p[st][post]) + cyc(p[st][post], p[st][i]);
	if(cpre < cpost) {
		psp(p[st - 1][j], p[st][pre]);
		while(pre != i) {
			int pp = pre - 1;
			if(pp == -1) pp = sz - 1;
			printf("-%d\n", cont(p[st][pre], p[st][pp]));
			pre = pp;
		}
	} else {
		psp(p[st - 1][j], p[st][post]);
		while(post != i) {
			int pp = post + 1;
			if(pp == sz) pp = 0;
			printf("+%d\n", cyc(p[st][post], p[st][pp]));
			post = pp;
		}
	}
}

int main() {
	initialize();
	cout << solve() << endl;
	print(m, min_element(f[m].begin(), f[m].end()) - f[m].begin());
	return 0;
}