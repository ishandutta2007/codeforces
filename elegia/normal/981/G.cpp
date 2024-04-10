#include <cstdio>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <vector>
#include <map>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef map<int, int> MapT;

const int P = 998244353;

struct Node {
	int l, r, d, mul, add;
	Node *ls, *rs;

	int get() const {
		return ((ll)d * mul + add * (ll)(r - l + 1)) % P;
	}

	void pushDown() {
		d = get();
		ls->mul = mul * (ll)ls->mul % P;
		ls->add = (mul * (ll)ls->add + add) % P;
		rs->mul = mul * (ll)rs->mul % P;
		rs->add = (mul * (ll)rs->add + add) % P;
		mul = 1;
		add = 0;
	}

	void update() {
		d = ls->get() + rs->get();
		if (d >= P)
			d -= P;
	}

	void cmul(int l, int r) {
		LOG("MUL %d %d\n", l, r);
		if (this->l == l && this->r == r) {
			mul *= 2;
			if (mul >= P)
				mul -= P;
			add *= 2;
			if (add >= P)
				add -= P;
			return;
		}
		pushDown();
		if (r <= ls->r)
			ls->cmul(l, r);
		else if (l >= rs->l)
			rs->cmul(l, r);
		else {
			ls->cmul(l, ls->r);
			rs->cmul(rs->l, r);
		}
		update();
	}

	void cadd(int l, int r) {
		LOG("ADD %d %d\n", l, r);
		if (this->l == l && this->r == r) {
			if (++add == P)
				add = 0;
			return;
		}
		pushDown();
		if (r <= ls->r)
			ls->cadd(l, r);
		else if (l >= rs->l)
			rs->cadd(l, r);
		else {
			ls->cadd(l, ls->r);
			rs->cadd(rs->l, r);
		}
		update();
	}

	int query(int l, int r) {
		if (this->l == l && this->r == r)
			return get();
		pushDown();
		if (r <= ls->r)
			return ls->query(l, r);
		if (l >= rs->l)
			return rs->query(l, r);
		int ret = ls->query(l, ls->r) + rs->query(rs->l, r);
		if (ret >= P)
			ret -= P;
		return ret;
	}
};

const int N = 200010;

Node* seg;
MapT r2l[N];
int cl[N], cr[N];

Node* build(int l, int r) {
	static Node pool[N * 2];
	static Node* ptop = pool;
	Node* p = ptop;
	++ptop;
	p->l = l;
	p->r = r;
	p->mul = 1;
	if (l == r)
		return p;
	int mid = (l + r) / 2;
	p->ls = build(l, mid);
	p->rs = build(mid + 1, r);
	return p;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	seg = build(1, n);
	while (q--) {
		int opt, l, r;
		scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1) {
			int x;
			scanf("%d", &x);
			int ll = l, rr = r;
			MapT::iterator it = r2l[x].lower_bound(l - 1);
			int cc = 0;
			while (it != r2l[x].end() && max(it->second, l - 1) <= min(it->first, r + 1)) {
				ll = min(ll, it->second);
				rr = max(rr, it->first);
				cl[cc] = (it->second);
				cr[cc] = (it->first);
				++cc;
				r2l[x].erase(it++);
			}
			r2l[x].insert(make_pair(rr, ll));
			if (cc == 0) {
				seg->cadd(l, r);
			} else {
				for (int i = 0; i < cc; ++i)
					if (max(cl[i], l) <= min(cr[i], r))
						seg->cmul(max(cl[i], l), min(cr[i], r));
				for (int i = 1; i < cc; ++i)
					seg->cadd(cr[i - 1] + 1, cl[i] - 1);
				if (cl[0] > l)
					seg->cadd(l, cl[0] - 1);
				if (cr[cc - 1] < r)
					seg->cadd(cr[cc - 1] + 1, r);
			}
		} else
			printf("%d\n", seg->query(l, r));
	}
	return 0;
}