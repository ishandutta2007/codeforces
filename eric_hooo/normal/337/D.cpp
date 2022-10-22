#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int pos[100010];
vector <int> from[100010];
int id[100010], num[100010], size[100010], deep[100010];
int cnt = 1;
int n, m, d;

struct Segment_tree{
	struct Node{
		int maxj, lazy;
	}T[400010];
	void pushup(int now){
		T[now].maxj = max(T[now << 1].maxj, T[now << 1 | 1].maxj);
	}
	void pushdown(int now){
		if (!T[now].lazy) return ;
		int v = T[now].lazy; T[now].lazy = 0;
		T[now << 1].maxj += v, T[now << 1].lazy += v;
		T[now << 1 | 1].maxj += v, T[now << 1 | 1].lazy += v;
	}
	void Build(int now, int l, int r){
		T[now].lazy = 0;
		if (l == r){
			T[now].maxj = pos[num[l]] ? deep[num[l]] : -INF;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int x){
		if (L > R) return ;
		if (l == L && r == R){
			T[now].maxj += x;
			T[now].lazy += x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	void Update(int l, int r, int x){Update(1, 1, n, l, r, x);}
	int Query(){return T[1].maxj;}
}seg;

void dfs(int x, int last){
	id[x] = cnt++, num[id[x]] = x, size[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		deep[v] = deep[x] + 1, dfs(v, x), size[x] += size[v];
	}
}

int get_ans(int x, int last){
	int dist = seg.Query();
	int ans = 0;
	if (dist >= 0 && dist <= d) ans++;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		seg.Update(1, n, 1), seg.Update(id[v], id[v] + size[v] - 1, -2);
		ans += get_ans(v, x);
		seg.Update(1, n, -1), seg.Update(id[v], id[v] + size[v] - 1, 2);
	}
	return ans;
}

int main(){
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++){
		int x; scanf("%d", &x);
		pos[x] = 1;
	}
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs(1, 1), seg.Build(1, 1, n);
	printf("%d\n", get_ans(1, 1));
	return 0;
}