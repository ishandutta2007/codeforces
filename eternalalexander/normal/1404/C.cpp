#include <bits/stdc++.h>
const int maxn = 3e5 + 17;
int n,q,rk[maxn],a[maxn],l[maxn],r[maxn],ans[maxn],b[maxn],x,y;

struct B {
	int sum[maxn];
	void reset(){std::memset(sum,0,sizeof(sum));}
	void add(int x){while(x){sum[x]++;x-=x&-x;}}
	int query(int x){int ans = 0;while(x<=n){ans+=sum[x];x+=x&-x;}return ans; }
}bit;


int cmp(int a,int b) { return r[a] < r[b]; }
void ins(int x){
	if(b[x]>n)return;
	bit.add(b[x]);
}

int main() {
	bit.reset();
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	for (int i = 1; i <= n; ++ i) {
		// i - x <= a[i] && a[i] <= i
		if (a[i] > i) { b[i] = n + 1;  continue; }
		int l = 1, r = i, ans = n + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (bit.query(mid) >= i - a[i]) { ans = mid; l = mid + 1; }
			else r = mid - 1;
		} b[i] = ans;
		if (b[i] <= n) bit.add(b[i]);
	//	printf("%d ",b[i]);
	}
	for (int i =1;i<=q;++i) {
		scanf("%d%d",&x,&y);
		l[i] = 1 + x;
		r[i] = n - y;
		rk[i] = i;
	}std::sort(rk+1,rk+q+1,cmp);
	bit.reset();
	int p = 0;
	for (int i = 1; i <= q; ++ i) {
		int j = rk[i];
		while (p < r[j]) ins(++p);
		ans[j] = bit.query(l[j]);
	} for (int i = 1; i <= q; ++ i) printf("%d\n",ans[i]);
	return 0;
}