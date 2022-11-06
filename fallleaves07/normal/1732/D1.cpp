#include<bits/stdc++.h>
using namespace std;
using LL = long long;
//test after hack

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<string, LL>> op(n);
	set<LL> all;
	for (auto &[s, v] : op) {
		cin >> s >> v;
		if (s[0] == '+') {
			all.insert(v);
		}
	}
	vector<int> id(n);
	struct Mexk {
		set<int> mex;
		vector<int> mxc;
		LL k;
		void init(LL k, int ans) {
			this->k = k;
			mxc.resize(ans + 1);
			for (int i = 1; i <= ans; i++) {
				mex.insert(i), mxc[i] = 0;
			}
		}
		void insert(LL val) {
			int v = val / k;
			if (v < (int)mxc.size()) {
				if ((++mxc[v]) == 1) {
					mex.erase(v);
				}
			}
		}
		void erase(LL val) {
			int v = val / k;
			if (v < (int)mxc.size()) {
				if (!(--mxc[v])) {
					mex.insert(v);
				}
			}
		}
		LL query() {
			return *mex.begin() * k;
		}
	};
	vector<Mexk> mex;
	map<LL, vector<int>> bind;
	{
		map<LL, int> idop;
		for (int i = 0; i < n; i++) {
			if (op[i].first[0] == '?') {
				if (!idop.count(op[i].second)) {
					idop[op[i].second] = mex.size();
					int lst = 1;
					while (all.count(op[i].second * lst)) {
						bind[op[i].second * lst].emplace_back(mex.size());
						++lst;
					}
					mex.emplace_back();
					mex.back().init(op[i].second, lst);
				}
				id[i] = idop[op[i].second];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (op[i].first[0] == '?') {
			printf("%lld\n", mex[id[i]].query());
		} else if (op[i].first[0] == '+') {
			for (auto j : bind[op[i].second]) {
				mex[j].insert(op[i].second);
			}
		} else if (op[i].first[0] == '-') {
			for (auto j : bind[op[i].second]) {
				mex[j].erase(op[i].second);
			}
		}
	}
    return 0;
}