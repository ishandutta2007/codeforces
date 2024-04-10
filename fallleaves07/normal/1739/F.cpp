#include<bits/stdc++.h>
using namespace std;
using LL = long long;

string getstr(string &s) {
	vector<bool> vis(12);
	string t;
	t += s[0], vis[s[0]] = true;
	int id = 0;
	for (int j = 1; j < (int)s.length(); j++) {
		if (t[id] == s[j]) {
			continue;
		}
		if (id > 0 && t[id - 1] == s[j]) {
			--id;
		} else if (id + 1 < (int)t.length() && t[id + 1] == s[j]) {
			++id;
		} else if (id == (int)t.length() - 1) {
			t += s[j], ++id;
		} else if (id == 0) {
			t = s[j] + t;
		} else {
			return "";
		}
	}
	return t;
}

struct ACAM {
	struct T {
		int s[12], val, fail;
		T() {
			memset(this, 0, sizeof(*this));
		}
	};
	vector<T> t;
	int root;
	int newnode() {
		t.emplace_back();
		return (int)t.size() - 1;
	}
	ACAM(int tot) {
		t.reserve(tot + 5);
		newnode();
		root = newnode();
	}
	void build(void) {
		queue<int> que;
		for (auto &u : t[root].s) {
			if (u) {
				que.push(u);
				t[u].fail = root, t[u].val += t[root].val;
			} else {
				u = root;
			}
		}
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (int i = 0; i < 12; i++) {
				int &u = t[v].s[i];
				if (u) {
					que.push(u);
					t[u].fail = t[t[v].fail].s[i], t[u].val += t[t[u].fail].val;
				} else {
					u = t[t[v].fail].s[i];
				}
			}
		}
	}
	int insert(const string &s) {
		int v = root;
		for (int i = 0; i < (int)s.length(); i++) {
			int &u = t[v].s[s[i] - 'a'];
			if (!u) {
				u = newnode();
			}
			v = u;
		}
		return v;
	}
	void solve() {
		vector f(1 << 12, vector<int>(t.size(), -1));
		vector fr(1 << 12, vector<pair<int, int>>(t.size()));
		f[0][root] = 0;
		int ans = -1, key = -1, lst = -1;
		for (int i = 0; i < (1 << 12); i++) {
			for (int j = 1; j < (int)t.size(); j++) {
				if (f[i][j] >= 0) {
					if (f[i][j] > ans) {
						ans = f[i][j], key = i, lst = j;
					}
					for (int k = 0; k < 12; k++) {
						if (!((i >> k) & 1)) {
							int x = t[j].s[k];
							if (f[i ^ (1 << k)][x] < f[i][j] + t[x].val) {
								f[i ^ (1 << k)][x] = f[i][j] + t[x].val;
								fr[i ^ (1 << k)][x] = {k, j};
							}
						}
					}
				}
			}
		}
		string str = "";
		while (key > 0) {
			int ch = fr[key][lst].first;
			str = char(ch + 'a') + str;
			lst = fr[key][lst].second;
			key ^= (1 << ch);
		}
		vector<bool> vis(12);
		for (auto c : str) {
			vis[c - 'a'] = true;
		}
		for (int i = 0; i < 12; i++) {
			if (!vis[i]) {
				str += char(i + 'a');
			}
		}
		printf("%s\n", str.c_str());
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> c(n);
	vector<string> s(n);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> s[i];
		s[i] = getstr(s[i]);
		tot += s[i].length() * 2;
	}
	ACAM acam(tot);
	for (int i = 0; i < n; i++) {
		if (s[i].length() > 0) {
			int u = acam.insert(s[i]);
			reverse(s[i].begin(), s[i].end());
			int v = acam.insert(s[i]);
			acam.t[u].val += c[i];
			if (v != u) {
				acam.t[v].val += c[i];
			}
		}
	}
	acam.build();
	acam.solve();
	return 0;
}