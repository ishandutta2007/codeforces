#include <bits/stdc++.h>

#define p 1000000009
#define N 200050

#define O tr[t]
#define L tr[ tr[t].l ]
#define R tr[ tr[t].r ]

#define x first
#define y second
#define MP make_pair

using namespace std;
typedef pair<int,int> pii;
inline int rd() { int r; scanf("%d",&r); return r; }

pii A[N];
int cnt,n,m,rt,a,b,c,d,k;
void GP(int &a,int &b,pii P) { a = P.x, b = P.y; }
struct Node{ int l,r,siz,key,F,G; }tr[N];
int up(int t) {
	O.siz = L.siz + R.siz + 1;
	if (!O.l && !O.r) { O.F = O.G = 0; return t; }
	if (!O.l) {
		O.F = R.G;
		O.G = R.F + 1;
		return t;
	}
	if (!O.r) {
		O.F = L.G;
		O.G = L.F + 1;
		return t;
	}
	O.F = L.G + R.G;
	O.G = max( L.F+R.G, L.G+R.F ) + 1;
	return t;
}

void build(int l,int r,int &t) {
	if (l > r) return ;
	int now = -1, lo = 0;
	for (int _=l;_<=r;_++)
		A[_].y > now ? now = A[_].y, lo = _ : 0;
	tr[ t=++cnt ].key = A[lo].y;
	build(l,lo-1,O.l);
	build(lo+1,r,O.r);
	up(t);
}

pii spl(int t,int k) {
	int tmp;
	if (!k) return MP(0,t);
	if (k == O.siz) return MP(t,0);
	return L.siz + 1 <= k ? 
		( GP(O.r, tmp, spl(O.r,k-L.siz-1)), up(t), MP(t,tmp) ):
		( GP(tmp, O.l, spl(O.l,k))        , up(t), MP(tmp,t) );
}

int mer(int x,int y) {
	if (!x || !y) return x+y;
	return tr[x].key > tr[y].key ?
		( tr[x].r = mer(tr[x].r, y), up(x) ):
		( tr[y].l = mer(x, tr[y].l), up(y) );
}

void solve() {
	for (int _=k+1;_<=n;_++) 
		A[_].x =(1LL*a*A[_-1].x+b) %p, A[_].y = (1LL*c*A[_-1].y+d) %p;
	sort(A+1,A+n+1);
	build(1,n,rt);
	m = rd();
	while (m--) {
		int ll = rd(), rr = rd(),r1,r2; pii tmp;

		tmp.x = ll, tmp.y = 0;
		ll = (int)(lower_bound(A+1,A+n+1,tmp) - A) - 1;
		GP(r1,rt,spl(rt,ll));

		tmp.x = rr+1, tmp.y = 0;
		rr = (int)(lower_bound(A+1,A+n+1,tmp) - A - 1) - ll;
		GP(rt,r2,spl(rt,rr));

		printf("%d\n",max(tr[rt].F, tr[rt].G));

		rt = mer(r1,rt);
		rt = mer(rt,r2);
	}
}

void init() {
	n = rd(), k = rd();
	for (int _=1;_<=k;_++) A[_].x = rd(), A[_].y = rd();
	a = rd(), b = rd(), c = rd(), d =rd();
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	init();
	solve();
	return 0;
}