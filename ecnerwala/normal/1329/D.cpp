#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		string A; cin >> A;
		int N = int(A.size());

		int S = 1; while (S < N) S *= 2;
		vector<int> seg(2*S);
		for (int i = 0; i < N; i++) {
			seg[S+i] = i+1;
		}
		auto query = [&](int i) {
			int res = 0;
			for (int a = S+i; a; a /= 2) res += seg[a];
			return res;
		};
		// half-open
		auto updateRange = [&](int l, int r, int v) {
			for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
				if (a & 1) seg[a++] += v;
				if (b & 1) seg[--b] += v;
			}
		};

		vector<int> cnt(26);

		map<pair<int, int>, char> equals;
		for (int i = 1; i < N; i++) {
			if (A[i-1] == A[i]) {
				equals[{i-1,i}] = A[i];
				cnt[A[i]-'a']++;
			}
		}

		vector<pair<pair<int, int>, pair<int, int>>> evts[26];

		auto updEvt = [&](auto it, auto jt) {
			if (it->second != jt->second) {
				evts[it->second-'a'].push_back({it->first, jt->first});
				evts[jt->second-'a'].push_back({it->first, jt->first});
			}
		};

		for (auto it = equals.begin(); it != equals.end(); ++it) {
			auto jt = it; ++jt;
			if (jt == equals.end()) break;
			updEvt(it, jt);
		}

		vector<pair<int, int>> ans;

		auto doRange = [&](int l, int r) {
			int ql = query(l);
			int qr = query(r);
			ans.push_back({ql, qr});
			updateRange(r+1, N, -(qr - ql + 1));
		};
		while (true) {
			int c = int(max_element(cnt.begin(), cnt.end()) - cnt.begin());
			while (true) {
				if (evts[c].empty()) {
					assert(cnt[c] == int(equals.size()));
					if (equals.size() == 0) {
						doRange(0, N-1);
						goto done;
					} else if (equals.size() == 1) {
						auto it = equals.begin()->first;
						doRange(0, it.first);
						doRange(it.second, N-1);
						equals.clear();
						goto done;
					} else {
						cnt[c]--;
						auto it = equals.begin();
						auto jt = it; ++jt;
						doRange(it->first.second, jt->first.first);
						pair<int, int> n(it->first.first, jt->first.second);
						equals.erase(it);
						equals.erase(jt);
						equals[n] = char(c+'a');
					}
					break;
				}
				pair<int, int> l, r; tie(l, r) = evts[c].back(); evts[c].pop_back();
				auto lit = equals.find(l);
				auto rit = equals.find(r);
				if (lit == equals.end() || rit == equals.end()) {
					continue;
				}
				assert(lit->second != rit->second);
				assert(lit->second-'a' == c || rit->second-'a' == c);
				cnt[lit->second-'a']--;
				cnt[rit->second-'a']--;
				doRange(l.second, r.first);

				equals.erase(lit);
				auto it = equals.erase(rit);

				if (it != equals.end() && it != equals.begin()) {
					auto pt = it; --pt;
					updEvt(pt, it);
				}
				break;
			}
		}

done:
		cout << ans.size() << '\n';
		for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
	}

	return 0;
}