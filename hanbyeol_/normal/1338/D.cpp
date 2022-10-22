#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N; cin >> N;
	vector<vector<int>> conn(N);
	for(int i=0; i<N-1; ++i)
	{
		int u, v; cin >> u >> v; --u; --v;
		conn[u].push_back(v); conn[v].push_back(u);
	}
	map<pair<int, int>, pair<int, int>> M;
	vector<multiset<int>> coS(N), enS(N); vector<int> nf(N, -2);
	// nf=-2, no value calced, nf = -1, all value calced, nf = i, all calced except i
	function<pair<int,int>(int,int)> dfs = [&](int a, int p)
	{
		auto it = M.find({a, p});
		if(it != M.end()) return it->second;

		int child = (int)conn[a].size(); if(p != -1) --child;

		// consider no value case, run plain dp
		if(nf[a] == -2)
		{
			nf[a] = p; // we calculate every value except p
			for(auto x: conn[a]) if(x != p)
			{
				auto [cc, ce] = dfs(x, a);
				coS[a].insert(cc); enS[a].insert(ce);
			}
			int me = 1, mc = 0;
			if(!enS[a].empty()) me = max(me, *enS[a].rbegin());
			if(!coS[a].empty()) mc = max(mc, *coS[a].rbegin());
			int co = child - 1 + max(mc, me), en = 1 + mc;
			// cout << a + 1 << " " << p + 1 << " " << co << " " << en << endl;
			return M[{a, p}] = {co, en};
		}

		// if something is not filled, we will fill it.
		if(nf[a] != -1)
		{
			auto [cc, ce] = dfs(nf[a], a);
			coS[a].insert(cc); enS[a].insert(ce);
			nf[a] = -1;
		}

		int cc = -1, ce = -1;
		if(p != -1)
		{
			//pull already calculated value;
			tie(cc, ce) = dfs(p, a);
			coS[a].erase(coS[a].find(cc));
			enS[a].erase(enS[a].find(ce));
		}
		int me = 1, mc = 0;
		if(!enS[a].empty()) me = max(me, *enS[a].rbegin());
		if(!coS[a].empty()) mc = max(mc, *coS[a].rbegin());

		int co = child - 1 + max(mc, me), en = 1 + mc;
		// cout << a + 1 << " " << p + 1 << " " << co << " " << en << endl;
			
		if(p != -1)
		{
			coS[a].insert(cc);
			enS[a].insert(ce);
		}

		return M[{a, p}] = {co, en};
	};
	int ans = 0;
	for(int i=0; i<N; ++i) ans = max({ans, dfs(i, -1).first, dfs(i, -1).second});
	cout << ans << endl;

}