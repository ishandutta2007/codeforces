#include <bits/stdc++.h>

#define maxn 300005

int a[maxn],b[maxn],n,m,tl,h[maxn<<1],vis[maxn],p,cnt,cw[maxn],sum;
std::vector<int>ans;

void add(int i) {
	int x = a[i];
	if (!x) return;
//	printf("+ %d (%d) %d %d\n",x,cw[x] == vis[x] - 1,cw[x],vis[x]);
	cnt += (cw[x] == vis[x] - 1);
	cw[x] ++;
}

void erz(int i) {
	int x = a[i];
	if ((!x) || (!cw[x])) return;
	//printf("- %d\n",x);
	cnt -= (cw[x] == vis[x]);
	cw[x] --;
}

int check() { return cnt == sum; }

int main() {
	scanf("%d%d%d",&n,&m,&p);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		h[++tl] = a[i];
	}
	for (int i = 1; i <= m; ++ i) {
		scanf("%d",&b[i]);
		h[++tl] = b[i];
	} std::sort(h+1,h+tl+1); tl = std::unique(h+1,h+tl+1) - (h + 1);
	for (int i = 1; i <= n; ++ i) a[i] = std::lower_bound(h+1,h+tl+1,a[i]) - (h+1) + 1;
	for (int i = 1; i <= m; ++ i) b[i] = std::lower_bound(h+1,h+tl+1,b[i]) - (h+1) + 1;
	sum = 0;
	for (int i = 1; i <= m; ++ i)  { sum += (vis[b[i]] == 0); vis[b[i]] ++; }
	for (int i = 1; i <= n; ++ i) if (!vis[a[i]]) a[i] = 0;
	for (int i = 1; i <= p; ++ i) {
		
		int c = i;
	//	printf("check %d\n",i);
		for (int j = 1; j <= m && c <= n; ++ j) { add(c); c += p; }
		if (check()) ans.push_back(c - p);
		//printf("->%d\n",cnt);
		while (c <= n) {
			erz(c - m * p);
			add(c);
			if (check()) ans.push_back(c);
		//	printf("->%d\n",cnt);
			c += p;
		} for (int j = i; j <= n; j += p) erz(j);
	}
	if (ans.size()) std::sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int x:ans) printf("%d ",x - (m - 1) * p);
	return 0;
}