#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int inf = 1e9;
const int M = (1 << 18);
pii tree1[M + M];
pii tree2[M + M];
int r[M];
int dis[M];

void update1(pii* tree, int u, pii p){
	tree[u += M] = p;
	for (u /= 2; u >= 1; u /= 2){
		tree1[u] = min(tree[u + u], tree[u + u + 1]);
	}
}

void update2(pii* tree, int u, pii p){
	tree[u += M] = p;
	for (u /= 2; u >= 1; u /= 2){
		tree[u] = max(tree[u + u], tree[u + u + 1]);
	}
}

pii query1(pii* tree, int a, int b){
	a += M;
	b += M;
	pii res = min(tree[a], tree[b]);
	while (a / 2 != b / 2){
		if (a % 2 == 0) res = min(res, tree[a + 1]);
		if (b % 2 == 1) res = min(res, tree[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

pii query2(pii* tree, int a, int b){
	a += M;
	b += M;
	pii res = max(tree[a], tree[b]);
	while (a / 2 != b / 2){
		if (a % 2 == 0) res = max(res, tree[a + 1]);
		if (b % 2 == 1) res = max(res, tree[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

void solve()
{
	int n;
	int A, B;

	scanf("%d%d%d", &n, &A, &B);

	rep(i, 1, n){
		scanf("%d", &r[i]);
		update1(tree1, i, {i - r[i], i});
		update2(tree2, i, {i + r[i], i});
	}

	queue <int> Q;
	
	rep(i, 1, n){
		dis[i] = inf;
	}

	dis[A] = 0;

	update1(tree1, A, {+inf, A});
	update2(tree2, A, {-inf, A});
	
	Q.push(A);

	while (!Q.empty()){
		int u = Q.front();
	//	dbg(u);
		Q.pop();
		while (true){
			pii res = query1(tree1, u, min(u + r[u], n));
			//dbg(res.f);
			//dbg(res.s);
			if (res.f > u) break;
			int v = res.s;
			//dbg(v);
			assert(dis[v] == 1e9);
			dis[v] = dis[u] + 1;
			update1(tree1, v, {+inf, v});
			update2(tree2, v, {-inf, v});
			Q.push(v);
		}
		while (true){
			pii res = query2(tree2, max(1, u - r[u]), u);
			if (res.f < u) break;
			int v = res.s;
			//dbg(v);
			assert(dis[v] == 1e9);
			dis[v] = dis[u] + 1;
			update1(tree1, v, {+inf, v});
			update2(tree2, v, {-inf, v});
			Q.push(v);
		}
	}

	rep(i, 1, n){
		update1(tree1, i, {+inf, i});
		update2(tree2, i, {-inf, i});
	}

	printf("%d\n", dis[B]);
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--){
		solve();
	}
	return 0;
}