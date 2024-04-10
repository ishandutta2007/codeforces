#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using ll = long long;

const int MN = 2e5 + 100;
int N;

struct node
{
public:
	node * l, * r;
	ll v, z;
	node() : l(nullptr), r(nullptr), v(0LL), z(0LL) {};
};
const int pool_sz = 50000;
node * pool;
int pool_ctr;
node * nn(node * p = nullptr)
{
	if(!pool_ctr) pool = new node[pool_ctr = pool_sz];
	if(p) pool[pool_ctr-1] = *p;
	return pool+--pool_ctr;
}

void upd(node *&n, int l, int r, int ql, int qr, ll q)
{
	n = nn(n);
	n->v += (qr-ql)*q;
	if(ql == l&&r == qr) n->z += q;
	else
	{
		int m = l + (r-l)/2;
		if(ql < m) upd(n->l, l, m, ql, std::min(qr, m), q);
		if(m < qr) upd(n->r, m, r, std::max(m, ql), qr, q);
	}
}
ll qry(node *n , int l, int r, int ql, int qr)
{
	if(!n) return 0LL;
	ll f = 0LL;
	if(ql == l&&r == qr) return n->v;
	else
	{
		f = n->z*(qr-ql);
		int m = l + (r-l)/2;
		if(ql < m) f += qry(n->l, l, m, ql, std::min(qr, m));
		if(m < qr) f += qry(n->r, m, r, std::max(m, ql), qr);
		return f;
	}
}
	

struct S
{
public:
	node * n;
	int t;
};
std::vector<S> m[MN];
int lb(int k, int v)
{
	int l = 0, r = m[k].size();
	for(;r-l>1;)
	{
		int x = l+(r-l)/2;
		if(m[k][x].t < v) l = x;
		else r = x;
	}
	return r;
}

struct R
{
public:
	int m;
	mutable int t;//t.. inclusive has mex m
	R(int m = -1, int t = 0) : m(m), t(t) {}
	bool operator < (R o) const {return m < o.m;}//equiv to x > o.x
};
std::set<R> r;
void fix(std::set<R>::iterator it, int i, bool over = 0)
{
	int v = it->m;
	S x = m[v].back();
	if(over && x.t == i) return;
	if(!over) assert(x.t != i);
	node * n = x.n;
	upd(n, 0, N, std::next(it)->t, it->t, i-x.t);
	//printf("outinf (%d %d) upd(%d %d %d %d %d)  fullres: %lld\n", it->m, i, 0, N, std::next(it)->t, it->t, i-x.t, qry(n, 0, N, 0, N));
	m[v].push_back(S{n, i});
}
void fix(int v, int i, bool over = 0)
{
	if(over && m[v].back().t == i) return;
	if(!over) assert(m[v].back().t < i);
	m[v].push_back(S{m[v].back().n, i});
}
int p[MN];

ll getper(int k, int i, int l, int r)
{
	if(i==m[k].size())
	{
		std::set<R>::iterator it = ::r.lower_bound({k,0});
		return it->m == k ? std::max(0LL, static_cast<ll>(std::min(r, it->t) - std::max(l-1, std::next(it)->t))) : 0LL;
	}
	return (qry(m[k][i].n, 0, N, l-1, r)-qry(m[k][i-1].n, 0, N, l-1, r))/(m[k][i].t-m[k][i-1].t);
}
ll P;
void convert(int i, int *a, int *l, int *r, int *k)
{
	*a=(*a+P)%(N+1);
	*l=(*l+P)%i+1;
	*r=(*r+P)%i+1;
	if(*r<*l) *l^=*r^=*l^=*r;
	*k=(*k+P)%(N+1);
}
void ans_q(int i)
{
	int a, l, r, k;
	scanf("%d%d%d%d", &a, &l, &r, &k);
	convert(i, &a, &l, &r, &k);
	p[a] = i;
	std::set<R>::iterator it;

	it = ::r.lower_bound({a});
	if(it->m == a) fix(it, i);
	for(int j = a, k = i;it->m==j;++j)
	{
		k = std::min(k, p[j]);
		if(k >= it->t) k = it->t, it = ::r.erase(it);
		else ++it;
		if(k <= it->t) break;
		if(it->m == j+1) fix(it, i), it->t = k;
		else fix(j+1, i), it = ::r.insert(R{j+1, k}).first;
	}

	if(a)
		if((it=::r.begin())->m) fix(0, i), ::r.insert(R{0, i});
		else fix(it, i), ++it->t;
	else
		if((it=::r.begin())->m==1) fix(it, i, 1), ++it->t;
		else if(it->m>1) fix(1, i, 1), ::r.insert(R{1, i});

	//printf("setc["); for(R x : ::r) printf("(%d, %d) ", x.m, x.t); printf("]\n");

	P = 0LL;
	int u, v;
	u = lb(k, l);
	v = lb(k, r+1)-1;
	assert(v+1 >= u);
	if(u > v) return printf("%lld\n", P=getper(k,u,l,r)*(u-v)), void();
	if(u < v) P = qry(m[k][v].n, 0, N, l-1, r)-qry(m[k][u].n, 0, N, l-1, r);
	if(l < m[k][u].t) P += getper(k, u, l, r)*(m[k][u].t-l);
	P += getper(k, v+1, l, r)*(r-m[k][v].t+1);
	printf("%lld\n", P);
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i <= N;i++)
		m[i].assign(1, S{nullptr, 0});
	r.clear();
	r.insert(R{MN, 0});
	for(int i = 1;i <= N;i++)
		ans_q(i);
	return 0;
}


/*

5
0 1 1 1
1 1 2 0
0 1 3 1
1 1 4 2
2 1 5 3

5
2 1 1 2
2 1 2 1
0 1 3 0
0 2 2 3
0 3 4 0

*/