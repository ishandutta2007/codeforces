#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

namespace __gnu_pbds {
template <typename K, typename V=null_type>
using order_statistic_tree = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
}
using __gnu_pbds::order_statistic_tree;

// We negate k so that as k increases, things become more blue
// k >= r - b <=> blue

const int MAXN = 1.1e5;
int N;

vector<int> ch[MAXN];
int sz[MAXN];
int par[MAXN];

int preorder[MAXN];
int st[MAXN];
int en[MAXN];
// HLD top
int top[MAXN];

int curK;
int leafValue[MAXN];

const int INF = 1e9;
struct func {
	int a, b; // value is 0 on [-inf,a), x on [a,b), 1 on [b, +inf)
};
const func LEAF_FUNCS[2] = {{INF, INF}, {-INF, -INF}};

int coalesce(int v, int lo, int hi) {
	assert(lo <= hi);
	return min(max(v, lo), hi);
}
// a(b(x))
func compose(func a, func b) {
	return func{coalesce(b.a, a.a, a.b), coalesce(b.b, a.a, a.b)};
}

const int S = 1 << 17;
func segtree[2 * S];

// To find the first k which is blue:
// exists index i such that A[i] <= k and k >= (# > i) - (# <= i)
// k = min_i(max(A[i], # > i - # <= i))
order_statistic_tree<pair<int, int>> chTree[MAXN];
decltype(chTree[0].begin()) chIter[MAXN];

bool isBlue(int cur, int k, int extra) {
	int b = int(chTree[cur].order_of_key(pair<int, int>(k, INF)));
	int r = int(chTree[cur].size()) - b;
	return k >= extra + (r - b);
}
void fixBlueCutoff(int cur, int& k, int extra) {
	while (!isBlue(cur, k, extra)) k++;
	while (isBlue(cur, k-1, extra)) --k;
}
void fixFunc(int cur) {
	func& f = segtree[S+st[cur]];
	if (leafValue[cur] == -1) {
		assert(!ch[cur].empty());
		fixBlueCutoff(cur, f.a, -1);
		fixBlueCutoff(cur, f.b, +1);
		assert(f.a <= f.b);
	} else {
		assert(ch[cur].empty());
		f = LEAF_FUNCS[leafValue[cur]];
	}
	for (int a = (S+st[cur])/2; a; a /= 2) {
		segtree[a] = compose(segtree[2*a], segtree[2*a+1]);
	}
}

int queryVert(int cur) {
	int a = st[cur];
	assert(a < S);
	func ans = segtree[S+a];
	for (int l = S+a+1, r = S+S; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			ans = compose(ans, segtree[l]);
			l++;
		}
		assert((r & 1) == 0);
	}
	assert(ans.a == ans.b);
	return ans.a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> curK;
	curK *= -1;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		ch[u].push_back(v);
		ch[v].push_back(u);
	}
	for (int i = 0; i < N; i++) {
		cin >> leafValue[i];
	}

	{
		auto dfs_impl = [&](auto dfs, int cur, int prv) -> void {
			par[cur] = prv;
			if (prv != -1) {
				ch[cur].erase(find(ch[cur].begin(), ch[cur].end(), prv));
			}
			sz[cur] = 1;
			for (int nxt : ch[cur]) {
				dfs(dfs, nxt, cur);
				sz[cur] += sz[nxt];
			}
		};
		dfs_impl(dfs_impl, 0, -1);
	}

	{
		int curInd = 0;
		auto dfs2_impl = [&](auto dfs2, int cur, int curTop) -> void {
			preorder[curInd] = cur;
			st[cur] = curInd;
			top[cur] = curTop;

			curInd++;

			sort(ch[cur].begin(), ch[cur].end(), [&](int a, int b) { return sz[a] > sz[b]; });
			bool isFirst = true;
			for (int nxt : ch[cur]) {
				dfs2(dfs2, nxt, isFirst ? curTop : nxt);
				isFirst = false;
			}
			en[cur] = curInd;
			assert(en[cur] - st[cur] == sz[cur]);
		};
		dfs2_impl(dfs2_impl, 0, 0);
		assert(curInd == N);
	}

	for (int z = N-1; z >= 0; z--) {
		int v = preorder[z];
		fixFunc(v);
		if (v == top[v] && v != 0) {
			int p = par[v];
			chIter[v] = chTree[p].insert(pair<int, int>(queryVert(v), v)).first;
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int v; cin >> v; v--;

			if (curK >= queryVert(v)) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else if (op == 2) {
			int v; cin >> v; v--;
			cin >> leafValue[v];
			while (true) {
				fixFunc(v);
				v = top[v];
				if (v == 0) {
					break;
				}
				int p = par[v];
				chTree[p].erase(chIter[v]);
				chIter[v] = chTree[p].insert(pair<int, int>(queryVert(v), v)).first;
				v = p;
			}
		} else if (op == 3) {
			cin >> curK;
			curK *= -1;
		} else assert(false);
	}

	return 0;
}