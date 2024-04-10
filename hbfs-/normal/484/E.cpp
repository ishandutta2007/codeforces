#include <bits/stdc++.h>

#define mid ((l+r)>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1

#define N 100050
using namespace std;

struct Afrojack{ int h,_; }A[N];
bool operator <(Afrojack p1, Afrojack p2) { return p1.h > p2.h; }
struct Monster{ int l,r,w,ans; }Q[N];

int n,m,e[N],tmp[N],T;

int ll,rr,v,x;

struct Node{
	int al,ar,siz,ans;
}tr[4*N],ret,id;

Node operator +(Node p1, Node p2) {
	Node ret;
	ret.siz = p1.siz + p2.siz;
	
	ret.ans = max( p1.ans, p2.ans );
	ret.ans = max( ret.ans, p1.ar + p2.al );
	
	ret.ar = p2.ar;
	p2.ar == p2.siz ? ret.ar += p1.ar :0;
	
	ret.al = p1.al;
	p1.al == p1.siz ? ret.al += p2.al :0;
	return ret;
}

inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void init() {
	n = rd();
	for (int _=1;_<=n;_++) A[_].h = rd(), A[_]._ = _;
	m = rd();
	for (int _=1;_<=m;_++)
		Q[_].l = rd(), Q[_].r = rd(), Q[_].w = rd();
	sort(A+1,A+n+1);
	for (int _=1;_<=m;_++) e[_] = _;
}

Node build(int l,int r,int t) {
	return tr[t] = l==r ? (Node){0,0,1,0} : build(ls) + build(rs);
}

void update(int l,int r,int t) {
	if (l == r)
		return tr[t] = v ? (Node){1,1,1,1} : (Node){0,0,1,0}, (void)0;
	x <= mid ? update(ls) : update(rs);
	tr[t] = tr[t<<1] + tr[t<<1^1];
}

void query(int l,int r,int t) {
	if (l >= ll && r <= rr) return ret = ret + tr[t], (void)0;
	if (ll <= mid) query(ls);
	if (rr > mid) query(rs);
}

void solve(int l,int r,int ql,int qr) {
	if (ql > qr) return ;
	if (l == r) {
		for (int _=ql;_<=qr;_++) Q[ e[_] ].ans = A[l].h;
		return ;
	}
	
	while (T<mid)
		x = A[T+1]._, v = 1, update(1,n,1), T++;
	while (T>mid)
		x = A[T]._, v = 0, update(1,n,1), T--;
	
	int L = ql-1, R = qr+1;
	for (int _=ql;_<=qr;_++) {
		ll = Q[ e[_] ].l , rr = Q[ e[_] ].r, ret = id;
		query(1,n,1);
		ret.ans >= Q[ e[_] ].w ? tmp[++L] = e[_] : tmp[ --R ] = e[_];
	}
	for (int _=ql;_<=qr;_++) e[_] = tmp[_];
	
	solve(l,mid,ql,L);
	solve(mid+1,r,R,qr);
}

int main() {
	init();
	build(1,n,1);
	solve(1,n,1,m);
	for (int _=1;_<=m;_++) printf("%d\n",Q[_].ans);
	return 0;
}