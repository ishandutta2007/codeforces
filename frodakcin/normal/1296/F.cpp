#include <cstdio>
#include <cassert>
#include <cstring>
#include <functional>
#include <algorithm>

template<class T> bool ckmax(T *a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T *a, T b) {return b<*a?*a=b,1:0;}

const int MN = 5e3 + 10, MM = 5e3 + 10;
const int MV = 1e7;
const int L2 = 18;
int N, M;
int hd[MN], nx[MN*2], to[MN*2], E;

void adde(int a, int b)
{
	nx[E] = hd[a];
	to[E] = b;
	hd[a] = E;
	++E;
}
struct low
{
public:
	int l, n;
	bool operator < (low o) const {return l < o.l || !(o.l < l) && n < o.n;}
};
low rmq[MN*2][L2];
int pre[MN], post[MN], T;
int p[MN][L2], pe[MN], d[MN];
int ans[MN];
void dfs(int n)
{
	for(int i = 0;;++i)
		if(p[n][i] && p[p[n][i]][i])
			p[n][i+1] = p[p[n][i]][i];
		else
			break;
	//printf("PARR %d -> %d\n", n, p[n][1]);
	post[n] = pre[n] = T++;
	rmq[pre[n]][0] = {d[n], n};
	for(int i = hd[n], x;~i;i = nx[i])
		if((x = to[i]) != p[n][0])
		{
			p[x][0] = n;
			pe[x] = i/2;
			d[x] = d[n]+1;
			dfs(x);
			post[n] = T++;
			rmq[post[n]][0] = {d[n], n};
		}
}
int lca(int a, int b)
{
	if(a == b) return a;
	a = pre[a], b = pre[b];//WTF how did this pass first 51 cases with d[a] and d[b]
	if(b<a) std::swap(a,b);
	int d = 31 - __builtin_clz(b-a);
	return std::min(rmq[a][d], rmq[b-(1<<d)][d]).n;//does not include b, but that's okay cuz b can't be an ancestor of a
}
struct upd
{
public:
	int a, b, w;
	void in() {scanf("%d%d%d", &a, &b, &w);}
	bool operator > (upd o) const {return w > o.w;}
};
upd b[MM];
int jmp[MN];
int color(int n, int ld, int c)
{
	if(d[n] <= ld)
		return jmp[n];
	if(jmp[n] == n)
		return ans[pe[n]] = c, jmp[n] = color(p[n][0], ld, c);
	return jmp[n] = color(jmp[n], ld, c);
}

int mw[MN][L2];
void dfs2(int n)
{
	mw[n][0] = ans[pe[n]];
	for(int i = 0;;++i)
		if(p[n][i+1])
			mw[n][i+1] = std::min(mw[n][i], mw[p[n][i]][i]);
		else
			break;
	for(int i = hd[n], x;~i;i = nx[i])
		if((x = to[i]) != p[n][0])
			dfs2(x);
}
int getmin(int a, int b)
{
	int m = MV;
	if(d[b] < d[a]) std::swap(a, b);
	for(int x = d[b]-d[a], i = 0;(1<<i) <= x;++i)
		if(x>>i&1)
			ckmin(&m, mw[b][i]), b = p[b][i];
	//printf("OUTM %d\n", m);
	if(a == b) return m;
	for(int i = 31 - __builtin_clz(d[a]-d[1]);i >= 0;--i)
		if(p[a][i] && p[a][i] != p[b][i])
			ckmin(&m, std::min(mw[a][i], mw[b][i])), a = p[a][i], b = p[b][i];
	return std::min({m, mw[a][0], mw[b][0]});
}
int main(void)
{
	//lca
	memset(hd, -1, sizeof(hd));
	scanf("%d", &N);
	for(int i = 0, x, y;i < N-1;++i)
		scanf("%d%d", &x, &y), adde(x, y), adde(y, x);
	dfs(1);
	assert(T == N*2-1);
	for(int i = T-1;i >= 0;--i)
		for(int j = 0;i + (1<<j+1) < T;++j)//.... HOW DID REVERSING ORDER OF FOR LOOP PASS 97 TESTS
			rmq[i][j+1] = std::min(rmq[i][j], rmq[i+(1<<j)][j]);
	//color
	scanf("%d", &M);
	for(int i = 0;i < M;++i)
		b[i].in();
	std::sort(b, b+M, std::greater<upd>());
	for(int i = 1;i <= N;++i)
		jmp[i] = i;
	for(int i = 0, l;i < M;++i)
	{
		l = lca(b[i].a, b[i].b);
		//printf("LCA(%d %d): %d\n", b[i].a, b[i].b, l);
		if(l != b[i].a)
			color(b[i].a, d[l], b[i].w);
		if(l != b[i].b)
			color(b[i].b, d[l], b[i].w);
	}
	//check
	//for(int i = 0;i+1 < N;++i) printf("%d%c", std::max(0, ans[i]), " \n"[i+2==N]);
	dfs2(1);
	for(int i = 0;i < M;++i)
		if(getmin(b[i].a, b[i].b) != b[i].w)//can have some asserts here
			return printf("-1\n"), 0;
	//ans
	for(int i = 0;i+1 < N;++i)
		printf("%d%c", std::max(1, ans[i]), " \n"[i+2==N]);//change to 1 before you submit
	return 0;
}