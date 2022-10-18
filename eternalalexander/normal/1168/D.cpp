#include <bits/stdc++.h>

const int maxn = 150005 + 7;
int L[maxn],sum[maxn],d[maxn],fa[maxn],link[maxn],f[maxn][27],g[maxn][27],belong[maxn],
bad[maxn],len,old[maxn][27];
int n,q,bad_cnt;
char c[maxn],s[maxn];
std::vector<int>ch[maxn],nxt[maxn],S[maxn][26];

int is_single(int x) {
	if (x == 0 || x == 1) return 0;
	return ch[fa[x]].size() == 1;
}

int get(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	return 26;
}

int calc() {
	int ans = 0, free = L[1] - sum[1];
	for (int i = 0; i < 26; ++i) 
		ans += (i + 1) * (f[1][i] + free);
	return ans;
}

void dfs(int u) {
	d[u] = d[fa[u]] + 1;
	if (ch[u].empty()) {
		if (len && d[u] != len) {
			while (q--) puts("Fou");
			exit(0);
		} len = d[u];
		return ;
	} for (int v:ch[u]) dfs(v);
}

void shrink() {
	for (int i = n; i >= 1; i --) {
		if (belong[i]) continue;
		belong[i] = i;
		link[i] = fa[i];
		g[i][get(c[i])] ++;
		while (is_single(i) && is_single(link[i])) { //should handle zero 
		//	printf("%d (%d) is single\n",link[i],ch[fa[link[i]]].size());
			g[i][get(c[link[i]])] ++;
			belong[link[i]] = i;
			link[i] = fa[link[i]];
		}
		//printf("%d -> %d\n",i,link[i]);
		nxt[link[i]].push_back(i);
	} 
	for (int i = n; i >= 1; i --) {
		if (belong[i] != i) continue;
		L[i] = len - d[i];
		if (d[i] == len) continue;
		for (int v:nxt[i]) 
			for (int j = 0; j < 26; ++ j) S[i][j].push_back(old[v][j] = f[v][j] + g[v][j]);
	//	for (int j = 0; j < 26; ++ j) assert(S[i][j].size());
		for (int j = 0; j < 26; ++ j) {
			std::sort(S[i][j].begin(),S[i][j].end());
			f[i][j] = *S[i][j].rbegin();
		}
		sum[i] = std::accumulate(f[i], f[i] + 26, 0);
		bad[i] = (sum[i] > L[i]);
		bad_cnt += bad[i];
	}
}

void update(int x,int c) {
	if ( ( x == 1 ) || (c == 26) ) return;
//	printf("update %d %d\n",x,c);
	int pre = link[x];
	bad_cnt -= bad[pre];
	sum[pre] -= f[pre][c];
	S[link[x]][c].erase(std::lower_bound(S[pre][c].begin(),S[pre][c].end(),old[x][c]));
	old[x][c] = f[x][c] + g[x][c];
	S[link[x]][c].insert(std::lower_bound(S[pre][c].begin(),S[pre][c].end(),old[x][c]),old[x][c]);
	f[link[x]][c] = *S[link[x]][c].rbegin();
	sum[pre] += f[pre][c];
//	printf("%d sum = %d, L = %d\n",pre,sum[pre],L[pre]);
	bad[pre] = (sum[pre] > L[pre]);
	bad_cnt += bad[pre];
	update(link[x],c);
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i = 2; i <= n; ++ i) {
		scanf("%d%s",&fa[i],s + 1);
		c[i] = s[1];
	//	printf("%d - %c > %d\n",fa[i],c[i],i);
		ch[fa[i]].push_back(i);
	} //puts("!");
	dfs(1);
//	puts("!");
	shrink();
//	puts("!");
	while (q--) {
		int x; char y;
		scanf("%d%s",&x,s + 1);
		y = s[1];
		int old = get(c[x]); c[x] = y;
		int z = get(y);
		x = belong[x];
	//	printf("<%d> - %d + %d\n",x,old,z);
		g[x][old] --; g[x][z] ++;
		update(x,old); update(x,z);
		if ( 0 == bad_cnt ) printf("Shi %d\n",calc());
		else puts("Fou");
	}
	return 0;
}