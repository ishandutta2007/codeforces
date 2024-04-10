#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 300010, P = 1000000009, SQRT5 = 383008016;

int n, m;

int a[N];
int pw[N], ipw[N], geo[N], igeo[N];

int mpow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = ret * (ll)x % P;
		x = x * (ll)x % P;
		k >>= 1;
	} 
	return ret;
}

struct Node {
	int l, r, sum, lazy, ilazy;
	Node *ls, *rs;
	
	int get() const {
		return (sum + lazy * (ll)geo[r - l + 1] % P + ilazy * (ll)igeo[r - l + 1] % P) % P;
	}
	
	void pd() {
		sum = get();
		if (lazy) {
			if ((ls->lazy += lazy) >= P)
				ls->lazy -= P;
			rs->lazy = (rs->lazy + lazy * (ll)pw[ls->r - ls->l + 1]) % P; 
			lazy = 0;
		}
		if (ilazy) {
			if ((ls->ilazy += ilazy) >= P)
				ls->ilazy -= P;
			rs->ilazy = (rs->ilazy + ilazy * (ll)ipw[ls->r - ls->l + 1]) % P; 
			ilazy = 0;
		}
	}
	
	int q(int l, int r) {
		if (this->l == l && this->r == r)
			return get();
		pd();
		if (r <= ls->r)
			return ls->q(l, r);
		if (l >= rs->l)
			return rs->q(l, r);
		return (ls->q(l, ls->r) + rs->q(rs->l, r)) % P;
	}
	
	void ch(int l, int r, int delt) {
		if (this->l == l && this->r == r) {
			if ((lazy += pw[delt]) >= P)
				lazy -= P;
			if ((ilazy -= ipw[delt]) < 0)
				ilazy += P; 
			return;
		}
		pd();
		if (r <= ls->r)
			ls->ch(l, r, delt);
		else if (l >= rs->l)
			rs->ch(l, r, delt);
		else {
			ls->ch(l, ls->r, delt);
			rs->ch(rs->l, r, delt + ls->r - l + 1);
		}
		if ((sum = ls->get() + rs->get()) >= P)
			sum -= P;
	}
};

Node* seg;

Node* build(int l, int r);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	pw[0] = ipw[0] = 1;
	pw[1] = (SQRT5 + 1) * (ll)mpow(2, P - 2) % P;
	ipw[1] = (P + 1 - SQRT5) * (ll)mpow(2, P - 2) % P;
	int inv = mpow(SQRT5, P - 2);
	for (int i = 2; i <= n; ++i) {
		pw[i] = pw[i - 1] * (ll) pw[1] % P;
		ipw[i] = ipw[i - 1] * (ll) ipw[1] % P;
	} 
	for (int i = 1; i <= n; ++i) {
		geo[i] = (geo[i - 1] + pw[i]) % P;
		igeo[i] = (igeo[i - 1] + ipw[i]) % P;
	}
	seg = build(1, n);
	while (m--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1)
			{
			seg->ch(l, r, 0);
		}
		else
			printf("%d\n", int(seg->q(l, r) * (ll)inv % P));
	}

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}

Node* build(int l, int r) {
	static Node pool[N * 2];
	static Node* ptop = pool;
	Node* p = ptop;
	++ptop;
	p->l = l;
	p->r = r;
	if (l == r) {
		p->lazy = a[l];
		p->ilazy = (P - a[l]) % P;
		return p;
	}
	int mid = (l + r) >> 1;
	p->ls = build(l, mid);
	p->rs = build(mid + 1, r);
	if ((p->sum = p->ls->get() + p->rs->get()) >= P)
		p->sum -= P;
	return p;
}