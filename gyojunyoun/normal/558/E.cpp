#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
using namespace std;
typedef pair<int, int> pii;

struct NOD {
	NOD(int sum = 0, int cnt = 0, int dt = 0)
		: p(0), l(0), r(0), sum(sum), cnt(cnt), dt(dt) {}
	NOD *p, *l, *r;
	int sum, cnt, dt;

	void upd() {
		sum = cnt;
		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
	void rot() {
		NOD *c = p, *g = p->p;
		if(this == p->l) {
			p->l = r;
			if(r) r->p = p;
			r = p;
		} else {
			p->r = l;
			if(l) l->p = p;
			l = p;
		}
		p->p = this; p = g;
		if(g) (g->l == c ? g->l : g->r) = this;
		c->upd(); upd();
	}
	void dfs(vector<NOD*> &V) {
		if(l) l->dfs(V);
		V.eb(this);
		if(r) r->dfs(V);
	}
};

struct SPT {
	NOD *rt;

	void init(int N, char *A) {
		NOD *x = rt = new NOD(N+2, 1, -1);
		for(int i = 1; i <= N; i++) {
			x->r = new NOD(N-i+2, 1, A[i]-'a');
			x->r->p = x;
			x = x->r;
		}
		x->r = new NOD(1, 1, -1);
		x->r->p = x;
	}

	NOD* splay(NOD *x) {
		for(NOD *g; x->p;) {
			if(!(g = x->p->p)) {
				x->rot();
				break;
			}
			((g->l == x->p) == (x->p->l == x) ? x->p : x)->rot();
			x->rot();
		}
		return (rt = x);
	}

	NOD* findBef(int K) {
		NOD *x = rt, *ret = rt;
		for(; x;) {
			if(x->l) {
				if(K <= x->l->sum + x->cnt) {
					x = x->l;
					continue;
				}
				K -= x->l->sum;
			}
			if(K <= x->cnt) break;
			K -= x->cnt;
			ret = x;
			x = x->r;
		}
		return splay(ret);
	}
	NOD* findAft(int K) {
		NOD *x = rt, *ret = rt;
		for(; x;) {
			if(x->l) {
				if(K <= x->l->sum) {
					ret = x;
					x = x->l;
					continue;
				}
				K -= x->l->sum;
			}
			if(K <= 0) {
				ret = x;
				break;
			}
			K -= x->cnt;
			x = x->r;
		}
		return splay(ret);
	}

	NOD* interval(int s, int e) {
		NOD *x = findBef(s);
		rt = x->r;
		rt->p = 0;
		findAft(e - x->cnt - (x->l ? x->l->sum : 0));
		rt->p = x;
		x->r = rt;
		rt = x;
		return rt->r->l;
	}
} spt;

void f(int t, int s, int e) {
	NOD *x = spt.interval(s, e);
	vector<NOD*> PV;
	x->dfs(PV); x = x->p;

	vector<pii> V;
	for(auto &v : PV) {
		V.eb(v->dt, v->cnt);
		delete v;
	}

	vector<pii> TV;
	int l = s - (x->p->sum - x->sum) - 1;
	int i = 0, n = sz(V);
	for(; l;) {
		if(V[i].second <= l) {
			TV.eb(V[i]);
			l -= V[i].second;
			i++;
			continue;
		}
		TV.eb(V[i].first, l);
		V[i].second -= l;
		break;
	}

	vector<int> CV(26, 0);
	l = e-s+1;
	for(; l;) {
		if(V[i].second <= l) {
			CV[V[i].first] += V[i].second;
			l -= V[i].second;
			i++;
			continue;
		}
		CV[V[i].first] += l;
		V[i].second -= l;
		break;
	}

	if(t) {
		for(int k = 0; k < 26; k++)
			if(CV[k]) TV.eb(k, CV[k]);
	} else {
		for(int k = 26; k--;)
			if(CV[k]) TV.eb(k, CV[k]);
	}

	for(; i < n; i++)
		if(V[i].second) TV.eb(V[i]);
	
	x->l = new NOD(0, TV[0].second, TV[0].first);
	x->l->p = x;
	x = x->l;
	for(i = 1, n = sz(TV); i < n; i++) {
		x->r = new NOD(0, TV[i].second, TV[i].first);
		x->r->p = x;
		x = x->r;
	}
	for(i = n; i--; x = x->p) x->upd();
}

const int MAXN = 100055;

char A[MAXN];

int N, Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q >> A+1;
	spt.init(N, A);

	for(int t, a, b; Q--;) {
		cin >> a >> b >> t;
		f(t, a+1, b+1);
	}

	vector<NOD*> V;
	spt.rt->dfs(V);
	for(auto &v : V) if(0 <= v->dt)
		for(int c = v->cnt; c--;) putchar('a' + v->dt);
	putchar('\n');
	return 0;
}