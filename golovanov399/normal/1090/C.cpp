#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt();
	vector<set<int>> a(n);
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		for (int j = 0; j < k; ++j) {
			a[i].insert(nxt() - 1);
		}
	}
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += a[i].size();
	}

	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		cnt[i] = a[i].size();
	}


	vector<array<int, 3>> ans;

	int mn = total / n;
	int mx = (total + n - 1) / n;
	{
		set<int> mn_ids, mx_ids;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] < mn) {
				mn_ids.insert(i);
			} else if (cnt[i] > mx) {
				mx_ids.insert(i);
			}
		}
		vector<vector<int>> avail(m);
		for (int i : mx_ids) {
			for (int j : a[i]) {
				avail[j].push_back(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			set<int>::iterator it = mn_ids.begin();
			while (it != mn_ids.end() && a[*it].count(i)) {
				++it;
			}
			vector<int> to_del;
			for (int j : avail[i]) {
				if (it == mn_ids.end()) {
					break;
				}
				if (cnt[j] <= mx) {
					continue;
				}
				ans.push_back({j, *it, i});
				--cnt[j];
				++cnt[*it];
				a[j].erase(i);
				a[*it].insert(i);
				if (cnt[*it] >= mn) {
					to_del.push_back(*it);
				}
				do {
					++it;
				} while (it != mn_ids.end() && a[*it].count(i));
			}
			for (int x : to_del) {
				mn_ids.erase(x);
			}
		}
	}
	mn = total / n;
	mx = mn;
	{
		set<int> mn_ids, mx_ids;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] < mn) {
				mn_ids.insert(i);
			} else if (cnt[i] > mx) {
				mx_ids.insert(i);
			}
		}
		vector<vector<int>> avail(m);
		for (int i : mx_ids) {
			for (int j : a[i]) {
				avail[j].push_back(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			set<int>::iterator it = mn_ids.begin();
			while (it != mn_ids.end() && a[*it].count(i)) {
				++it;
			}
			vector<int> to_del;
			for (int j : avail[i]) {
				if (it == mn_ids.end()) {
					break;
				}
				if (cnt[j] <= mx) {
					continue;
				}
				ans.push_back({j, *it, i});
				--cnt[j];
				++cnt[*it];
				a[j].erase(i);
				a[*it].insert(i);
				if (cnt[*it] >= mn) {
					to_del.push_back(*it);
				}
				do {
					++it;
				} while (it != mn_ids.end() && a[*it].count(i));
			}
			for (int x : to_del) {
				mn_ids.erase(x);
			}
		}
	}
	mn = (total + n - 1) / n;
	mx = mn;
	{
		set<int> mn_ids, mx_ids;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] < mn) {
				mn_ids.insert(i);
			} else if (cnt[i] > mx) {
				mx_ids.insert(i);
			}
		}
		vector<vector<int>> avail(m);
		for (int i : mx_ids) {
			for (int j : a[i]) {
				avail[j].push_back(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			set<int>::iterator it = mn_ids.begin();
			while (it != mn_ids.end() && a[*it].count(i)) {
				++it;
			}
			vector<int> to_del;
			for (int j : avail[i]) {
				if (it == mn_ids.end()) {
					break;
				}
				if (cnt[j] <= mx) {
					continue;
				}
				ans.push_back({j, *it, i});
				--cnt[j];
				++cnt[*it];
				a[j].erase(i);
				a[*it].insert(i);
				if (cnt[*it] >= mn) {
					to_del.push_back(*it);
				}
				do {
					++it;
				} while (it != mn_ids.end() && a[*it].count(i));
			}
			for (int x : to_del) {
				mn_ids.erase(x);
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto& v : ans) {
		for (int& x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	return 0;
}