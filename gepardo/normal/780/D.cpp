#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>

using namespace std;

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
    #else
		ios_base::sync_with_stdio(false);
    #endif // DEBUG
    int n; cin >> n;
    map<string, vector< pair<char, int> > > mp;
	for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        char c = b[0];
        a = a.substr(0, 3);
        for (auto it: mp[a]) {
			if (it.first == c) {
				cout << "NO" << endl;
				return 0;
			}
        }
        mp[a].emplace_back(c, i);
	}
	vector<string> ans(n);
	map<string, int> cnt;
    for (const auto& it: mp) {
        if (it.second.size() != 1) {
			for (auto jt: it.second) {
                string res = it.first.substr(0, 2) + jt.first;
                ans[jt.second] = res;
                cnt[res]++;
			}
		}
    }
	for (auto it: cnt) {
		if (it.second > 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
    vector< pair< pair<string, string>, int> > var;
	for (const auto& it: mp) {
		if (it.second.size() == 1) {
            auto jt = it.second[0];
            string res1 = it.first;
            string res2 = it.first.substr(0, 2) + jt.first;
            var.push_back({{res1, res2}, jt.second});
		}
    }
    map<string, int> s2i;
    vector<string> i2s;
    for (const auto& it: var) {
		s2i[it.first.first] = true;
		s2i[it.first.second] = true;
    }
    int ptr = 0;
    for (auto& it: s2i) {
		it.second = ptr++;
		i2s.push_back(it.first);
    }
    vector< vector< pair<int, int> > > g(ptr);
    for (const auto& it: var) {
		int a = s2i[it.first.first];
		int b = s2i[it.first.second];
		g[a].push_back({b, it.second});
    }
    vector<char> blocked(ptr);
    for (int i = 0; i < ptr; i++) {
		blocked[i] = !!cnt[i2s[i]];
    }
	vector<int> whose(ptr, -1);
	bool ok = true;
	while (ok) {
		ok = false;
		for (int i = 0; i < ptr; i++) {
			for (auto& j: g[i]) {
				if (j.second >= 0 && blocked[j.first] && !blocked[i]) {
					whose[i] = j.second;
					blocked[i] = true;
					ok = true;
					j.second = -1;
					break;
				}
				if (j.second >= 0 && !blocked[j.first] && blocked[i]) {
					whose[j.first] = j.second;
					blocked[j.first] = true;
					ok = true;
					j.second = -1;
					break;
				}
			}
		}
		if (!ok) {
			for (int i = 0; i < ptr; i++) {
				for (auto& j: g[i]) {
					if (j.second >= 0 && !blocked[j.first] && !blocked[i]) {
						whose[i] = j.second;
						blocked[i] = true;
						ok = true;
						j.second = -1;
						break;
					}
				}
				if (ok) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < ptr; i++) {
		if (whose[i] >= 0) {
			ans[whose[i]] = i2s[i];
			cnt[i2s[i]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == "") {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (auto it: cnt) {
		if (it.second > 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}