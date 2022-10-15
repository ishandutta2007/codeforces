#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

struct Query {
	int cid1, cid2, qid;
	
	Query() {
	}
	
	Query(int cid1, int cid2, int qid)
		: cid1(cid1), cid2(cid2), qid(qid) {
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, q; cin >> n >> m >> q;
	vector< vector<int> > g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> dLow1(n), dLow2(n), dUp(n), d(n);
	vector< vector<int> > comps;
	vector< vector<int64_t> > lengths;
	vector< vector<int64_t> > lengthsSuf;
	vector<int> cRoots;
	vector<int> compId(n, -1);
	vector<int> diameter;
	
	function<void(int, int)> dfs1 = [&](int v, int p) {
		compId[v] = (int)comps.size() - 1;
		comps.back().push_back(v);
		dLow1[v] = dLow2[v] = 0;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			dfs1(to, v);
			dLow2[v] = max(dLow2[v], dLow1[to] + 1);
			if (dLow2[v] > dLow1[v]) {
				swap(dLow1[v], dLow2[v]);
			}
		}
	};
	
	function<void(int, int)> dfs2 = [&](int v, int p) {
		if (p < 0) {
			dUp[v] = 0;
			d[v] = dLow1[v];
		}
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			if (dLow1[v] != dLow1[to] + 1) {
				dUp[to] = max(dUp[v] + 1, dLow1[v] + 1);
			} else {
				dUp[to] = max(dUp[v] + 1, dLow2[v] + 1);
			}
			d[to] = max(dLow1[to], dUp[to]);
			dfs2(to, v);
		}
	};
	
	for (int i = 0; i < n; i++) {
		if (compId[i] < 0) {
			comps.emplace_back();
			cRoots.push_back(i);
			dfs1(i, -1);
			dfs2(i, -1);
			int dtr = 0;
			for (int v : comps.back()) {
				dtr = max(dtr, d[v]);
			}
			diameter.push_back(dtr);
			lengths.emplace_back();
			for (int v : comps.back()) {
				lengths.back().push_back(d[v]);
			}
			sort(lengths.back().begin(), lengths.back().end());
			lengthsSuf.emplace_back(lengths.back().size() + 1);
			for (int j = (int)lengths.back().size() - 1; j >= 0; j--) {
				lengthsSuf.back()[j] = lengths.back()[j] + lengthsSuf.back()[j+1];
			}
		}
	}
	int csz = (int)comps.size();
	
	vector<int64_t> ans(q);
	vector<Query> queries(q);
	vector< map<int, vector<Query> > > queriesByCid(csz);
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		Query q(compId[a], compId[b], i);
		if (comps[q.cid1].size() > comps[q.cid2].size()) {
			swap(q.cid1, q.cid2);
		}
		queries[i] = q;
		if (q.cid1 == q.cid2) {
			continue;
		}
		queriesByCid[q.cid1][q.cid2].push_back(q);
	}
	for (int from = 0; from < csz; from++) {
		vector< pair<int, int64_t> > places;
		for (auto &it : queriesByCid[from]) {
			places.emplace_back(it.first, 0);
		}
		for (int len : lengths[from]) {
			for (auto &place : places) {
				int to = place.first; 
				int64_t &placeAns = place.second;
				int maxD = max(diameter[from], diameter[to]);
				int beg = lower_bound(
					lengths[to].begin(),
					lengths[to].end(),
					maxD - 1 - len
				) - lengths[to].begin();
				int maxLen = (int)lengths[to].size();
				placeAns += (int64_t)maxD * beg + lengthsSuf[to][beg] + (int64_t)(maxLen - beg) * (len + 1);
			}
		}
		int ktr = 0;
		for (auto &it : queriesByCid[from]) {
			int64_t curRes = places[ktr++].second;
			for (Query &q : it.second) {
				ans[q.qid] = curRes;
			}
		}
	}
	
	vector<long double> theAns(q);
	for (int i = 0; i < q; i++) {
		if (queries[i].cid1 == queries[i].cid2) {
			theAns[i] = -1;
		} else {
			theAns[i] = (long double)ans[i] / comps[queries[i].cid1].size() / comps[queries[i].cid2].size();
		}
	}
	
	for (int i = 0; i < q; i++) {
		cout << fixed << setprecision(10) << theAns[i] << "\n";
	}
	return 0;
}