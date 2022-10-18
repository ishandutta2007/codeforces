#include <bits/stdc++.h>

const int maxn = 4e5 + 2222;
int n,q,opt[maxn],l[maxn],r[maxn],x[maxn],zero[maxn],one[maxn],nxt[maxn];

int find(int x) {
	if (!nxt[x]) return x;
	return nxt[x] = find(nxt[x]);
} 

struct data {
	int fr,sc;
} sum[maxn << 2],NL;

data merge(data x,data y) {
	std::vector<int>v = {x.fr,x.sc,y.fr,y.sc};
	std::sort(v.begin(),v.end(),[](int a,int b) { return zero[a] > zero[b]; });
	data d; d.fr = v[0]; d.sc = v[1];
	return d;
}

void build(int l,int r,int rt) {
	if (l == r) {
		sum[rt].fr = l; sum[rt].sc = 0;
	//	printf("sum[%d] = <%d %d>\n",rt,sum[rt].fr,sum[rt].sc);
		return ;
	} int mid = (l + r) / 2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	sum[rt] = merge(sum[rt<<1],sum[rt<<1|1]);
//	printf("sum[%d] = <%d %d>\n",rt,sum[rt].fr,sum[rt].sc);
}

data query(int l,int r,int L,int R,int rt) {
	if (l > R || r < L) { return NL; }
	if (l <= L && R <= r) return sum[rt];
	return merge(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
} 

int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= q; ++ i) {
		scanf("%d",&opt[i]);
		if (opt[i] == 0) scanf("%d%d%d",&l[i],&r[i],&x[i]);
		else scanf("%d",&x[i]);
	} 
	for (int i = 1; i <= n; ++ i) one[i] = zero[i] = q + 1;
	for (int i = 1; i <= q; ++ i) {
		if ( ( opt[i] == 1 ) || ( x[i] == 1 ) ) continue;
		int p = find(l[i]);
		while (p <= r[i]) {
			nxt[p] = p + 1;
			assert(zero[p] == q + 1);
			zero[p] = i;
		//	printf("zero[%d] = %d\n",p,i);
			p = find(nxt[p]);
		} 
	} //for (int i = 0;  i <= n; ++ i) printf("%d ",zero[i]); puts("");
	build(1,n,1);
	for (int i = 1; i <= q; ++ i) {
		if ( ( opt[i] == 1 ) || ( x[i] == 0 ) ) continue;
		auto pr = query(l[i],r[i],1,n,1);
		int fr = pr.fr, sc = pr.sc;
		if (zero[fr] < q + 1) assert(0);
		if (!sc) { one[fr] = std::min(one[fr],i);  }
		else {
			one[fr] = std::min(one[fr],std::max(i,zero[sc]));
		}
	} for (int i = 1; i <= q; ++ i) {
		if (opt[i] == 0) continue;
		int c = -1;
		if (one[x[i]] <= i) c = 1;
		if (zero[x[i]] <= i) { assert(c == -1); c = 0; }
	//	printf("<%d> %d %d\n",x[i],zero[x[i]],i);
		if (c == -1) puts("N/A");
		if (c == 1) puts("YES");
		if (c == 0) puts("NO");
	} 
	return 0;
}