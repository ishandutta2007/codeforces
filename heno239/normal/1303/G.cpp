#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct LiChaoTree {
	int sz;
	struct Node {
		int l, r;
		Node* chl; Node* chr;
		LP val;
		Node(int l, int r) :l(l), r(r) {
			val = { 0,INF };
			chl = chr = NULL;
		}
	};
	Node* root;
	LiChaoTree() {
		int max_n = 1<<18;
		sz = 1;
		while (sz < max_n)sz <<= 1;
		root = new Node(0, sz);
	}
	ll calc(LP a, int x) {
		return a.first*x + a.second;
	}
	void add(Node* node, LP a) {
		if (!node)return;
		int l = node->l, r = node->r;
		int m = (l + r) / 2;
		//
		if (calc(node->val, m) > calc(a, m))swap(node->val, a);
		if (r - l == 1)return;
		//
		if (calc(node->val, l) > calc(a, l)) {
			if (!node->chl)node->chl = new Node(l, m);
			add(node->chl, a);
		}
		else if (calc(node->val, r) > calc(a, r)) {
			if (!node->chr)node->chr = new Node(m, r);
			add(node->chr, a);
		}
	}
	void add(LP a) {
		add(root, a);
	}
	ll query(int x) {
		ll ret = INF;
		Node* node = root;
		while (node) {
			ret = min(ret, calc(node->val, x));
			int m = (node->l + node->r) / 2;
			if (x < m) {
				node = node->chl;
			}
			else {
				node = node->chr;
			}
		}
		return ret;
	}
};

ll a[1 << 18];
vector<int> G[1 << 18];

queue<vector<int>> q;
bool exi[1 << 18];

int depth[1 << 18];
ll c[1 << 18];
ll sum[1 << 18];
ll rsum[1 << 18];
ll ans = 0;
void yaru(vector<int> v) {
	if (v.empty())return;
	for (int id : v)exi[id] = true;
	int g; int sz = v.size();
	
	function<int(int, int)> s_root = [&](int id, int fr)->int {
		int res = 1;
		int ma = 0;
		for (int to : G[id]) {
			if (to == fr)continue;
			if (!exi[to])continue;
			int nex = s_root(to, id);
			ma = max(ma, nex);
			res += nex;
		}
		if (ma <= sz / 2 && sz - res <= sz / 2)g = id;
		return res;
	};
	s_root(v[0], -1);
	//cout << "? " << g << endl;
	depth[g] = 0;
	c[g] = a[g];
	sum[g] = c[g];
	rsum[g] = 0;
	function<void(int, int)> upd = [&](int id, int fr) {
		if (!exi[id])return;
		depth[id] = depth[fr] + 1;
		c[id] = c[fr] + a[id];
		sum[id] = sum[fr] + a[id] * (depth[id] + 1);
		rsum[id] = rsum[fr] + (c[id] - a[g]);
		for (int to : G[id]) {
			if (to == fr)continue;
			upd(to, id);
		}
	};
	for (int to : G[g])upd(to, g);
	//cout << sum[2] << endl;
	vector<vector<int>> chs;

	vector<int> nexs;
	function<void(int, int)> search_next = [&](int id, int fr) {
		if (!exi[id])return;
		nexs.push_back(id);
		for (int to : G[id]) {
			if (to == fr)continue;
			search_next(to, id);
		}
	};
	for (int to : G[g]) {
		search_next(to, g);
		if (nexs.empty())continue;
		q.push(nexs);
		chs.push_back(nexs);
		nexs.clear();
	}

	LiChaoTree lt1,lt2;
	rep(i, chs.size()) {
		if (i > 0) {
			for (int id : chs[i]) {
				ll sum = rsum[id] - lt1.query(depth[id]);
				ans = max(ans, sum);
			}
		}
		for (int id : chs[i]) {
			lt1.add({ -c[id],-sum[id] });
		}
	}
	per(i, (int)chs.size()) {
		if (i+1<(int)chs.size()) {
			for (int id : chs[i]) {
				ll sum = rsum[id] - lt2.query(depth[id]);
				ans = max(ans, sum);
			}
		}
		for (int id : chs[i]) {
			lt2.add({ -c[id],-sum[id] });
		}
	}



	for (int id : v)exi[id] = false;
}


void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, n)cin >> a[i];
	vector<int> ori(n); rep(i, n)ori[i] = i;
	q.push(ori);
	while (!q.empty()) {
		vector<int> v = q.front(); q.pop();
		yaru(v);
	}
	cout << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}