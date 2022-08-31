#include<bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using ll = long long;

namespace lct {

struct node {
	node* p = nullptr;
	node* c[2] = {nullptr, nullptr};

	// computed
	ll pathSz = 0;
	ll totSz = 0;
	ll totVal = 0;

	// inputs
	ll oTotSz = 0;
	ll oTotVal = 0;

	int aVal;

	// isroot
	inline bool r() { return p == nullptr || !(this == p->c[0] || this == p->c[1]); }
	// direction
	inline bool d() { assert(!r()); return this == p->c[1]; }

	inline void update() {
		pathSz = 1 + (c[0] ? c[0]->pathSz : 0) + (c[1] ? c[1]->pathSz : 0);
		totSz = 1 + oTotSz + (c[0] ? c[0]->totSz : 0) + (c[1] ? c[1]->totSz : 0);
		totVal = oTotVal;
		totVal += ((c[0] ? c[0]->pathSz : 0) + 1) * ((c[1] ? c[1]->totSz : 0) + 1 + oTotSz);
		totVal += (c[0] ? c[0]->totVal : 0);
		totVal += (c[1] ? c[1]->totVal : 0);
	}

	void propogate() {
		// shouldn't need to do anything
	}

	// precondition: parent and current are propogated
	void rot() {
		assert(!r());

		int x = d();
		node* pa = p;
		node* ch = c[!x];

		assert((!ch) || ch->p == this);

		if(!pa->r()) pa->p->c[pa->d()] = this;
		this->p = pa->p;

		pa->c[x] = ch;
		if(ch) ch->p = pa;

		this->c[!x] = pa;
		pa->p = this;

		pa->update();
		update();
	}

	// postcondition: always propogated
	void splay() {
		if(r()) {
			propogate();
			update();
			return;
		}

		while(!r()) {
			if(!p->r()) {
				node* gp = p->p;
				node* pa = p;
				gp->propogate();
				pa->propogate();
				propogate();
				if(d() == p->d()) {
					pa->rot();
					assert(p == pa);
				} else {
					rot();
					assert(p == gp);
				}
				rot();
			} else {
				p->propogate();
				propogate();
				rot();
				assert(r());
			}
		}
		update();
	}

	// attach on right side
	// precondition: propogated
	void make_child(node* n) {
		assert(r());

		if(c[1]) {
			node* v = c[1];
			c[1] = nullptr;
			assert(v->r());

			oTotSz += v->totSz;
			oTotVal += v->totVal;

			update();
		}

		assert(!c[1]);

		if(n) {

			assert(n->r());
			assert(n->p == this);

			oTotSz -= n->totSz;
			oTotVal -= n->totVal;

			c[1] = n;
			assert(c[1]->p == this);

			update();
		}
	}

	// postcondition: propogated
	void expose() {
		splay();
		make_child(nullptr);
		while(p) {
			assert(r());
			p->splay();
			p->make_child(this);
			rot();
			update();
			assert(r());
		}
		assert(!p);
		assert(!c[1]);
	}

	void link(node* pa) {
		assert(p == nullptr);
		assert(pa->p == nullptr);
		pa->oTotSz += totSz;
		pa->oTotVal += totVal;
		pa->update();
		p = pa;
	}

	void cut() {
		assert(r());
		assert(p->p == nullptr);
		p->make_child(nullptr);
		p->oTotSz -= totSz;
		p->oTotVal -= totVal;
		p->update();

		p = nullptr;
	}
};

} // namespace lct

const int MAXN = 3.1e5;
int N;
int A[MAXN];
int invA[MAXN];
int prvBigger[MAXN];
int nxtBigger[MAXN];
using lct::node;
node nodes[MAXN];

const int S = 1 << 18;
int seg[2*S];

ll ans[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		invA[A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		seg[S+i] = A[i];
	}
	for (int i = S-1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);

	std::y_combinator([&](auto self, int l, int r) -> node* {
		assert(l <= r);
		if (l == r) return nullptr;
		int maxVal = 0;
		for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
			if (a & 1) maxVal = max(maxVal, seg[a++]);
			if (b & 1) maxVal = max(maxVal, seg[--b]);
		}
		int m = invA[maxVal];
		node* res = &nodes[m];
		res->aVal = A[m];
		res->update();
		node* c0 = self(l, m);
		if (c0) c0->link(res);
		node* c1 = self(m+1, r);
		if (c1) c1->link(res);
		return res;
	})(1, N+1);

	set<int> vals;
	for (int i = 1; i <= N; i++) {
		vals.insert(i);
	}

	auto printPath = std::y_combinator([&](auto self, node* cur) -> void {
		if (!cur) return;
		self(cur->c[0]);
		cerr << cur->aVal << ' ';
		self(cur->c[1]);
	});
	for (int t = N; t >= 1; t--) {
		int i = invA[t];
		nodes[i].expose();
		//cerr << t << ' ' << nodes[i].totVal << '\n';
		//cerr << "path "; printPath(&nodes[i]); cerr << '\n';
		//if (nodes[i].c[0]) cerr << nodes[i].c[0]->aVal << '\n';
		assert(nodes[i].c[0] == nullptr);
		ans[t] = nodes[i].totVal;
		auto it = vals.erase(vals.find(i));
		node* r = nullptr;
		if (it != vals.end()) {
			r = &nodes[*it];
			//cerr << "righ " << *it << ' ' << r->aVal << '\n';
			r->expose();
			nodes[i].expose();
			r->splay();
			assert(r->p == &nodes[i]);
			r->cut();
		}
		node* l = nullptr;
		if (it != vals.begin()) {
			--it;
			l = &nodes[*it];
			//cerr << "left " << *it << ' ' << l->aVal << '\n';
			l->expose();
			nodes[i].expose();
			l->splay();
			assert(l->p == &nodes[i]);
			l->cut();
		}

		if (l == nullptr || r == nullptr) continue;

		assert(l->p == nullptr);
		assert(r->p == nullptr);
		//cerr << "l "; printPath(l); cerr << '\n';
		//cerr << "r "; printPath(r); cerr << '\n';

		if (l->pathSz >= r->pathSz) {
			swap(l, r);
		}
		// size from l to r
		std::y_combinator([&](auto self, node* cur) -> void {
			if (!cur) return;
			node* a = cur->c[0], *b = cur->c[1];
			if (a) a->p = nullptr;
			if (b) b->p = nullptr;
			cur->c[0] = cur->c[1] = nullptr;
			cur->update();

			self(a);

			node* ins = r;
			while (true) {
				assert(cur->aVal != ins->aVal);
				int d = (cur->aVal < ins->aVal);
				if (ins->c[d] == nullptr) {
					//cerr << "ins " << cur->aVal << ' ' << ins->aVal << ' ' << d << '\n';
					ins->c[d] = cur;
					cur->p = ins;
					break;
				} else {
					ins = ins->c[d];
				}
			}
			cur->splay();
			r = cur;

			self(b);
		})(l);
	}

	for (int t = 1; t <= N; t++) {
		cout << ans[t] << '\n';
	}

	return 0;
}