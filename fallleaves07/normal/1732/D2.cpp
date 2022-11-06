#include<bits/stdc++.h>
using namespace std;
using LL = long long;
//test after hack

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	set<LL> all;
	struct Mexk {
		set<int> mex;
		int mxa, id;
		LL k;
		Mexk(LL k, int id) {
			this->k = k, this->id = id;
			mxa = 0;
		}
		void init(LL k, int ans) {
			this->k = k;
			mxa = ans;
			for (int i = 1; i <= ans; i++) {
				mex.insert(i);
			}
		}
		void insert(LL val) {
			int v = val / k;
			if (v <= mxa) {
				mex.erase(v);
			}
		}
		void erase(LL val) {
			int v = val / k;
			if (v <= mxa) {
				mex.insert(v);
			}
		}
		LL query(set<LL> &all, map<LL, vector<int>> &bind) {
			while (mex.empty()) {
				++mxa;
				bind[k * mxa].emplace_back(id);
				if (!all.count(mxa * k)) {
					mex.insert(mxa);
				}
			}
			return *mex.begin() * k;
		}
	};
	vector<Mexk> mex;
	map<LL, vector<int>> bind;
	map<LL, int> idop;
	for (int i = 0; i < n; i++) {
		string s;
		LL v;
		cin >> s >> v;
		if (s[0] == '?') {
			if (!idop.count(v)) {
				idop[v] = mex.size();
				mex.emplace_back(v, mex.size());
			}
			printf("%lld\n", mex[idop[v]].query(all, bind));
		} else if (s[0] == '+') {
			all.insert(v);
			for (auto j : bind[v]) {
				mex[j].insert(v);
			}
		} else if (s[0] == '-') {
			all.erase(v);
			for (auto j : bind[v]) {
				mex[j].erase(v);
			}
		}
	}
    return 0;
}