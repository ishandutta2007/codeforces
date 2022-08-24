#include <bits/stdc++.h>

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Tree{
	int n;
	vector<long long> a;
	vector<long long> ad;

	Tree(int m){
		n = 1;
		while (n < m)
			n *= 2;
		a.resize(n + n);
		ad.resize(n + n);
	}

	Tree(const vector<int>& ar){
		n = 1;
		while (n < ar.size())
			n *= 2;
		a.resize(n + n);
		ad.resize(n + n);
		for (int i = 0; i < (int)ar.size(); i++){
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; i--){
			a[i] = a[2 * i] + a[2 * i + 1];
		}
	}

	void _add(int v, int l1, int r1, int l, int r, long long x){
		if (l < l1)
			l = l1;
		if (r > r1)
			r = r1;
		if (l >= r1 || l1 >= r)
			return;
		a[v] += x * (r - l);
		if (l == l1 && r == r1){
			ad[v] += x;
			return;
		}
		int mid = (l1 + r1) >> 1;
		_add(v + v, l1, mid, l, r, x);
		_add(v + v + 1, mid, r1, l, r, x);
	}

	void add(int l, int r, long long x){
		// cerr << "ARA TI 4O\n";
		_add(1, 0, n, l, r, x);
	}

	long long _get(int v, int l1, int r1, int l, int r){
		if (l < l1)
			l = l1;
		if (r > r1)
			r = r1;
		if (l >= r1 || l1 >= r)
			return 0;
		if (l == l1 && r == r1){
			return a[v];
		}
		int mid = (l1 + r1) >> 1;
		return _get(v + v, l1, mid, l, r) + _get(v + v + 1, mid, r1, l, r) + ad[v] * (r - l);
	}

	long long get(int l, int r){
		return _get(1, 0, n, l, r);
	}
};

int main() {

	int n = nxt(), m = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt();
	}
	vector<int> l(m), r(m), d(m);
	for (int i = 0; i < m; i++){
		l[i] = nxt() - 1;
		r[i] = nxt();
		d[i] = nxt();
	}

	Tree tr1(m);
	for (int i = 0; i < k; i++){
		int x = nxt() - 1, y = nxt();
		tr1.add(x, y, 1);
	}

	Tree tree(a);
	for (int i = 0; i < m; i++){
		tree.add(l[i], r[i], tr1.get(i, i + 1) * d[i]);
	}

	for (int i = 0; i < n; i++)
		printf("%I64d ", tree.get(i, i + 1));
	puts("");
	
	return 0;
}