#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

#define tget(n,p) ((n)?(n)->p:0)

using ll = long long;

const int MN = 2e5+10;

namespace AVL
{
	const int MN = 2e7;
	struct node
	{
		public:
			node *c[2];
			int v, s;
			int h;
			node(int _v=0):v(v)
			{
				s=1,h=0;
				c[0]=c[1]=nullptr;
			}
	} pool[MN];
	int X;
	node *nn(int v)
	{
		assert(X<MN);
		node *n=pool+X++;
		n->v=v;
		return n;
	}
	void upd(node *n)
	{
		n->s=tget(n->c[0], s)+tget(n->c[1], s)+1;
		n->h=std::max(tget(n->c[0], h), tget(n->c[1], h))+1;
	}
	node *rot(node *n, bool c)
	{
		node *o=n->c[c];
		n->c[c]=o->c[!c];
		o->c[!c]=n;
		return upd(n), upd(o), o;
	}
	node *bal(node *n)
	{
		int b = tget(n->c[0],h)-tget(n->c[1],h);
		if(b>1)
			if(tget(n->c[0]->c[0],h)+1==n->c[0]->h) return rot(n, 0);
			else return n->c[0]=rot(n->c[0], 1), rot(n, 0);
		else if(b<-1)
			if(tget(n->c[1]->c[1],h)+1==n->c[1]->h) return rot(n, 1);
			else return n->c[1]=rot(n->c[1], 0), rot(n, 1);
		else return n;
	}
	node *ins(node *n, int v)
	{
		if(!n) return nn(v);
		if(v<n->v) return n->c[0]=ins(n->c[0], v), upd(n), bal(n);
		else if(n->v<v) return n->c[1]=ins(n->c[1], v), upd(n), bal(n);
		assert(0); //can't have duplicates in a permutation
	}
	int count(node *n, int v)//number <= v
	{
		if(!n) return 0;
		if(v<n->v) return count(n->c[0], v);
		else return tget(n->c[0],s)+1+count(n->c[1], v);
	}
	node *merge(node *l, node *r)
	{
		if(!r) return l;
		if(!l) return r;
		if(l->h<r->h) return r->c[0]=merge(l,r->c[0]), upd(r), r;
		else return l->c[1]=merge(l->c[1],r), upd(l), l;
	}
	node *mwr(node *l, node *m, node *r)//m may be replaced with value
	{
		int b=tget(l,h)-tget(r,h);
		if(b>1) return l->c[1]=mwr(l->c[1],m,r), upd(l), l;
		else if(b<-1) return r->c[0]=mwr(l,m,r->c[0]), upd(r), r;
		else return m->c[0]=l, m->c[1]=r, upd(m), m;
	}
	struct cut
	{
		public:
			node *l, *r;
	};
	cut split(node *n, int k)
	{
		if(k==0) return {nullptr,n};
		else if(k==n->s) return {n,nullptr};//n must exist
		cut x;
		if(k<=tget(n->c[0],s)) return x=split(n->c[0],k), cut{x.l, mwr(x.r, n, n->c[1])};
		else return x=split(n->c[1],k-tget(n->c[0],s)-1), cut{mwr(n->c[0], n, x.l), x.r};
	}
	node *rem(node *n, int v)
	{
		int k=count(n, v);
		assert(k);
		auto x = split(n, k);
		x.l = split(x.l, x.l->s-1).l;
		return merge(x.l, x.r);
	}
}

int N, Q, p[MN], w[MN], X;
ll ans;

struct TNode
{
	public:
		TNode *c[2], *p;
		AVL::node *set[2];
		int m;
		ll inv, tot;
} a[MN];

void build(TNode *n, int l, int r)
{
	int b=MN, m=-1;
	for(int i=l;i<r;++i)
		if(ckmin(b, w[i]))
			m=i;
	n->m=m;
	if(l<m)
	{
		build(n->c[0]=a+(++X), l, m);
		n->c[0]->p=n;
	}
	if(m+1<r)
	{
		build(n->c[1]=a+(++X), m+1, r);
		n->c[1]->p=n;
	}

	n->tot=(ll)(r-m)*(m-l+1);
	for(int i=m+1;i<=r;++i)
		n->set[1]=AVL::ins(n->set[1], p[i]);
	for(int i=l;i<=m;++i)
		n->inv += AVL::count(n->set[1], p[i]), n->set[0]=AVL::ins(n->set[0], p[i]);
	ans += std::min(n->inv, n->tot-n->inv);
}

template<bool add>
void mod(TNode *n, int x, int l, int r)
{
	if(!n) return;
	int m=n->m;
	if(m<x) mod<add>(n->c[1], x, m+1, r);
	else mod<add>(n->c[0], x, l, m);
	ans -= std::min(n->inv, n->tot-n->inv);
	if(add)
		if(m<x) n->inv+=tget(n->set[0],s)-AVL::count(n->set[0], p[x]), n->set[1]=AVL::ins(n->set[1], p[x]);
		else n->inv+=AVL::count(n->set[1], p[x]), n->set[0]=AVL::ins(n->set[0], p[x]);
	else
		if(m<x) n->inv-=tget(n->set[0],s)-AVL::count(n->set[0], p[x]), n->set[1]=AVL::rem(n->set[1], p[x]);
		else n->inv-=AVL::count(n->set[1], p[x]), n->set[0]=AVL::rem(n->set[0], p[x]);
	ans += std::min(n->inv, n->tot-n->inv);
	//printf("HM %d %d %lld %lld\n", l, r, n->inv, n->tot);
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", p+i);
	for(int i=0;i<N-1;++i)
		scanf("%d", w+i);
	build(a, 0, N-1);
	scanf("%d", &Q);
	for(int i=0,x,y;i<Q;++i)
	{
		scanf("%d%d", &x, &y);
		--x, --y;
		if(x!=y)
		{
			mod<0>(a, x, 0, N-1);
			mod<0>(a, y, 0, N-1);
			std::swap(p[x], p[y]);
			mod<1>(a, x, 0, N-1);
			mod<1>(a, y, 0, N-1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}