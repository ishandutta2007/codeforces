#include <bits/stdc++.h>

const int maxn = 1e5 + 17;
using ll = long long;
const int mod = 1e9 + 7;

int ch[maxn*32][2],h[maxn],a[maxn],n,q,rt[maxn],L[maxn],R[maxn],sz,tl;
ll ans = 0;

struct Lusterdawn {
	int sum[maxn];
	void reset() { std::memset(sum,0,sizeof(sum)); }
	void add(int x) { while (x <= n) { sum[x] ++; x += x & -x; } }
	int query(int x) { int ans = 0; while (x) { ans += sum[x]; x -= x & -x; } return ans; }
} bit;

struct data {
	ll L,M,R,LM,MR,LMR;
} sum[maxn * 32];

data merge(data a,data b) {
	if (a.L == -1) return b;
	if (b.L == -1) return a;
	data c;
	c.L = a.L + b.L;
	c.R = a.R + b.R;
	c.M = a.M + b.M;
	c.LM = (a.LM + b.LM + a.L * b.M % mod) % mod;
	c.MR = (a.MR + b.MR + a.M * b.R % mod) % mod; 
	c.LMR = ( a.LMR + b.LMR +  a.L * b.MR % mod + a.LM * b.R % mod ) % mod;
	return c;
}

int insert(int rt,int l,int r,int p) {
	if (!rt) rt = ++sz;
	if (l == r) {
		sum[rt] = {L[p],1,R[p],0,0,0};
		return rt;
	} int mid = (l + r) >> 1;
	if (p <= mid) ch[rt][0] = insert(ch[rt][0],l,mid,p);
	else ch[rt][1] = insert(ch[rt][1],mid+1,r,p);
	sum[rt] = merge(sum[ch[rt][0]],sum[ch[rt][1]]);
	return rt;
}

int erase(int rt,int l,int r,int p) {
	if (!rt) rt = ++sz;
	if (l == r) {
		sum[rt] = {0,0,0,0,0,0};
		return rt;
	} int mid = (l + r) >> 1;
	if (p <= mid) ch[rt][0] = erase(ch[rt][0],l,mid,p);
	else ch[rt][1] = erase(ch[rt][1],mid+1,r,p);
	sum[rt] = merge(sum[ch[rt][0]],sum[ch[rt][1]]);
	return rt;
}


int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		h[++tl] = a[i];
	} 
	std::sort(h+1,h+tl+1);
	tl = std::unique(h+1,h+tl+1) - (h+1);
	for (int i = 1; i <= n; ++ i) a[i] = std::lower_bound(h+1,h+tl+1,a[i]) - (h + 1) + 1;
	sum[0].L = -1;
	bit.reset();
	for (int i = 1; i <= n; ++ i) {
		L[i] = bit.query(a[i]);
		bit.add(a[i]);
	} bit.reset();
	for (int i = n; i >= 1; i --) {
		R[i] = bit.query(a[i]);
		bit.add(a[i]);
	} for (int i = 1; i <= n; ++ i) {
		ans = (ans - sum[rt[a[i]]].LMR + mod) % mod;
		rt[a[i]] = insert(rt[a[i]],1,n,i);
		ans = (ans + sum[rt[a[i]]].LMR) % mod;
	}
	scanf("%d",&q);
	while (q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		ans = (ans - sum[rt[a[y]]].LMR + mod) % mod;
		if (x == 1)	rt[a[y]] = erase(rt[a[y]],1,n,y);
		else rt[a[y]] = insert(rt[a[y]],1,n,y);
		ans = (ans + sum[rt[a[y]]].LMR) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}