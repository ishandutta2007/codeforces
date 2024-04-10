#include <bits/stdc++.h>
#define N 2000050
using namespace std;
typedef long long LL;
int n,m;
LL ans;
inline int rd() { int r; scanf("%d",&r); return r; }
struct Monster{ int l,r; LL v,ans; }Q[N];

inline void ut(LL &x,LL y) { x = max(x,y); }

bool cmp(Monster p1,Monster p2) { 
	return p1.r == p2.r ? p1.l > p2.l : p1.r > p2.r;
}

bool cmp2(Monster p1,Monster p2) {
	return p1.l > p2.l;
}

void solve(int l,int r) {
	if (l >= r) return ;
	int mid = (l + r) >> 1;
	solve(l,mid); 
	sort(Q+l,Q+mid+1,cmp2); //  
	
	int T = mid+1;
	LL cur = 0LL;
	for (int _=r;_>=mid+1;_--) {
		while (T-1 >= l && Q[T-1].l < Q[_].r) ut(cur , Q[T-1].ans) , T--;
		ut(Q[_].ans,cur+Q[_].v);
	}
	
	solve(mid+1,r);
}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) 
		Q[i].l = rd() , Q[i].r = rd() , Q[i].ans = Q[i].v = rd();
	sort(Q+1,Q+n+1,cmp);
	solve(1,n);
	for (int i=1;i<=n;i++) ut(ans,Q[i].ans);
	cout << ans << endl;
	return 0;
}