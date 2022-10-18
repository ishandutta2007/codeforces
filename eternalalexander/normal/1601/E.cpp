#include <bits/stdc++.h>

using ll = long long;
const int maxn = 3e5 + 222;

int n,q,k,a[maxn],sum[maxn],l[maxn],r[maxn],T[maxn][21],stk[maxn],top,len[maxn];
ll ans[maxn],sw[maxn];
std::vector<int>reg[maxn],qry[maxn];

void build_RMQ() {
	len[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		T[i][0] = a[i];
		len[i] = len[i - 1];
		while ((1 << (len[i] + 1) ) <= i) len[i] ++;
	} 
	for (int i = 1; i <= 19; ++ i) {
		for (int j = n; j >= 1; j --) {
			int nxt = j + (1 << (i - 1));
			if (nxt > n) T[j][i] = T[j][i-1];
			else T[j][i] = std::min(T[j][i-1],T[nxt][i-1]);
		}
	}
}

int query(int l,int r) {
	int p = len[r - l + 1];
	return std::min(T[l][p], T[r-(1<<p)+1][p]);
}


void solve1() {
	build_RMQ();
	for (int i = 1; i <= q; ++ i) {
		int p = l[i];
		ll ans = 0;
		while (p <= r[i]) {
			ans += query(l[i],p);
			p += k;
		} printf("%lld\n",ans);
	} 
}

void solve2() {
	for (int c = 0; c < k; ++ c) {
		for (int i = 1; i <= n; ++ i) {
			sum[i] = sum[i - 1] + ( (i % k) == c);
			qry[i].clear();
		}// for (int i = 1; i <= n; ++ i) printf("%d ",sum[i]); puts("");
		for (int x:reg[c]) qry[l[x]].push_back(x); 
		stk[top = 1] = n + 1;
		a[n + 1] = -10;
		for (int i = n; i >= 1; i --) {
			while (a[i] < a[stk[top]]) top --;
			stk[++top] = i;
			sw[top] = sw[top - 1] + (ll) a[i] * (sum[stk[top - 1] - 1] - sum[i - 1]);
			//printf("%d<%d> %d<%d>\n",stk[top-1],sum[stk[top-1]],i-1,sum[i-1]);
		//	assert(sum[stk[top - 1]] >= sum[i - 1]);
			for (int x:qry[i]) {
				int lp = 1, rp = top, p = top;
				while (lp <= rp) {
					int mid = (lp + rp) >> 1;
					if (stk[mid] <= r[x]) { p = mid; rp = mid - 1; }
					else lp = mid + 1;
				}
				assert(stk[p] <= r[x]);
				assert(stk[p - 1] > r[x]);
			//	for (int j = 1; j <= top; ++ j) printf("<%d %d> %lld\n",stk[j],a[stk[j]],sw[j]);
			//	printf("(%d) [%d %d], p = %d,%lld,%d - <%d>%d\n",x,l[x],r[x],p,sw[top] - sw[p],sum[r[x]] ,stk[p],sum[stk[p] - 1]); 
				ans[x] = sw[top] - sw[p] + (ll) (sum[r[x]] - sum[stk[p] - 1]) * a[stk[p]];
			}		
		} 
	} for (int i = 1; i <= q; ++ i) 
		printf("%lld\n",ans[i]);
}
		

int main() {
	scanf("%d%d%d",&n,&q,&k);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	for (int i = 1; i <= q; ++ i) {
		scanf("%d%d",&l[i],&r[i]);
		reg[l[i] % k].push_back(i);
	}
	int B = std::sqrt(n);
	if (k>B) solve1();
	else solve2();
	return 0;
}