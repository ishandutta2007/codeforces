#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

inline pair<int, int> mp(int x, int y) {
	return {min(x, y), max(x, y)};
}

void mark_sizes(const vector<vector<int>>& ed, const vector<int>& edges, const vector<char>& forb, vector<int>& size, int v, int pr = -1) {
	size[v] = 1;
	for (int ed_num : ed[v]) {
		if (forb[ed_num]) {
			continue;
		}
		int x = edges[ed_num] - v;
		if (x == pr) {
			continue;
		}
		mark_sizes(ed, edges, forb, size, x, v);
		size[v] += size[x];
	}
}

int find_centroid(const vector<vector<int>>& ed, const vector<int>& edges, const vector<char>& forb, const vector<int>& size, int total, int v, int pr = -1) {
	int thres = (total + 1) / 2;
	for (int ed_num : ed[v]) {
		if (forb[ed_num]) {
			continue;
		}
		int x = edges[ed_num] - v;
		if (x == pr) {
			continue;
		}
		if (size[x] >= thres) {
			return find_centroid(ed, edges, forb, size, total, x, v);
		}
	}
	return v;
}

vector<int> get_neigs(const vector<vector<int>>& ed, const vector<int>& edges, vector<char>& forb, int v) {
	vector<int> res;
	for (int ed_num : ed[v]) {
		if (forb[ed_num]) {
			continue;
		}
		int x = edges[ed_num] - v;
		forb[ed_num] = 1;
		res.push_back(x);
	}
	return res;
}

int main(){
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].push_back((i + 1) % n);
		a[i].push_back((i + n - 1) % n);
	}

	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> ends(n);
	for (int i = 0; i < n; ++i) {
		for (int &x : a[i]) {
			if (x < i) {
				x += n;
			}
		}
		sort(all(a[i]));
		ends[i] = lower_bound(all(a[i]), n) - a[i].begin();
		for (int &x : a[i]) {
			if (x >= n) {
				x -= n;
			}
		}
	}

	vector<vector<int>> rgns;
	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size() - 1; ++j) {
			if (S.find({i, a[i][j]}) != S.end()) {
				continue;
			}
			rgns.push_back({});
			int cur = i;
			int index = j;
			do {
				rgns.back().push_back(cur);
				int old = cur;
				cur = a[cur][index];
				S.insert({old, cur});
				if (old > cur) {
					index = lower_bound(a[cur].begin(), a[cur].begin() + ends[cur], old) - a[cur].begin();
				} else {
					index = lower_bound(a[cur].begin() + ends[cur], a[cur].end(), old) - a[cur].begin();
				}
				--index;
				assert(index >= 0);
			} while (cur != i);
		}
	}

	int cnt = rgns.size();
	vector<vector<int>> ed(cnt);
	map<pair<int, int>, int> lst;
	vector<int> edges;
	for (int i = 0; i < cnt; ++i) {
		int ls = rgns[i].back();
		for (int x : rgns[i]) {
			auto p = mp(x, ls);
			if (abs(ls - x) > 1 && abs(ls - x) < n - 1) {
				if (lst.count(p)) {
					int j = lst[p];
					ed[i].push_back(edges.size());
					ed[j].push_back(edges.size());
					edges.push_back(i + j);
				} else {
					lst[p] = i;
				}
			}
			ls = x;
		}
	}

	int edges_cnt = edges.size();
	vector<char> forb(edges_cnt);
	vector<int> color(cnt);
	vector<int> size(cnt);
	vector<char> used(cnt);
	vector<int> roots = {0};
	int curcolor = 1;
	while (!roots.empty()) {
		vector<int> new_roots;
		for (int root : roots) {
			mark_sizes(ed, edges, forb, size, root);
			int centroid = find_centroid(ed, edges, forb, size, size[root], root);
			color[centroid] = curcolor;
			auto neigs = get_neigs(ed, edges, forb, centroid);
			new_roots.insert(new_roots.end(), all(neigs));
		}
		roots.swap(new_roots);
		++curcolor;
	}

	vector<pair<vector<int>, int>> regions(cnt);
	for (int i = 0; i < cnt; ++i) {
		regions[i] = {rgns[i], i};
		sort(all(regions[i].first));
		reverse(all(regions[i].first));
	}

	sort(all(regions));
	for (int i = 0; i < cnt; ++i) {
		printf("%d ", color[regions[i].second]);
	}
	printf("\n");

	return 0;
}