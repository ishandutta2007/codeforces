#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int bruteforce(vector<vector<pair<int, int>>> segments) {
	int ans = 0;
	rep(j,0,(1<<(sz(segments)))) {
		vector<int> rows;
		rep(i,0,sz(segments)) {
			if (j&(1<<i))
				rows.push_back(i);
		}
		bool canDo = true;
		rep(i,0,sz(rows)-1) {
			bool ok = false;
			for (auto s1 : segments[rows[i]])
			for (auto s2 : segments[rows[i+1]]) {
				if (s1.second > s2.first && s2.second > s1.first) {
					ok = true;
				}
			}
			if (!ok)
				canDo = false;
		}
		if (canDo) {
			ans = max(ans, __builtin_popcount(j));
		}
	}
	return sz(segments)-ans;
}

void solve() {
	int n, m;
#ifdef DEBUG
	n = 1+(rand()%10);
	m = 1+(rand()%20);
#else
	cin >> n >> m;
#endif
#ifdef DEBUG
	//cerr << endl << n << " " << m << endl;
#endif
	map<pair<int, int>, int> M;
	map<pair<int, int>, int> toRow;
	M[make_pair(-3, -2)] = 0;
	M[make_pair(-1, 15e8)] = 0;
	M[make_pair(16e8, 2e9)] = 0;
	toRow[make_pair(-3, -2)] = -1;
	toRow[make_pair(-1, 15e8)] = -1;
	toRow[make_pair(16e8, 2e9)] = -1;
	vector<vector<pair<int, int>>> segments(n);
	rep(i,0,m) {
		int I, l, r;
#ifdef DEBUG
		I = (rand()%n)+1;
		l = rand()%1000000;
		r = l+(rand()%10000);
#else
		cin >> I >> l >> r;
#endif
#ifdef DEBUG
		//cerr << I << " " << l << " " << r << endl;
#endif
		--I;
		++r;
		assert(r > l);
		segments[I].emplace_back(l, r);
	}
#ifdef DEBUG
	int bruteforceVal = bruteforce(segments);
#endif
	vector<int> prevRow(n, -1);
	int ans = n;
	int bestrow = 0;
	rep(i,0,n) {
		sort(all(segments[i]));
		rep(j,0,sz(segments[i])) {
			if (j+1 < sz(segments[i]) && segments[i][j].second > segments[i][j+1].first) {
				if (segments[i][j].second > segments[i][j+1].second) {
					segments[i][j+1].second = segments[i][j].second;
				}
				segments[i][j].second = segments[i][j+1].first;
			}
		}
		int best = 0;
		for (auto seg : segments[i]) {
			auto it = M.lower_bound(seg);
			while (it->first.second > seg.first) {
				--it;
			}
			++it;
			while (it->first.first < seg.second) {
				if (it->second > best) {
					best = max(best, it->second);
					assert(toRow.count(it->first));
					prevRow[i] = toRow[it->first];
				}
				++it;
			}
		}
		for (auto seg : segments[i]) {
			while (true) {
				auto it = M.lower_bound(seg);
				auto key = it->first;
				auto val = it->second;
				while (key.second > seg.first) {
					--it;
					key = it->first;
					val = it->second;
				}
				++it;
				key = it->first;
				val = it->second;
				if (key.first < seg.second) {
					if (val > best) {
						assert(val <= best);
					}
					M.erase(it);
					if (key.first < seg.first) {
						M[make_pair(key.first, seg.first)] = val;
						assert(toRow.count(key));
						toRow[make_pair(key.first, seg.first)] = toRow[key];
					}
					if (key.second > seg.second) {
						M[make_pair(seg.second, key.second)] = val;
						assert(toRow.count(key));
						toRow[make_pair(seg.second, key.second)] = toRow[key];
					}
				} else {
					break;
				}
			}
			M[make_pair(seg.first, seg.second)] = best+1;
			toRow[make_pair(seg.first, seg.second)] = i;
		}
		if (n-best-1 < ans) {
			ans = min(ans, n-best-1);
			bestrow = i;
		}
	}
#ifndef DEBUG
	cout << ans << endl;
#endif
#ifdef DEBUG
	assert(ans == bruteforceVal);
#endif
	set<int> remaining;
	rep(i,0,n)
		remaining.insert(i);
	vector<int> rows;
	while (bestrow != -1) {
		rows.push_back(bestrow);
		remaining.erase(bestrow);
		bestrow = prevRow[bestrow];
	}
	rep(i,0,sz(rows)-1) {
		bool ok = false;
		for (auto s1 : segments[rows[i]])
		for (auto s2 : segments[rows[i+1]]) {
			if (s1.second > s2.first && s2.second > s1.first) {
				ok = true;
			}
		}
		assert(ok);
	}
	assert(sz(remaining) == ans);
	reverse(all(rows));
#ifndef DEBUG
	for (auto i : remaining)
		cout << i+1 << " ";
	cout << endl;
#endif
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
#ifdef DEBUG
	while (true)
#endif
		solve();
}