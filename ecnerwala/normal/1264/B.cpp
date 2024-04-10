#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct V {
	vector<pii> outs; // (dest, edge index)
	int nins = 0;
};

vi euler_walk(vector<V>& nodes, int nedges, int src=0) {
	int c = 0;
	trav(n, nodes) c += abs(n.nins - sz(n.outs));
	if (c > 2) return {};
	vector<vector<pii>::iterator> its;
	trav(n, nodes)
		its.push_back(n.outs.begin());
	vector<bool> eu(nedges);
	vi ret, s = {src};
	while(!s.empty()) {
		int x = s.back();
		auto& it = its[x], end = nodes[x].outs.end();
		while(it != end && eu[it->second]) ++it;
		if(it == end) { ret.push_back(x); s.pop_back(); }
		else { s.push_back(it->first); eu[it->second] = true; }
	}
	if(sz(ret) != nedges+1)
		ret.clear(); // No Eulerian cycles/paths.
	// else, non-cycle if ret.front() != ret.back()
	reverse(all(ret));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int A, B, C, D; cin >> A >> B >> C >> D;
	for (int s = 0; s < 4; s++) {
		for (int t = s; t < 4; t++) {
			vector<V> nodes(5);
			vector<int> ans;
			int numE[5] = {2 * A, 2 * B, 2 * C, 2 * D, 2};
			int edgeInd = 0;
			auto addEdge = [&](int a, int b) {
				numE[a]--; numE[b]--;
				nodes[a].outs.push_back({b, edgeInd});
				nodes[a].nins++;
				nodes[b].outs.push_back({a, edgeInd});
				nodes[b].nins++;
				edgeInd++;
			};
			if (!numE[s]) goto is_bad;
			addEdge(s, 4);
			if (!numE[t]) goto is_bad;
			addEdge(t, 4);

			for (int i = 0; i+1 < 4; i++) {
				if (numE[i] > numE[i+1]) {
					goto is_bad;
				}
				while (numE[i] > 0) {
					addEdge(i, i+1);
				}
			}
			if (numE[3]) goto is_bad;
			ans = euler_walk(nodes, edgeInd, 4);
			if (ans.empty()) goto is_bad;
			assert(ans.front() == 4);
			assert(ans.back() == 4);
			cout << "YES" << '\n';
			for (int i = 1; i < int(ans.size())-1; i++) {
				cout << ans[i] << " \n"[i+1==int(ans.size())-1];
			}
			exit(0);
is_bad:;
		}
	}
	cout << "NO" << '\n';

	return 0;
}