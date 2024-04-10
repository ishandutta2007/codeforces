#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

inline bool initIt() {
	ios_base::sync_with_stdio(false);
	return true;
};
bool inited = initIt();

class MaxFenwick {
	private:
		int n;
		vector<int> v;
	public:
		inline void modify(int i, int delta) {
			for (; i < n; i |= i+1) {
				v[i] += delta;
			}
		}
		
		inline int max(int i) {
			int res = 0;
			for (; i >= 0; i &= i+1, i--) {
				res = std::max(res, v[i]);
			}
			return res;
		}
		
		MaxFenwick(int n)
			: n(n), v(n, 0) {
		}
};

class SegTree {
	private:
		int n;
		vector<int> t;
		vector<int> lazy;
	
		inline void push(int x, int l, int r) {
			if (lazy[x] >= 0) {
				t[x] = lazy[x] * (r - l + 1);
				if (l != r) {
					lazy[x*2] = lazy[x];
					lazy[x*2+1] = lazy[x];
				}
				lazy[x] = -1;
			}
		}
		
		inline int getItem(int x, int tl, int tr) {
			push(x, tl, tr);
			return t[x];
		}
		
		inline void recalc(int x, int tl, int tm, int tr) {
			t[x] = getItem(x*2, tl, tm) + getItem(x*2+1, tm+1, tr);
		}
		
		void update(int x, int tl, int tr, int l, int r, int val) {
			if (l > r) {
				return;
			}
			if (l == tl && r == tr) {
				lazy[x] = val;
			} else {
				push(x, tl, tr);
				int tm = (tl + tr) / 2;
				update(x*2, tl, tm, l, min(tm, r), val);
				update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
				recalc(x, tl, tm, tr);
			}
		}
		
		int query(int x, int tl, int tr, int l, int r) {
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return getItem(x, tl, tr);
			} else {
				push(x, tl, tr);
				int tm = (tl + tr) / 2;
				return query(x*2, tl, tm, l, min(tm, r)) + 
				       query(x*2+1, tm+1, tr, max(l, tm+1), r);			
			}
		}
	public:
		inline void update(int l, int r, int val) {
			update(1, 0, n-1, l, r, val);
		}
	
		inline int query(int l, int r) {
			return query(1, 0, n-1, l, r);
		}
		
		inline SegTree(int n)
			: n(n), t(4 * n, 0), lazy(4 * n, -1) {
		}
};

inline int getInt() {
	int n; cin >> n;
	return n;
}

inline vector< pair<int, int> > getVectorPairIntInt(int n) {
	vector< pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	return v;
}

int n = getInt();
vector< pair<int, int> > v = getVectorPairIntInt(n);
int m = getInt();
vector< pair<int, int> > q = getVectorPairIntInt(m);
vector< pair< pair<int, int>, int> > queries(m);
vector<int> ans(m);
vector<int> dp(n);
vector<int> new2old;
map<int, int> old2new;

inline void init() {
	for (int i = 0; i < m; i++) {
		queries[i] = {{q[i].first - 1, q[i].second - 1}, i};
	}
	sort(queries.begin(), queries.end());
	reverse(queries.begin(), queries.end());
	for (int i = 0; i < n; i++) {
		v[i].second += v[i].first;
	}
	vector<int> allCoord;
	for (int i = 0; i < n; i++) {
		allCoord.push_back(v[i].first);
		allCoord.push_back(v[i].second);
	}
	sort(allCoord.begin(), allCoord.end());
	new2old.push_back(allCoord[0]);
	for (int i = 1; i < (int)allCoord.size(); i++) {
		if (allCoord[i] > allCoord[i-1]) {
			new2old.push_back(allCoord[i]);
		}
	}
	for (int i = 0; i < (int)new2old.size(); i++) {
		old2new[new2old[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		v[i].first = old2new[v[i].first];
		v[i].second = old2new[v[i].second];
	}
}

inline void calcDP() {
	MaxFenwick f(n);
	for (int i = n-1; i >= 0; i--) {
		int l = 0, r = n-1;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (v[m].first > v[i].second) {
				r = m-1;
			} else {
				l = m;
			}
		}
		dp[i] = max(v[i].second, f.max(l));
		f.modify(i, dp[i]);
	}
}

inline void processQueries() {
	int cs = new2old.size() - 1;
	SegTree st(cs);
	for (int i = 0; i < cs; i++) {
		st.update(i, i, new2old[i+1] - new2old[i]);
	}
	int ptr = n-1;
	for (int i = 0; i < m; i++) {
		int l = queries[i].first.first, r = queries[i].first.second; 
		int id = queries[i].second;
		while (ptr >= l) {
			st.update(v[ptr].first, v[ptr].second - 1, 0);
			ptr--;
		}
		ans[id] = st.query(v[l].first, v[r].second - 1);
	}
}

int main() {
	init();
	calcDP();
	processQueries();
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}