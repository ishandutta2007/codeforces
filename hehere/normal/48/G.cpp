#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'\n", __LINE__, __FUNCTION__);
typedef int real;
#define int LL
namespace BasicUnit {
	inline int readint() {
		int a = 0, p = 1; char c = getchar();
		while(isspace(c) && c != '-') c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a * p;
	}
	inline LL readLL() {
		LL a = 0, p = 1; char c = getchar();
		while(isspace(c) && c != '-') c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a * p;
	}
}
using namespace BasicUnit;
const int maxN = 200000 + 233;
int n;
struct Edge {
	int from, to, dist, last;
	Edge(int f=0, int t=0, int d=0, int l=0) : from(f), to(t), dist(d), last(l) {}
}edges[maxN << 1]; int h[maxN];

int loop[maxN << 1], cnt = 0;
bool il[maxN];
int sd[maxN << 1], d[maxN << 1];

int tmp = 0;
void dfs2(int u, int fa, int v) {
//	printf("%d vis\n", u);getchar();
	if(tmp + 1 > cnt * 2) return;
	++tmp; sd[tmp] = sd[tmp - 1] + v;
	for(int i = h[u]; i; i = edges[i].last) {
		Edge &e = edges[i];
		if(e.to == fa || !il[e.to]) continue;
		dfs2(e.to, u, e.dist);
	}
}

bool vis[maxN];
int stk[maxN], top = 0;
void mark_loop(int u) {
	memset(il, 0, sizeof(il));
	do {
		il[loop[++cnt] = stk[top]] = true;
	} while(stk[top--] != u);
//	printf("%d\n", cnt);
	dfs2(loop[1], loop[cnt], 0);
//	for(int i = cnt + 1; i <= 2*cnt; ++i) sd[i] = sd[i-1] + (sd[i-cnt] - sd[i-cnt-1]);
	for(int i = 1; i <= cnt * 2; ++i) d[i] = sd[i] - sd[i-1]; d[1] = d[cnt + 1];
	for(int i = cnt + 1; i <= cnt*2; ++i) loop[i] = loop[i-cnt];
//	for(int i = 1; i <= cnt; ++i) printf("%d ", loop[i]);
//	printf("(loop)\n");
//	for(int i = 1; i <= 2*cnt; ++i) printf("%d ", sd[i]);
//	printf("(sd)\n");
//	for(int i = 1; i <= 2*cnt; ++i) printf("%d ", d[i]);
//	printf("(d)\n");
}

bool dfs1(int u, int fa) {
	vis[u] = true; stk[++top] = u;
	for(int i = h[u]; i; i=edges[i].last) {
		Edge &e = edges[i];
		if(e.to == fa) continue;
		if(vis[e.to]) { mark_loop(e.to); return true; }
		if(dfs1(e.to, u)) return true;
	}
	top--;
	return false;
}

int sz[maxN];
int ans[maxN];//temp. as sum of depths
void dfs3(int u, int fa) {
//	printf("%d vis\n", u);
	sz[u] = 1;
	for(int i = h[u]; i; i = edges[i].last) {
		Edge &e = edges[i];
		if(e.to == fa || sz[e.to]) continue;
		dfs3(e.to, u);
		if(!il[e.to]) sz[u] += sz[e.to], ans[u] += ans[e.to] + sz[e.to]*e.dist;
	}
}
void dfs4(int u, int fa) {
	for(int i = h[u]; i; i = edges[i].last) {
		Edge &e = edges[i];
		if(e.to == fa) continue;
		if(il[e.to]) continue;
		int delta = ans[u] - (ans[e.to] + sz[e.to]*e.dist);
		ans[e.to] += delta + (n - sz[e.to]) * e.dist;
		dfs4(e.to, u);
	}
}

int down[maxN], val, L, R;
int j;

void shift_i(int &i) {
//	printf("shift_iter: ");
	val += down[loop[i]]; R += sz[loop[i]];
//	printf(" + %d", down[loop[i]]);
	++i;
	val -= down[loop[i]];
	val += R * d[i];
	val -= L * d[i]; L -= sz[loop[i]];
//	printf(" - %d + %d - %d\n", down[loop[i]], R * d[i], L * d[i+1]);
}

void shift_j(int i) {
//	printf("shift_j: ");
	val += (sd[j+1] - sd[i]) * sz[loop[j+1]];
//	printf(" +%d ", (sd[j+1] - sd[i]) * sz[loop[j+1]]);
	++j;
	L += sz[loop[j]]; R -= sz[loop[j]];
	val -= sz[loop[j]] * (sd[i+cnt] - sd[j]);
//	printf(" -%d \n", sz[loop[j]] * (sd[i+cnt] - sd[j]));
//	printf("shift_j: val = %d\n", val);
}
/*
8
5 4 1
8 6 2
3 2 1
2 4 2
8 5 3
7 6 2
1 4 1
6 5 3

ans = 27 29 35 21 21 29 41 31
*/

void calc() {
	for(int i = 1; i <= n; ++i) down[i] = ans[i];
	j = 1; val = L = R = 0;
	for(int k = 2; k <= cnt; ++k) val = val + down[loop[k]] + R * d[k], R += sz[loop[k]]/*, printf("val = %d\n", val)*/;
	val += R * d[1 + cnt];
//	printf("Initiallized. j = %d, val = %d, L = %d, R = %d\n", j, val, L, R);
	for(int i = 1; i <= cnt; ++i) { // warning: boundary cases
		if(i != 1) {//shift
			--i;
			if(j == i) shift_j(i);
			shift_i(i);
		}
		if(j == i + cnt - 1) goto FINAL;
		while(j <= i + cnt - 2) {
			int vv = val, jj = j, ll = L, rr = R;
			shift_j(i);
			if(val < vv) ; else {
				val = vv; j = jj; L = ll; R = rr;
				break;
			}
		}
		FINAL: {}
		ans[loop[i]] += val;
//		printf("Done. j = %d, val = %d, L = %d, R = %d\n", j, val, L, R);
//		printf("%dth->%dth (%d -> %d) got val %d, ans = %d\n", i, j, loop[i], loop[j], val, ans[loop[i]]);
		dfs4(loop[i], -1);
	}
}
/*
8
1 2 2
2 3 3
2 5 2
3 4 3
5 4 1
4 8 4
4 6 4
6 7 3

3
1 2 3
2 3 2
1 3 1
*/
real main() {
	
	n = readint();
	for(int i = 1; i <= n; ++i) {
		int x = readint(), y = readint(), z = readint();
		edges[i<<1] = Edge(x, y, z, h[x]); h[x] = i<<1;
		edges[i<<1|1] = Edge(y, x, z, h[y]); h[y] = i<<1|1;
	}
	//find out the loop
	memset(vis, 0, sizeof(vis)); top = 0;
	dfs1(1, -1);
	//work out the sizes
	memset(sz, 0, sizeof(sz)); memset(ans, 0, sizeof(ans));
	dfs3(loop[1], -1);
//	for(int i = 1; i <= n; ++i) printf("%d ", sz[i]); printf("\n");
//	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]); printf("\n");
	calc();
//	printf("\n\nFINAL = \n");
	for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
	return 0;
}