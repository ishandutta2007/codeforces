#include<bits/stdc++.h>
using namespace std;

// we'll build up a spanning forrest, then find some collision

void printVector(char c, const vector<int>& v) {
	printf("%c %d\n", c, int(v.size()));
	for (int i = 0; i < int(v.size()); i++) {
		printf("%d%c", v[i], " \n"[i == int(v.size())-1]);
	}
	fflush(stdout);
}
map<vector<int>, int> mp;
int query(vector<int> v) {
	if (v.size() <= 1) return 0;
	sort(v.begin(), v.end());
	if (mp.count(v)) return mp[v];
	printVector('?', v);
	int r; (void) scanf("%d", &r);
	if (r == -1) exit(0);
	return mp[v] = r;
}

// find a node where extra connects to base
int findConnection(const vector<int>& base, int baseE, const vector<int>& extra, bool checkExists) {
	vector<int> q;
	if (checkExists) {
		q = extra;
		int extraE = query(q);
		q.insert(q.end(), base.begin(), base.end());
		int totE = query(q);
		assert(totE >= baseE + extraE);
		if (totE == baseE + extraE) return false;
	}

	int l = 0, r = int(extra.size());
	while (r - l > 1) {
		int m = (l + r) / 2;
		q.clear();
		q.insert(q.end(), extra.begin() + l, extra.begin() + m);
		int extraE = query(q);
		q.insert(q.end(), base.begin(), base.end());
		int totE = query(q);
		assert(totE >= baseE + extraE);
		if (totE == baseE + extraE) {
			// nothing on this side
			l = m;
		} else {
			r = m;
		}
	}
	return extra[l];
}

const int MAXN = 700;
int N;
// 0 is not visited, -1 is a root
int par[MAXN];
bool side[MAXN];

void build(int root) {
	assert(par[root] == 0);
	par[root] = -1;
	side[root] = false;

	int numE = 0;
	vector<int> curTree;
	curTree.push_back(root);

	vector<int> halfTree[2];
	halfTree[side[root]].push_back(root);

	while (true) {
		vector<int> cnd;
		for (int i = 1; i <= N; i++) {
			if (par[i] == 0) cnd.push_back(i);
		}
		int nxt = findConnection(curTree, numE, cnd, true);
		if (!nxt) return;
		vector<int> tmp;
		tmp.push_back(nxt);

		int prv = findConnection(tmp, 0, curTree, false);
		assert(prv);
		par[nxt] = prv;
		side[nxt] = !side[prv];

		int bad = findConnection(tmp, 0, halfTree[side[nxt]], true);
		if (bad) {
			assert(prv != bad);
			// nxt is connected to both prv and bad, so let's find their common ancestor
			vector<int> pprv, pbad;
			for (int cur = prv; cur != -1; cur = par[cur]) {
				pprv.push_back(cur);
			}
			for (int cur = bad; cur != -1; cur = par[cur]) {
				pbad.push_back(cur);
			}
			int lca = -1;
			assert(pprv.back() == root);
			assert(pbad.back() == root);
			while (!pprv.empty() && !pbad.empty() && pprv.back() == pbad.back()) {
				lca = pprv.back();
				pprv.pop_back();
				pbad.pop_back();
			}
			assert(lca != -1);
			vector<int> s;
			s.push_back(nxt);
			s.insert(s.end(), pprv.begin(), pprv.end());
			s.push_back(lca);
			s.insert(s.end(), pbad.rbegin(), pbad.rend());

			printVector('N', s);
			exit(0);
		}

		halfTree[side[nxt]].push_back(nxt);
		curTree.push_back(nxt);
		numE = query(curTree);

	}
}

int main() {
	(void) scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			build(i);
		}
	}
	vector<int> s;
	for (int i = 1; i <= N; i++) {
		if (side[i]) {
			s.push_back(i);
		}
	}
	printVector('Y', s);

	return 0;
}