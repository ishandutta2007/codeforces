#include <iostream>
#include <cstdio>

#define mid ((l+r)>>1)
#define ls l,mid,2*t
#define rs mid+1,r,2*t+1

#define N 300050
using namespace std;
typedef long long LL;

inline int rd() { int t; scanf("%d",&t); return t; }
inline void ut(int &x,int y) { x = max(x,y); }
struct Tree{ int lb,rb,ans; }tr[4*N];
int tmp[N],n,bg[N];
LL a[N];

int dis(int x,int y) {
	if (!x || !y) return 0;
	int r = x - y;
	if (x == y+1 && a[x] == 0) return 1;
	return r+1;
	
	if (a[y+1] > 0 && a[x] < 0) r++;
	return r;
}

Tree merge(Tree p1,Tree p2) {
	Tree tmp;
	tmp.lb = p1.lb ? p1.lb : p2.lb;
	tmp.rb = p2.rb ? p2.rb : p1.rb;
	tmp.ans = max(p1.ans , p2.ans);
	ut(tmp.ans , dis( p2.lb , p1.rb ));
	return tmp;
}

void build(int l,int r,int t) {
	if (l == r) {
		tr[t].lb = tr[t].rb = bg[l] > 0 ? l : 0; 
		tr[t].ans = 1; 
		return ; }
	build(ls); build(rs);
	tr[t] = merge(tr[2*t] , tr[2*t+1]);
}

int x;
void update(int l,int r,int t) {
	if (l > x || r < x) return ;
	if (l == r) {
		tr[t].lb = tr[t].rb = bg[l] > 0 ? l : 0; 
		tr[t].ans = 1; 
		return ; }
	update(ls); update(rs);
	tr[t] = merge(tr[2*t] , tr[2*t+1]);
}

void init() {
	n=rd();
	tmp[0] = -1;
	for (int i=1;i<=n;i++) tmp[i] = rd();
	for (int i=2;i<=n;i++) a[i] = tmp[i] - tmp[i-1]; 
	
	for (int i=1;i<=n;i++) if ((a[i]<0 && a[i+1]>0) || (!a[i]) || (!a[i+1])) bg[i] = 1;
	build(1,n,1);
}

inline void c(int t) {
	if (t<1 || t>n) return ;
	bg[x=t] = (a[t]<0 && a[t+1]>0) || (!a[t]) || (!a[t+1]);
	update(1,n,1);
}

void solve() {
	int m = rd();
	while (m--) {
		int ql=rd() , qr=rd() , d=rd();
		a[ql] += 1LL * d; if (qr+1 <= n) a[qr+1] -= 1LL * d; a[1] = 0;
		c(ql-1); 
		c(ql); 
		c(ql+1);
		c(qr-1); 
		c(qr); 
		c(qr+1);
		int ans = tr[1].ans;
		if (tr[1].lb) ut(ans,tr[1].lb);
		if (tr[1].rb) ut(ans,n-tr[1].rb+1);
		if (!tr[1].lb && !tr[1].rb) ut(ans,n);
		printf("%d\n",ans);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("2.in","r",stdin);
		freopen("2.out","w",stdout);
	#endif
	init();
	solve();
	return 0;
}