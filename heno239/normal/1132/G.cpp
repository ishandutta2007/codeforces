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
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct SegT {
private:
	int n; vector<int> node, lazy;
	const int init_c = 0;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void del(int k) {
	    add(-mod, k, k + 1);
	}
};

vector<int> G[1 << 20];

int trans[1 << 20];
int ri[1 << 20];
int cur = 0;
void dfs(int id, int fr) {
	trans[id] = cur; cur++;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs(to, id);
	}
	ri[trans[id]] = cur;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<int> nex(n);
	stack<P> st;
	rep(i, n) {
		while (!st.empty()) {
			P p = st.top();
			if (p.first < a[i]) {
				st.pop();
				nex[p.second] = i;
			}
			else {
				break;
			}
		}
		st.push({ a[i],i });
	}
	while (!st.empty()) {
		int id = st.top().second; st.pop();
		nex[id] = n;
	}
	rep(i, n) {
		G[nex[i]].push_back(i);
	}
	dfs(n, -1);
	SegT sg(n + 1);
	rep(i, k) {
		int id = trans[i];
		sg.add(1, id, ri[id]);
	}
	int ans = sg.query(0, n + 1);
	cout << ans;
	for(int i = k; i < n; i++) {
		int id = trans[i];
		int lid = trans[i - k];
		sg.add(1, id, ri[id]);
		sg.del(lid);
		ans = sg.query(0, n + 1);
		cout << " " << ans;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}