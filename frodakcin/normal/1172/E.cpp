#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 4e5 + 100;
const int MM = 4e5 + 100;

vector<int> a[MN];
int v[MN];
int N, M;
ll qdiff[MM];
int p[MN];

//Start Splay
struct node
{
public:
	node * p;
	node * c[2];
	
	ll sz, szd;
	ll osz;
	void upd(ll x) {sz += x, szd += x;}
};
node X[MN];
int gid(node * n) {return n?n-X:-1;}
bool Srt(node * n) {return !n->p || (n->p->c[0] != n && n->p->c[1] != n);}
bool son(node * n) {return n->p->c[1] == n;}
ll gsz(node * n) {return n?n->sz:0LL;}
ll sqr(ll x) {return x*x;}
void setc(node * n, node * c, bool w)
{
	n->c[w] = c;
	if(c) c->p = n;
}
void rotup(node * n)
{
	bool c = son(n);
	node * o = n->p;
	setc(o, n->c[!c], c);
	if(Srt(o)) n->p = o->p; else setc(o->p, n, son(o));
	setc(n, o, !c);
}
void down(node * n)
{
	if(n->szd)
	{
		for(int c : {0,1}) if(n->c[c]) n->c[c]->upd(n->szd);
		n->szd = 0LL;
	}
}
void predwn(node * n) {if(!Srt(n)) predwn(n->p); down(n);}
void splay(node * n, node * z = nullptr)
{
	predwn(n);
	for(;!Srt(n) && n->p != z;)
		if(Srt(n->p) || n->p->p == z)
			rotup(n);
		else
			if(son(n)==son(n->p))
				rotup(n->p), rotup(n);
			else
				rotup(n), rotup(n);
}
node * first(node * n)
{
	down(n);
	if(n->c[0]) return first(n->c[0]);
	else return n;
}
ll tsz(node * n)
{
	if(!n->c[1]) return n->osz;
	splay(first(n->c[1]), n);
	return n->osz + sqr(gsz(n->c[1]));
}
void inorder(node * n)
{
	if(!n) return;
	inorder(n->c[0]);
	printf("%d c:[%d %d] v:(%lld(%lld) %lld) p: %d\n", gid(n), gid(n->c[0]), gid(n->c[1]), n->sz, n->szd, n->osz, gid(n->p));
	inorder(n->c[1]);
}
//End Splay
ll dfs(int n)
{
	X[n].sz = 1LL, X[n].osz = 0LL;
	for(int x : a[n])
		if(p[n] != x)
		{
			p[x] = n;
			ll t = dfs(x);
			X[n].sz += t, X[n].osz += t*t;
		}
	X[n].p = n?X+p[n]:nullptr;
	return X[n].sz;
}
//Start LCT
void access(node * n)
{
	splay(n);
	n->osz = tsz(n);
	setc(n, nullptr, 1);
	node * x = first(n);
	splay(x);
	for(;x->p;)
	{
		splay(x->p);
		x->p->osz = tsz(x->p)-sqr(gsz(x));
		x->p->c[1] = x;
		splay(x = first(x->p));
	}
	splay(n);
}
ll link(node * n, node * p)
{
	access(n); //assert(!n->c[0]);
	access(p); //printf("\tL0\n"); inorder(p); inorder(n);
	node * top = first(p);
	splay(top); ll tmp = tsz(top) + tsz(n); /*printf("\tL2\n"); inorder(top);*/ splay(p);
	n->p = p;
	p->sz += n->sz, p->osz += sqr(gsz(n));
	if(p->c[0]) p->c[0]->upd(n->sz);
	//printf("\tL1\n"); inorder(p); inorder(n);
	splay(top);
	//printf("\tL3: %lld\n", tsz(top)); inorder(top);
	return tsz(top) - tmp;
}
ll cut(node * n, node * p)
{
	access(n);
	access(p); //assert(n->p == p && !n->c[0] && !n->c[1]);
	//printf("\tC0\n"); inorder(p); inorder(n);
	node * top = first(p);
	splay(top); ll tmp = tsz(top); splay(p);
	p->osz -= sqr(gsz(n)); n->p = nullptr; p->sz -= n->sz;
	if(p->c[0]) p->c[0]->upd(-n->sz);
	//printf("\tC1\n"); inorder(p); inorder(n);
	splay(top);
	return tsz(top) + tsz(n) - tmp;
}
//End LCT
struct Q
{
public:
	int loc;
	int n;
	bool type; // 0 = join_cluster, 1 = leave_cluster
};
void process(vector<Q>& qs)
{
	//ll val = tl(N)*N, tmp;
	for(Q& q : qs)
	{
		//tmp = qdiff[q.loc];
		if(q.type)
			qdiff[q.loc] -= cut(X+q.n, X+p[q.n]);
		else
			qdiff[q.loc] -= link(X+q.n, X+p[q.n]);
		//printf(" %lld\n", val -= qdiff[q.loc]-tmp);
	}
}
vector<Q> colq[MN];

ll ans;
int main(void)
{
	a[0].push_back(1), a[1].push_back(0);
	scanf("%d%d", &N, &M);
	for(int i = 1;i <= N;i++)
		scanf("%d", v+i), colq[v[i]].push_back({0, i, 1});
	for(int i = 0, u, v;i < N-1;i++)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs(0);
	for(int i = 1, x, c;i <= M;i++)
		scanf("%d%d", &x, &c), colq[v[x]].push_back({i, x, 0}), colq[v[x]=c].push_back({i, x, 1});
	for(int i = 1;i <= N;i++)
		colq[v[i]].push_back({M+1, i, 0});
	for(int i = 1;i <= N;i++)
		process(colq[i]);
	for(int i = 0;i	<= M;i++)
		printf("%lld\n", ans += qdiff[i]);
	return 0;
}