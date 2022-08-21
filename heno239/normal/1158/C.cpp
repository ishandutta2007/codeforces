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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

struct Segraph {
private:
	vector<vector<int>> G;
	int sz;
	vector<int> num;
	int ori;
	int cur;
public:
	Segraph(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		G.resize(2 * sz - 1);
		num.resize(2 * sz - 1, 0);
		cur = n; ori = n;
		rep(i, sz - 1) {
			G[i].push_back(2 * i + 1); num[2 * i + 1]++;
			G[i].push_back(2 * i + 2); num[2 * i + 2]++;
		}
	}
	void add_edge(int a, int b) {
		G[a + sz - 1].push_back(b + sz - 1);
		num[b + sz - 1]++;
	}
	void add_edge(int x,int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return;
		else if (a <= l && r <= b) {
			G[x + sz - 1].push_back(k); num[k]++;
		}
		else {
			add_edge(x,a, b, k * 2 + 1, l, (l + r) / 2);
			add_edge(x,a, b, k * 2 + 2, (l + r) / 2, r);
		}
	}
	vector<int> query() {
		vector<int> ans(ori,-mod);
		queue<int> q;
		rep(i, 2*sz-1) {
			if (num[i] == 0) {
				q.push(i); num[i]--;
			}
		}
		while (!q.empty()) {
			int id = q.front(); q.pop();
			if (id >= sz - 1&&id<sz-1+ori) {
				ans[id-sz+1] = cur; cur--;
			}
			rep(j, G[id].size()) {
				int to = G[id][j];
				num[to]--;
				if (num[to] == 0) {
					q.push(to); num[to]--;
				}
			}
		}
		return ans;
	}
};
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	//vector<int> c(n + 1);
	vector<vector<int>> G(n);
	vector<int> r(n);

	Segraph st(n);
	rep(i, n) {
		if (p[i] >= 0) {
			//c[i]++; c[p[i] - 1]--;
			st.add_edge(i, i + 1, p[i]);
			if (p[i] < n) {
				st.add_edge(p[i], i);
				//G[p[i]].push_back(i); r[i]++;
			}
		}
	}
	/*int tmp = 0;
	rep(i, n-1) {
		tmp += c[i];
		if (tmp > 0) {
			G[i].push_back(i + 1); r[i + 1]++;
		}
	}*/
	//vector<int> ans(n, -mod);
	vector<int> ans = st.query();
	bool f = true;
	rep(i, n) {
		if (ans[i] == -mod)f = false;
	}
	//cout << "ans is" << endl;
	if (f) {
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
	return 0;
}