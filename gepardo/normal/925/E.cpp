#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cassert>

using namespace std;

struct Query {
	int idx, mode;
};

template<typename T>
class SparseTable {
private:
	int n;
	vector<int> lg;
	vector< vector<T> > st;
public:
	inline T query(int l, int r) {
		int w = lg[r-l+1];
		return min(st[w][l], st[w][r - (1 << w) + 1]);
	}
	
	SparseTable(vector<T> v)
		: n(v.size()), lg(v.size()+1), st(20, vector<T>(n)) {
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i >> 1] + 1;
		}
		st[0] = v;
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
			}
		}
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> p(n, -1), t(n);
	vector<Query> q(m);
	vector< vector<int> > g(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i]; p[i]--;
		g[p[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < m; i++) {
		int val; cin >> val;
		if (val < 0) {
			q[i].mode = 1;
			val *= -1;
		} else {
			q[i].mode = 0;
		}
		q[i].idx = val-1;
	}
	vector< pair<int, int> > euler;
	vector<int> el(n), er(n);
	
	function<void(int, int)> dfs = [&](int v, int d) {
		el[v] = er[v] = euler.size();
		euler.emplace_back(d, v);
		for (int to: g[v]) {
			dfs(to, d+1);
			er[v] = euler.size();
			euler.emplace_back(d, v);
		}
	};
	dfs(0, 0);
	
	const int block = 818;
	vector<int> ans(m);
	vector<char> active(n, true);
	SparseTable< pair<int, int> > st(euler);
	
	for (int lp = 0; lp < m; lp += block) {
		int rp = min(m, lp + block);
		vector<char> good(n, false);
		vector<int> vals;
		for (int i = lp; i < rp; i++) {
			good[q[i].idx] = true;
			vals.push_back(q[i].idx);
		}
		good[0] = true;
		sort(vals.begin(), vals.end(), [&](int x, int y) {
			return el[x] < el[y];
		});
		for (int i = 1; i < (int)vals.size(); i++) {
			auto res = st.query(el[vals[i-1]], el[vals[i]]);
			good[res.second] = true;
		}
		vector<int> goods;
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				goods.push_back(i);
			}
		}
		vector<int> holidaySub(n);
		vector<int> balance(n);
		int theAns = 0;
		
		function<void(int)> dfs = [&](int v) {
			holidaySub[v] = !active[v];
			for (int to: g[v]) {
				dfs(to);
				holidaySub[v] += holidaySub[to];
			}
			balance[v] = t[v] - holidaySub[v];
			if (balance[v] < 0 && active[v]) {
				theAns++;
			}
		};
		
		dfs(0);
		int curAns = 0;
		vector<int> up(n, -1);
		vector< vector< pair<int, int> > > block(n);
		vector< vector<int> > byBlock(2*n+1);
		vector<int> iter(n, 0);
		vector<int> delta(n, 0);
		vector<char> nActive(n, true);
		for (int i = 0; i < n; i++) {
			if (!good[i]) {
				continue;
			}
			int v = i;
			block[v].emplace_back(balance[v], 1);
			up[v] = p[v];
			nActive[v] = active[v];
			v = p[v];
			if (v < 0 || good[v]) {
				continue;
			}
			int qv = v;
			while (v >= 0 && !good[v]) {
				if (active[v]) {
					byBlock[n + balance[v]].push_back(qv);
				}
				v = p[v];
			}
			up[qv] = v;
		}
		for (int i = 0; i <= 2*n; i++) {
			int val = i - n;
			for (int j: byBlock[i]) {
				if (!block[j].empty() && block[j].back().first == val) {
					block[j].back().second++;
				} else {
					block[j].emplace_back(val, 1);
				}
			}
		}
		
		auto update = [&](int bid) {
			while (iter[bid] > 0 && block[bid][iter[bid] - 1].first >= delta[bid]) {
				iter[bid]--;
				if (nActive[bid]) {
					curAns -= block[bid][iter[bid]].second;
				}
			}
			while (iter[bid] < (int)block[bid].size() && block[bid][iter[bid]].first < delta[bid]) {
				if (nActive[bid]) {
					curAns += block[bid][iter[bid]].second;
				}
				iter[bid]++;
			}
		};
		
		for (int i = 0; i < n; i++) {
			update(i);
		}
		curAns = theAns;
		for (int i = lp; i < rp; i++) {
			int add = q[i].mode ? -1 : +1;
			int v = q[i].idx;
			curAns -= add * (block[v][0].first < delta[v]);
			nActive[v] = active[v] = q[i].mode;
			while (v >= 0) {
				delta[v] += add;
				update(v);
				v = up[v];
			}
			ans[i] = curAns;
		}
	}
	
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}