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

const int N = 111111;
const int MX = 19;
vector<int> a[N];
int p[N][MX];
int level[N];
char used[N];
int tin[N], tout[N];
vector<int> order;

#define tm sdfaf
int tm;

const int A = 10;

vector<int> ppl[N][MX];

vector<int> merge(const vector<int>& L, const vector<int>& R){
	int l = 0, r = 0;
	vector<int> res;
	while (res.size() < A && (l < L.size() || r < R.size())){
		if (l == L.size())
			res.push_back(R[r++]);
		else
		if (r == R.size())
			res.push_back(L[l++]);
		else
		if (L[l] < R[r])
			res.push_back(L[l++]);
		else
			res.push_back(R[r++]);
	}
	return res;
}

void dfs(int v){
	tin[v] = tout[v] = tm++;
	order.push_back(v);
	used[v] = 1;
	for (auto x : a[v]){
		if (!used[x]){
			p[x][0] = v;
			int i = 0;
			while (p[x][i] > -1){
				int l = 0, r = 0;
				int pr = p[x][i];
				ppl[x][i + 1] = merge(ppl[x][i], ppl[pr][i]);
				p[x][i + 1] = p[p[x][i]][i];
				i++;
			}
			while (i < MX){
				p[x][i++] = -1;
				if (i < MX)
					ppl[x][i] = ppl[x][i - 1];
			}
			level[x] = level[v] + 1;
			dfs(x);
			tout[v] = tm++;
			order.push_back(v);
		}
	}
}

struct Tree{
	vector<int> a;
	int n;

	Tree(const vector<int>& ar){
		n = 1;
		while (n < ar.size())
			n *= 2;
		a.resize(n + n);
		for (int i = n + n - 1; i > 0; i--){
			if (i >= n){
				if (i - n < ar.size())
					a[i] = ar[i - n];
				else
					a[i] = -1;
			} else {
				if (a[i + i] == -1)
					a[i] = -1;
				else if (a[i + i + 1] == -1)
					a[i] = a[i + i];
				else
					a[i] = (level[a[i + i]] < level[a[i + i + 1]]) ? a[i + i] : a[i + i + 1];
			}
		}
	}

	Tree(){};

	int _get(int v, int l1, int r1, int l, int r){
		if (l < l1)
			l = l1;
		if (r > r1)
			r = r1;
		if (l >= r1 || l1 >= r)
			return -1;
		if (l == l1 && r == r1)
			return a[v];
		int mid = (l1 + r1) / 2;
		int u = _get(v + v, l1, mid, l, r);
		int w = _get(v + v + 1, mid, r1, l, r);
		if (u == -1)
			return w;
		else if (w == -1)
			return u;
		else
			return (level[u] < level[w]) ? u : w;
	}

	int get(int l, int r){
		return _get(1, 0, n, l, r);
	}
} tree;

int lca(int u, int v){
	int t1 = tin[u], t2 = tin[v];
	if (t1 > t2)
		swap(t1, t2);
	return tree.get(t1, t2 + 1);
}

vector<int> get(int u, int v){
	int w = lca(u, v);
	cerr << u << " " << v << " " << w << "\n";
	vector<int> res;
	int k = MX - 1;
	while (u != w){
		while (level[u] - level[w] < (1 << k))
			k--;
		res = merge(res, ppl[u][k]);
		u = p[u][k];
	}
	k = MX - 1;
	while (v != w){
		while (level[v] - level[w] < (1 << k))
			k--;
		res = merge(res, ppl[v][k]);
		v = p[v][k];
	}
	res = merge(res, ppl[w][0]);
	return res;
}

int main(){

	int n = nxt(), m = nxt(), q = nxt();
	for (int i = 0; i < n - 1; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 0; i < m; i++){
		int x = nxt() - 1;
		ppl[x][0].push_back(i + 1);
	}

	for (int i = 0; i < MX; i++)
		p[0][i] = -1;
	for (int i = 1; i < MX; i++)
		ppl[0][i] = ppl[0][0];
	dfs(0);

	tree = Tree(order);

	while (q--){
		int u = nxt() - 1, v = nxt() - 1;
		int k = nxt();
		// cerr << "qwe";
		auto cur = get(u, v);
		// cerr << "rty\n";
		if (cur.size() > k)
			cur.resize(k);
		printf("%d ", (int)cur.size());
		for (auto x : cur)
			printf("%d ", x);
		puts("");
	}

	return 0;
}