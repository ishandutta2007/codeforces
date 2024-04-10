#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

const long long INF = 0x3f3f3f3f3f3f3f3f;

inline int read(){
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int x = c ^ '0'; c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	return x;
}

inline void print(long long x){
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int fa[500010], leaf[500010];
vector <pii> from[500010];
vector <piii> q[500010];
long long ans[500010];
int size[500010];
long long dist[500010];
int n, m;

struct Segment_tree{
	struct Node{
		long long minj, lazy;
	}T[2000000];
	void pushdown(int now){
		if (!T[now].lazy) return ;
		long long v = T[now].lazy;
		T[now].lazy = 0;
		T[now << 1].minj += v, T[now << 1].lazy += v;
		T[now << 1 | 1].minj += v, T[now << 1 | 1].lazy += v;
	}
	void pushup(int now){
		T[now].minj = min(T[now << 1].minj, T[now << 1 | 1].minj);
	}
	void Build(int now, int l, int r){
		T[now].lazy = 0;
		if (l == r){
			T[now].minj = leaf[l] ? dist[l] : INF;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, long long v){
//		cout << "  Update:" << now << " " << l << " " << r << " " << L << " " << R << " " << v << endl;
		if (l == L && r == R){
			T[now].minj += v, T[now].lazy += v;
//			cout << "    minj:" << T[now].minj << endl;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, v);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, v);
		else Update(now << 1, l, mid, L, mid, v), Update(now << 1 | 1, mid + 1, r, mid + 1, R, v);
		pushup(now);
	}
	long long Query(int now, int l, int r, int L, int R){
		if (l == L && r == R) return T[now].minj;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return min(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

void dfs(int x){
	if (!from[x].size()) leaf[x] = 1;
	size[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i].fi, w = from[x][i].se;
		dist[v] = dist[x] + w, dfs(v), size[x] += size[v];
	}
}

long long all; 

void get_ans(int x){
	for (int i = 0; i < q[x].size(); i++){
		int l = q[x][i].fi.fi, r = q[x][i].fi.se, id = q[x][i].se;
		ans[id] = seg.Query(1, 1, n, l, r) + all;
	}
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i].fi, w = from[x][i].se;
		all += w, seg.Update(1, 1, n, v, v + size[v] - 1, -2 * w);
		get_ans(v);
		seg.Update(1, 1, n, v, v + size[v] - 1, 2 * w), all -= w;
	}
}

int main(){
	n = read(), m = read();
	for (int i = 2; i <= n; i++){
		fa[i] = read();
		int w = read();
		from[fa[i]].push_back(pii(i, w));
	}
	for (int i = 0; i < m; i++){
		int x = read(), l = read(), r = read();
		q[x].push_back(mp(mp(l, r), i));
	}
	dfs(1), seg.Build(1, 1, n), get_ans(1);
	for (int i = 0; i < m; i++){
		print(ans[i]), putchar('\n');
	}
	return 0;
}