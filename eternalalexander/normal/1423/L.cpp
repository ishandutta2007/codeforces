#include <bits/stdc++.h>
#define mp std::make_pair
#define pii std::pair<int,int>
#define ll long long
int b1 = 17, b2 = 23, m1 = 998244353, m2 = 1e9+7;
int n,s,d,c,x,cost[1<<21],tl1,tl2;
std::map<pii,int>answ;
struct BITSET {
	unsigned ll a[17];
	BITSET () { std::memset(a,0,sizeof(a)); }
	void set(int x) {
		int p = x/64;
		int q = x%64;
		a[p] |= (1ull << q);
	} int hash(int b,int m) {
		int ans = 0;
		for (int i = 0; i < 16; ++ i) ans = ((ll) ans * b + a[i]%m) % m;
		return ans;
	}
}res1[1<<11],res2[1<<21],b[3005],B,cur;

BITSET x_or(BITSET a,BITSET b) {
	BITSET c;
	for (int i = 0; i < 16; ++ i) c.a[i] = a.a[i] ^ b.a[i];
	return c;
}

void dfs1(int p,int lim,int ct = 0) {
	if (p == lim+1) {
		res1[++tl1] = cur;
		cost[tl1] = ct;
		return;
	} dfs1(p+1,lim,ct);
	cur = x_or(cur,b[p]);
	dfs1(p+1,lim,ct+1);
	cur = x_or(cur,b[p]);
}

void dfs2(int p,int ct = 0) {
	if (p == s + 1) {
		pii P = mp(cur.hash(b1,m1),cur.hash(b2,m2));
		if (answ.find(P) == answ.end()) answ[P] = ct;
		else answ[P] = std::min(answ[P],ct);
		return;
	}
	dfs2(p+1,ct);
	cur = x_or(cur,b[p]);
	dfs2(p+1,ct+1);
	cur = x_or(cur,b[p]);
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&s,&d);
	for (int i = 1; i <= s; ++ i) {
		scanf("%d",&c);
		for (int j = 1; j <= c; ++ j) {
			scanf("%d",&x);
			b[i].set(x);
		}
	} dfs2(s/3+1);
	dfs1(1,s/3);
	while (d--) {
		scanf("%d",&c);
		std::memset(B.a,0,sizeof(B.a));
		for (int i = 1; i <= c; ++ i) {
			scanf("%d",&x);
			B.set(x);
		} int ans = 1e9;
		for (int i = 1; i <= tl1; ++ i) {
			if (cost[i] > ans) continue;
			BITSET tmp = x_or(res1[i],B);
			auto p = mp(tmp.hash(b1,m1),tmp.hash(b2,m2));
			if (answ.find(p) == answ.end()) continue;
			ans = std::min(ans,answ[p] + cost[i]);
		} printf("%d\n",ans > s ? -1 : ans);
	}
	return 0;
}