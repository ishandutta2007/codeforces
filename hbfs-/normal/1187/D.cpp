#include <bits/stdc++.h>
#define N 300050

#define mid ((l+r)>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1

#define INF (1<<29)

using namespace std;

int tr[4*N], t[N], a[N], b[N], ll, rr, n;
vector<int> L[N];
inline int rd() {
	int r;scanf("%d",&r);return r;	
}

int build(int l,int r,int t) {
	return tr[t] = l==r ? a[l] : min(build(ls), build(rs));	
}

int query(int l,int r,int t) {
	if (l > rr || r < ll) return INF;
	if (l >= ll && r <= rr) return tr[t];
	return min(query(ls), query(rs));
}

void update(int l, int r, int t) {
	if (l > rr || r < ll) return ;
	if (l == r) {
		tr[t] = INF;
		return ;	
	}
	if (ll <= mid)
		update(ls);
	if (rr > mid)
		update(rs);
	tr[t] = min(tr[t<<1], tr[t<<1^1]);	
}

void solve() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=1;i<=n;i++) b[i] = rd();
	
	build(1, n, 1);
	for (int i=1;i<=n;i++) L[i].clear(), t[i] = 0;
	for (int i=1;i<=n;i++) L[ a[i] ].push_back(i);
	for (int i=1;i<=n;i++) t[i] = 0;
	
	for (int i=1;i<=n;i++) {
		if (t[ b[i] ] < (int)L[ b[i] ].size()) {
			rr = L[ b[i] ][ t[b[i]]++ ];
			ll = 1;
			int x = query(1, n, 1);
			if (x != a[rr]) {
				puts("NO");
				return ;	
			} else {
				ll = rr;
				update(1, n, 1);	
			}
		} else {
			puts("NO");
			return ;	
		}
	}
	
	puts("YES");
	
	return ;	
}

int main() {
	for (int T=rd();T;T--) solve();
	return 0;	
}