#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

inline vector<int> piFunc(const string &s) {
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j != 0 && s[i] != s[j]) {
			j = pi[j-1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

int main() {
	string s; cin >> s;
	int m = s.size();
	
	const int block = 30;
	int k; cin >> k;
	vector< pair<int, string> > v(k);
	vector<int> ans(k, -42);
	vector< vector< pair<int, int> > > byBlock(block);
	
	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
		int sz = v[i].second.size();
		if (sz < block) {
			byBlock[sz].emplace_back(i, s.size() + 1);
			s += '#' + v[i].second;
		} else {
			string q = v[i].second + '#' + s;
			auto pi = piFunc(q);
			vector<int> pos;
			for (int j = 0; j < m; j++) {
				if (pi[j + sz + 1] == sz) {
					pos.push_back(j);
				}
			}
			if (v[i].first > (int)pos.size()) {
				ans[i] = -1;
			} else {
				ans[i] = 1234567890;
				for (int j = v[i].first - 1; j < (int)pos.size(); j++) {
					ans[i] = min(ans[i], pos[j] - pos[j - v[i].first + 1] + sz);
				}
			}
		}
	}
	
	int n = s.size();
	vector<int> ord(n);
	vector<int> bucket(n+1);
	iota(ord.begin(), ord.end(), 1);
	for (int i = 1; i < block; i++) {
		vector< vector<int> > byL(128);
		for (int j: ord) {
			if (j != 0) {
				byL[(int)s[j-1]].push_back(j-1);
			}
		}
		vector<int> nOrd;
		for (auto &it: byL) {
			nOrd.insert(nOrd.end(), it.begin(), it.end());
		}
		int bs = 0;
		vector<int> nBuck(n, -1);
		vector< vector<int> > byBucket;
		byBucket.emplace_back();
		if (!nOrd.empty()) {
			nBuck[nOrd[0]] = bs;
			if (nOrd[0] < m) {
				byBucket.back().emplace_back(nOrd[0]);
			}
		}
		for (int j = 1; j < (int)nOrd.size(); j++) {
			if (bucket[nOrd[j]+1] != bucket[nOrd[j-1]+1] || s[nOrd[j]] != s[nOrd[j-1]]) {
				bs++;
				byBucket.emplace_back();
			}
			nBuck[nOrd[j]] = bs;
			if (nOrd[j] < m) {
				byBucket.back().emplace_back(nOrd[j]);
			}
		}
		ord = nOrd;
		bucket = nBuck;
		for (auto it: byBlock[i]) {
			int qId = it.first;
			int buck = bucket[it.second];
			int knt = v[qId].first;
			if (knt > (int)byBucket[buck].size()) {
				ans[qId] = -1;
			} else {
				ans[qId] = 1234567890;
				for (int j = knt - 1; j < (int)byBucket[buck].size(); j++) {
					ans[qId] = min(ans[qId], byBucket[buck][j] - byBucket[buck][j - knt + 1] + i);
				}
			}
		}
	}
	
	for (int i = 0; i < k; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}