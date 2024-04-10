#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct SearchAns {
	vector<int> loc;
	vector<vector<int>> presum, val;
	int ansbegin;
	const int b, p, q;
	SearchAns(int n, const vector<int> &loc_, const vector<pair<string, int>> &op, int _b, int _p, int _q) : loc(loc_), presum(loc.size()), val(loc.size()), b(_b), p(_p), q(_q) {
		loc.emplace_back(n);
		ansbegin = 1;
		for (int i = 0; i < loc[0]; i++) {
			if (op[i].first[0] == '+') {
				ansbegin += op[i].second;
			}
		}
		for (int i = 0; i < (int)loc.size() - 1; i++) {
			for (int j = loc[i]; j < loc[i + 1]; j++) {
				if (op[j].first[0] == '+') {
					val[i].emplace_back(op[j].second);
				}
			}
			sort(val[i].begin(), val[i].end());
			presum[i].resize(val[i].size());
			if (!val[i].empty()) {
				presum[i][0] = val[i][0];
				for (int j = 1; j < (int)val[i].size(); j++) {
					presum[i][j] = presum[i][j - 1] + val[i][j];
				}
			}
		}
		loc.pop_back();
	}
	bool check(const vector<int> &mul, LL lim, int cost) {
		int x = 1, aback = 1;
		for (auto v : mul) {
			aback *= v;
		}
		for (int i = 0; i < (int)mul.size(); i++) {
			x *= mul[i], aback /= mul[i];
			if (x == 1) {
				continue;
			}
			LL y = (x - 1ll) * aback;
			LL nowl = (lim + y - 1) / y;
			if (val[i].empty() || val[i].back() < nowl) {
				continue;
			}
			int c = val[i].end() - lower_bound(val[i].begin(), val[i].end(), nowl);
			cost -= c;
			if (cost < 0) {
				return false;
			}
		}
		return true;
	}
	LL calc(const vector<int> &mul, LL lim, int cost, int back) {
		int x = 1;
		LL ans = ansbegin, mxr = lim - 1, aback = 1;
		vector<int> rsum(mul.size(), 0);
		for (auto v : mul) {
			aback *= v;
		}
		for (int i = 0; i < (int)mul.size(); i++) {
			x *= mul[i], aback /= mul[i];
			if (x == 1) {
				ans += presum[i].empty() ? 0 : presum[i].back();
			} else {
				LL y = (x - 1ll) * aback;
				LL nowl = (lim + y - 1) / y;
				if (val[i].empty() || val[i].back() < nowl) {
					if (!val[i].empty()) {
						rsum[i] = presum[i].back();
					}
				} else {
					int d = lower_bound(val[i].begin(), val[i].end(), nowl) - val[i].begin();
					cost -= val[i].size() - d;
					if (d > 0) {
						rsum[i] = presum[i][d - 1];
					}
				}
				ans += (presum[i].empty() ? 0 : presum[i].back()) - rsum[i];
			}
		}
		if (cost > 0) {
			int x = 1, aback = 1;
			for (auto v : mul) {
				aback *= v;
			}
			for (int i = 0; cost > 0 && i < (int)mul.size(); i++) {
				x *= mul[i], aback /= mul[i];
				LL y = (x - 1ll) * aback;
				if (y > 0 && !val[i].empty() && mxr % y == 0) {
					LL nowr = mxr / y;
					int pl = lower_bound(val[i].begin(), val[i].end(), nowr) - val[i].begin();
					if (pl < (int)val[i].size() && val[i][pl] == nowr) {
						int pr = upper_bound(val[i].begin(), val[i].end(), nowr) - val[i].begin();
						int nowc = min(cost, pr - pl), ri = pr - 1, li = ri - nowc;
						ans += presum[i][ri], rsum[i] -= presum[i][ri];
						if (li >= 0) {
							ans -= presum[i][li], rsum[i] += presum[i][li];
						}
						cost -= nowc;
					}
				}
			}
		}
		for (int i = 0; i < (int)mul.size(); i++) {
			ans = ans * mul[i] + rsum[i];
		}
		ans *= back;
		return ans;
	}
	LL calc(vector<int> &mul) {
		int back = 1;
		LL cost = b;
		for (int i = 0; i < (int)mul.size(); i++) {
			if (mul[i] < 0) {
				cost -= q, back *= -mul[i];
				mul[i] = 1;
				if (cost < 0) {
					return 0;
				}
			}
		}
		cost /= p;
		LL l = 0, r = 1e18, lim = 1e18;
		while (l <= r) {
			LL mid = (l + r) >> 1;
			if (check(mul, mid, cost)) {
				lim = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return calc(mul, lim, cost, back);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, b, p, q;
	cin >> n >> b >> p >> q;
	vector<pair<string, int>> op(n);
	vector<int> loc;
	for (int i = 0; i < n; i++) {
		auto &[s, v] = op[i];
		cin >> s >> v;
		if (s[0] == '*' && v > 1) {
			loc.emplace_back(i);
		}
	}

	SearchAns sans(n, loc, op, b, p, q);

	vector<vector<int>> muls;
	vector<int> now;
	std::function<void(int, int)> search = [&](int id, int ns) {
		if (id == (int)loc.size()) {
			muls.emplace_back(now);
			return;
		}
		int nowv = op[loc[id]].second;
		if (nowv > ns) {
			now.push_back(-nowv);
			search(id + 1, ns);
			now.pop_back();
		}
		now.push_back(nowv);
		search(id + 1, max(ns, nowv));
		now.pop_back();
	};
	search(0, 0);
	LL ans = 0;
	for (auto &mul : muls) {
		ans = max(ans, sans.calc(mul));
	}
	printf("%lld\n", ans);
	return 0;
}