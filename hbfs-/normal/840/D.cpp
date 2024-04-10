#include <bits/stdc++.h>
#define N 300050
#define mid ((l+r)>>1)
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int a[N],x,rt[N],tr[20*N],ls[20*N],rs[20*N],tot,v,ans,n,q;

void update(int &lt,int rt,int l,int r) {
	tr[lt=++tot] = tr[rt];
	ls[lt] = ls[rt];
	rs[lt] = rs[rt];
	if (l == r) {
		tr[lt]++;
		return ;
	}
	if (x <= mid)
		update(ls[lt],ls[rt],l,mid);
	else
		update(rs[lt],rs[rt],mid+1,r);
	tr[lt] = tr[ls[lt]] + tr[rs[lt]];
}

void query(int lt,int rt,int l,int r) {
	if (tr[lt]-tr[rt] < v) return ;
	if (l == r) {
		if (ans == -1) ans = l; else ans = min(ans, l);
		return ;
	}
	query(ls[lt],ls[rt],l,mid);
	query(rs[lt],rs[rt],mid+1,r);
}

int main() {
	n = rd(), q = rd();
	for (int i=1;i<=n;i++) a[i] = rd();

	for (int i=1;i<=n;i++) {
		x = a[i];
		update(rt[i], rt[i-1], 1, n);
	}
	
	while (q--) {
		int ll = rd(), rr = rd(), k = rd();
		v = (rr-ll+1) / k + 1;
		ans = -1;
		query(rt[rr], rt[ll-1], 1, n);
		printf("%d\n",ans);
	}
	
	return 0;
}