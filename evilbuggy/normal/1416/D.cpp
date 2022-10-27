#include <bits/stdc++.h>
using namespace std;

struct RollbackInfo{
	int u, v, pu, pv;
	RollbackInfo(int iu, int iv, int ipu, int ipv){
		u = iu; v = iv; pu = ipu; pv = ipv;
	}
};

const int N = 500005;

int n, m, q, ptr;
int a[N], b[N], p[N], par[N], type[N], val[N], rem[N], st[N], en[N], vert[N], tree[N << 2];

vector<int> g[N];
stack<RollbackInfo> stk;

int find(int v){
	return (par[v] < 0)?v:(par[v] = find(par[v]));
}

bool combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v)return false;
	
	stk.push(RollbackInfo(u, v, par[u], par[v]));
	par[u] = par[v] = n + 1;
	g[n + 1].push_back(u);
	g[n + 1].push_back(v);
	++n; return true;
}

void dfs(int v){
	++ptr;
	st[v] = ptr;
	vert[ptr] = v;
	for(int u : g[v]){
		dfs(u);
	}
	en[v] = ptr;
}

void build(int v, int l, int r){
	if(l == r){
		tree[v] = vert[l];
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	if(p[tree[v1]] >= p[tree[v2]]){
		tree[v] = tree[v1];
	}else{
		tree[v] = tree[v2];
	}
}

void update(int v, int l, int r, int i){
	if(l == r){
		p[vert[l]] = 0;
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update(v1, l, m, i);
	else update(v2, m + 1, r, i);
	if(p[tree[v1]] >= p[tree[v2]]){
		tree[v] = tree[v1];
	}else{
		tree[v] = tree[v2];
	}
}

int query(int v, int s, int e, int l, int r){
	if(l <= s && e <= r)return tree[v];
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query(v1, s, m, l, r);
	if(m < l)return query(v2, m + 1, e, l, r);
	int x1 = query(v1, s, m, l, r);
	int x2 = query(v2, m + 1, e, l, r);
	if(p[x1] >= p[x2])return x1;
	return x2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
	}
	memset(rem, 0, sizeof(rem));
	for(int i = 1; i <= q; i++){
		cin >> type[i] >> val[i];
		if(type[i] == 2)rem[val[i]] = 1;
	}
	memset(par, -1, sizeof(par));
	for(int i = 1; i <= m; i++){
		if(rem[i] == 0){
			combine(a[i], b[i]);
		}
	}
	for(int i = q; i >= 1; i--){
		if(type[i] == 2){
			if(combine(a[val[i]], b[val[i]])){
				rem[val[i]] = 2;
			}
		}else{
			val[i] = find(val[i]);
		}
	}
	ptr = 0;
	for(int i = 1; i <= n; i++){
		if(par[i] < 0){
			dfs(i);
		}
	}
	assert(ptr == n);
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		if(type[i] == 1){
			int u = query(1, 1, n, st[val[i]], en[val[i]]);
			cout << p[u] << '\n';
			update(1, 1, n, st[u]);
		}
	}

	return 0;
}