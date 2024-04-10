#include <bits/stdc++.h>

#define maxn 1000005

int n,m,l,r;
char s[maxn];

struct data {
	int l,r,ans;
} sum[maxn<<2];

data merge(data a,data b) {
	data c; 
	c.ans = a.ans + b.ans + 2 * std::min(a.r,b.l);
	c.l = a.l + std::max(0,b.l - a.r);
	c.r = b.r + std::max(0,a.r - b.l);
	return c;
}

void build(int l,int r,int rt) {
	if (l == r) {
		if (s[l] == '(') sum[rt].r = 1;
		else sum[rt].l = 1;
		return;
	} int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	sum[rt] = merge(sum[rt<<1],sum[rt<<1|1]);
}

data query(int l,int r,int L,int R,int rt) {
	if (l <= L && R <= r) return sum[rt];
	if (l > R || r < L) return {0,0,0};
	return merge(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
}

int main() {
	scanf("%s",s+1);
	n = std::strlen(s + 1);
	build(1,n,1);
	scanf("%d",&m);
	while (m --) {
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r,1,n,1).ans);
	}
	return 0;
}