#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
vector<int> ch[MAXN];
int sz[MAXN];
pair<pair<int, int>, ll> D[MAXN];

int st[MAXN];
int en[MAXN];
int heavyRoot[MAXN];
int heavyLeaf[MAXN];

void dfs(int cur) {
	heavyLeaf[heavyRoot[cur]] = cur;
	en[cur] = st[cur] + 1;
	for (int nxt : ch[cur]) {
		st[nxt] = en[cur];
		heavyRoot[nxt] = (st[nxt] == st[cur] + 1) ? heavyRoot[cur] : nxt;
		dfs(nxt);
		en[cur] = en[nxt];
	}
}

const int S = (1 << 17);
struct node_t {
	ll constVal = 0;
	ll addVal = 0;

	ll operator () (ll v = 0) const {
		return max(constVal, addVal + v);
	}
};

node_t operator + (const node_t& a, const node_t& b) {
	node_t res;
	res.constVal = max(a.constVal, a.addVal + b.constVal);
	res.addVal = a.addVal + b.addVal;
	return res;
}

node_t seg[S*2];
node_t query_seg(int l, int r) {
	node_t lans;
	node_t rans;
	for (int a = l+S, b = r+S; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			lans = lans + seg[a];
			a++;
		}
		if (b & 1) {
			--b;
			rans = seg[b] + rans;
		}
	}
	node_t ans = lans + rans;
	return ans;
}

ll query_vert(int v) {
	int rt = heavyRoot[v];
	int lf = heavyLeaf[rt];
	assert(ch[lf].empty());
	return query_seg(st[v], st[lf] + 1)();
}

void update_seg(int i) {
	for (int a = (i+S)/2; a; a /= 2) {
		seg[a] = seg[2*a] + seg[2*a+1];
	}
}

void update_vert_add(int v, ll delta) {
	//cerr << "add " << v << ' ' << delta << '\n';
	int rt = heavyRoot[v];
	ll oldVal = query_vert(rt);
	// do change
	seg[st[v]+S].addVal += delta;
	update_seg(st[v]);
	ll newVal = query_vert(rt);
	//cerr << rt << ' ' << oldVal << "->" << newVal << '\n';
	if (P[rt]) {
		update_vert_add(P[rt], newVal - oldVal);
	}
}

void update_vert_const(int v, ll val) {
	//cerr << "const " << v << ' ' << val << '\n';
	int rt = heavyRoot[v];
	ll oldVal = query_vert(rt);
	// do change
	seg[st[v]+S].constVal = max(seg[st[v]+S].constVal, val);
	update_seg(st[v]);
	ll newVal = query_vert(rt);
	//cerr << rt << ' ' << oldVal << "->" << newVal << '\n';
	if (P[rt]) {
		update_vert_add(P[rt], newVal - oldVal);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int M; int K;
	cin >> N >> M >> K;
	P[1] = 0;
	for (int i = 2; i <= N; i++) {
		cin >> P[i];
		ch[P[i]].push_back(i);
	}

	for (int e = 0; e < M; e++) {
		int v, d; ll w; cin >> v >> d >> w;
		D[e] = {{-d, v}, w};
	}
	sort(D, D + M);

	for (int v = N; v >= 1; v--) {
		sz[v] ++;
		if (P[v]) sz[P[v]] += sz[v];
	}
	assert(sz[1] == N);

	for (int v = 1; v <= N; v++) {
		sort(ch[v].begin(), ch[v].end(), [&](int i, int j) -> bool { return sz[i] > sz[j]; });
	}
	st[1] = 0;
	heavyRoot[1] = 1;
	dfs(1);
	for (int v = 1; v <= N; v++) {
		assert(en[v] - st[v] == sz[v]);
		//cerr << v << ' ' << st[v] << ' ' << en[v] << ' ' << heavyRoot[v] << ' ' << heavyLeaf[v] << '\n';
	}

	for (int e = M-1; e >= 0; e--) {
		int v = D[e].first.second; ll w = D[e].second;
		// update this thing
		update_vert_const(v, query_vert(v) + w);
	}
	cout << query_vert(1) << '\n';

	return 0;
}