#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using ll = long long;

struct node
{
	public:
		node *l, *r;
		int s; int h;
		ll a, d; // d is key -- greed max a
		ll za, zd; // modifier for a, modifier for d
		ll ma, mb; // max(a);
		node(ll _a=0, ll _d=0): a(_a), d(_d)
		{
			l=r=nullptr;
			s=h=1;
			za=zd=0;
			ma=a,mb=a+d;
		}
};

const int pool_sz = 1e5;
int pool_ctr;
node *pool;
node *nn()
{
	if(!pool_ctr) pool=new node[pool_ctr=pool_sz];
	return pool+--pool_ctr;
}
node *nn(ll a, ll d) {node *n=nn(); *n=node(a,d); return n;}

int gs(node *n) {return n?n->s:0;}
int gh(node *n) {return n?n->h:0;}
ll gma(node *n) {return n?n->ma:0;}
ll gmb(node *n) {return n?n->mb:0;}

void upd(node *n)
{
	n->s=gs(n->l)+gs(n->r)+1;
	n->h=std::max(gh(n->l), gh(n->r))+1;
	n->ma=std::max({gma(n->l), gma(n->r), n->a});
	n->mb=std::max({gmb(n->l), gmb(n->r), n->a+n->d});
}

void upda(node *n, ll v) {n->za+=v, n->a+=v, n->ma+=v, n->mb+=v;}
void updd(node *n, ll v) {n->zd+=v, n->d+=v, n->mb+=v;}

void down(node *n)
{
	if(n->za)
	{
		if(n->l) upda(n->l, n->za);
		if(n->r) upda(n->r, n->za);
		n->za=0;
	}
	if(n->zd)
	{
		if(n->l) updd(n->l, n->zd);
		if(n->r) updd(n->r, n->zd);
		n->zd=0;
	}
}

node* rotl(node *n)
{
	down(n);
	node *o=n->r; assert(o);
	down(o);
	n->r=o->l, o->l=n;
	return upd(n), upd(o), o;
}

node* rotr(node *n)
{
	down(n);
	node *o=n->l; assert(o);
	down(o);
	n->l=o->r, o->r=n;
	return upd(n), upd(o), o;
}

node* bal(node *n)
{
	int d=gh(n->l)-gh(n->r);
	if(d > 1)
		if(gh(n->l->l)+1 == n->l->h)
			return rotr(n);
		else
			return n->l=rotl(n->l), rotr(n);
	else if(d < -1)
		if(gh(n->r->r)+1 == n->r->h)
			return rotl(n);
		else
			return n->r=rotr(n->r), rotl(n);
	return n; // should bal upd?
}

node* merge(node *l, node *r)
{
	if(!l) return r;
	if(!r) return l;
	if(l->h < r->h)
		return down(r), r->l=merge(l, r->l), upd(r), bal(r);
	else
		return down(l), l->r=merge(l->r, r), upd(l), bal(l);
}

node* mwr(node *l, node *m, node *r)
{
	int d=gh(l)-gh(r);
	if(d>1)
		return down(l), l->r=mwr(l->r, m, r), upd(l), bal(l);
	else if(d<-1)
		return down(r), r->l=mwr(l, m, r->l), upd(r), bal(r);
	else
		return m->l=l, m->r=r, upd(m), m; // bal unnecessary
}

struct cut
{
	public:
		node *l, *r;
};

cut split(node *n, int k) // split by size
{
	if(!k) return {nullptr, n};
	assert(n);
	if(k==n->s) return {n, nullptr};
	down(n);
	if(k <= gs(n->l))
	{
		cut x=split(n->l, k);
		return {x.l, mwr(x.r, n, n->r)};
	}
	else
	{
		cut x=split(n->r, k-gs(n->l)-1);
		return {mwr(n->l, n, x.l), x.r};
	}
}

int upper_bound(node* n, ll v) // count how many strictly less than d
{
	if(!n) return 0;
	down(n);
	if(v<n->d)
		return upper_bound(n->l, v);
	else
		return gs(n->l)+1+upper_bound(n->r, v);
}

node *get(node *n, int k)
{
	down(n);
	if(k<gs(n->l))
		return n->l?get(n->l, k):n->l;
	else if(k==gs(n->l))
		return n;
	else
		return get(n->r, k-gs(n->l)-1);
}

void pout(node *n)
{
	if(!n) return;
	down(n);
	pout(n->l);
	printf("%2d: c:[%2d, %2d], s:%2d, h:%2d, a:%3lld, d:%3lld, ma:%3lld, mb:%3lld, za:%3lld, zd:%3lld\n", pool_sz-(n-pool), n->l?pool_sz-(n->l-pool):-1, n->r?pool_sz-(n->r-pool):-1, n->s, n->h, n->a, n->d, n->ma, n->mb, n->za, n->zd);
	pout(n->r);
}

void assure(node *n)
{
	if(!n) return;
	down(n);
	assure(n->l);
	assure(n->r);
	if(n->l) assert(n->l->d <= n->d);
	if(n->r) assert(n->d <= n->r->d);
	upd(n);
}

int N, M;
ll C;

struct Evt
{
	public:
		ll t; int v;
		bool operator < (const Evt& o) const {return t < o.t;}
};
std::vector<Evt> evt;

int main()
{
	scanf("%d%d%lld", &N, &M, &C);
	for(int i=0;i<N;++i)
	{
		ll l,r;
		scanf("%lld%lld", &l, &r);
		evt.push_back({l,1});
		evt.push_back({r,1});
	}

	for(int i=0;i<M;++i)
	{
		ll l,r;
		scanf("%lld%lld", &l, &r);
		evt.push_back({l,2});
		evt.push_back({r,2});
	}
	std::sort(evt.begin(), evt.end());

	node *n=nn(0,0);
	int v=0;
	ll p=0, t;
	for(int i=0,j=0;i<evt.size();i=j)
	{
		if(i<evt.size()) t=evt[i].t-p, p=evt[i].t;
		if(v==1)
			upda(n, t), updd(n, -t); // a += t, (b-a) -= t
		else if(v==2)
			updd(n, t); // (b-a) += t
		else if(v==3)
		{
			cut s1=split(n, upper_bound(n, -C));
			cut s2=split(s1.r, upper_bound(s1.r, C));
			node *a=s1.l, *b=s2.l, *c=s2.r;

			//wait and use dual
			if(a)
				b=merge(nn(a->mb+C, -C), b);
			if(c)
				b=merge(b, nn(c->ma, C));

			//greed
			if(a) upda(a, t);
			if(b) upda(b, 2*t);
			if(c) upda(c, t);

			n=merge(a, merge(b,c));
		}
		//printf("ON STEP %d (%d for len %lld):\n", i, v, t);
		//pout(n);
		for(;j<evt.size() && evt[i].t == evt[j].t;++j)
			v^=evt[j].v;
	}
	
	printf("%lld\n", n->ma);
	return 0;
}