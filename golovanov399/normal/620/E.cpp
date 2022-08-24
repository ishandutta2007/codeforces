#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int mbc(long long x){
	int res = 0;
	while (x){
		res += x % 2;
		x /= 2;
	}
	return res;
}

struct Tree{
	int n;
	vector<long long> a;
	vector<long long> q;

	Tree(int nn = 1){
		n = 1;
		while (n < nn)
			n *= 2;
		a.resize(n + n);
		q.resize(n + n);
	}

	Tree(const vector<long long>& ar){
		n = 1;
		while (n < ar.size())
			n *= 2;
		a.resize(n + n);
		q.resize(n + n);
		for (int i = 0; i < ar.size(); i++)
			a[n + i] = (1ll << (ar[i]));
		for (int i = n - 1; i > 0; i--)
			a[i] = a[i + i] | a[i + i + 1];
	}

	long long _get(int v, int l1, int r1, int l, int r){
		if (l >= r1 || l1 >= r)
			return 0;
		if (l < l1)
			l = l1;
		if (r > r1)
			r = r1;
		if (l == l1 && r == r1)
			return a[v];
		if (q[v])
			return q[v];
		int mid = (l1 + r1) / 2;
		return _get(v + v, l1, mid, l, r) | _get(v + v + 1, mid, r1, l, r);
	}

	int get(int l, int r){
		return mbc(_get(1, 0, n, l, r));
	}

	void relax(int v){
		if (q[v] == 0)
			return;
		if (v >= n){
			q[v] = 0;
			return;
		}
		a[v + v] = q[v + v] = q[v];
		a[v + v + 1] = q[v + v + 1] = q[v];
		q[v] = 0;
	}

	void _chg(int v, int l1, int r1, int l, int r, int x){
		if (l >= r1 || l1 >= r)
			return;
		if (l < l1)
			l = l1;
		if (r > r1)
			r = r1;
		if (l == l1 && r == r1){
			a[v] = q[v] = (1ll << x);
			return;
		}
		relax(v);
		int mid = (l1 + r1) / 2;
		_chg(v + v, l1, mid, l, r, x);
		_chg(v + v + 1, mid, r1, l, r, x);
		a[v] = a[v + v] | a[v + v + 1];
	}

	void chg(int l, int r, int x){
		_chg(1, 0, n, l, r, x);
	}
};

const int N = 444444;
int tin[N], tout[N];
int tt = 0;
vector<itn> a[N];
char used[N];
vector<int> order;

void dfs(int v){
	used[v] = 1;
	tin[v] = tout[v] = tt++;
	order.push_back(v);
	for (auto x : a[v]){
		if (!used[x]){
			dfs(x);
			tout[v] = tt++;
			order.push_back(v);
		}
	}
}

int main(){

	int n = nxt(), m = nxt();
	vector<int> c(n);
	for (itn i = 0; i < n; i++)
		c[i] = nxt() - 1;
	for (int i = 0; i < n - 1; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	int sz = order.size();
	vector<long long> qq(sz);
	for (itn i = 0; i < sz; i++)
		qq[i] = c[order[i]];

	Tree tree(qq);
	while (m--){
		int t = nxt();
		if (t == 1){
			int x = nxt() - 1, y = nxt() - 1;
			tree.chg(tin[x], tout[x] + 1, y);
		} else {
			int v = nxt() - 1;
			printf("%d\n", tree.get(tin[v], tout[v] + 1));
		}
	}

	return 0;
}