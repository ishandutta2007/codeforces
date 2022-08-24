#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Token {
	int l, r;
	int x;
};

void revpr(vector<Token>& a, int l) {
	int r = a[l - 1].r;
	reverse(a.begin(), a.begin() + l);
	for (int i = 0; i < l; ++i) {
		a[i].l = r - a[i].l;
		a[i].r = r - a[i].r;
		swap(a[i].l, a[i].r);
		a[i].x *= -1;
	}
}

void renumber(vector<Token>& a) {
	int missed = (int)a.size() + 1;
	for (int i = 1; i <= (int)a.size(); ++i) {
		missed ^= i;
		missed ^= abs(a[i - 1].x);
	}
	for (auto& t : a) {
		if (abs(t.x) > missed) {
			t.x += (t.x > missed) ? -1 : 1;
		}
	}
}

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	vector<int> s_types(n / 2), t_types(n / 2);
	for (int i = 0; i < n; i += 2) {
		s_types[i / 2] = (s[i] - '0') + (s[i + 1] - '0');
		t_types[i / 2] = (t[i] - '0') + (t[i + 1] - '0');
	}
	auto st_sort = s_types;
	auto tt_sort = t_types;
	sort(all(st_sort));
	sort(all(tt_sort));
	if (st_sort != tt_sort) {
		cout << "-1\n";
		return;
	}

	vector<int> by_type[3];
	for (int i = 0; i < n / 2; ++i) {
		by_type[t_types[i]].push_back(i);
	}

	vector<Token> a;
	for (int i = 0; i < n / 2; ++i) {
		int tp = s_types[i];
		int x = by_type[tp].back();
		by_type[tp].pop_back();
		int val = x + 1;
		if (s[2 * i] != t[2 * x]) {
			val *= -1;
		}
		a.push_back({2 * i, 2 * i + 2, val});
	}

	vector<int> ans;
	auto rev = [&](int l) {
		ans.push_back(a[l - 1].r);
		revpr(a, l);
	};
	while ((int)a.size() > 1) {
		while (true) {
			vector<int> pos(a.size());
			for (int i = 0; i < (int)a.size(); ++i) {
				pos[abs(a[i].x) - 1] = i;
			}
			bool ok = false;
			for (int i = 0; i < (int)a.size() - 1; ++i) {
				if (a[pos[i]].x > 0 && a[pos[i + 1]].x > 0 && pos[i] < pos[i + 1]) {
					if (pos[i] + 1 != pos[i + 1]) {
						rev(pos[i] + 1);
						rev(pos[i + 1]);
					}
					a[pos[i + 1] - 1].r = a[pos[i + 1]].r;
					a.erase(a.begin() + pos[i + 1]);
					renumber(a);
					ok = true;
					break;
				} else if (a[pos[i]].x < 0 && a[pos[i + 1]].x < 0 && pos[i] > pos[i + 1]) {
					if (pos[i] + 1 != pos[i + 1]) {
						rev(pos[i + 1] + 1);
						rev(pos[i]);
					}
					a[pos[i] - 1].r = a[pos[i]].r;
					a.erase(a.begin() + pos[i]);
					renumber(a);
					ok = true;
					break;
				} else if (a[pos[i]].x > 0 && a[pos[i + 1]].x < 0) {
					int l = min(pos[i], pos[i + 1]);
					int r = max(pos[i], pos[i + 1]);
					rev(r + 1);
					rev(r - l);
					a[r - 1 - l].r = a[r - l].r;
					a.erase(a.begin() + (r - l));
					renumber(a);
					ok = true;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
		if ((int)a.size() == 1) {
			if (a[0].x < 0) {
				rev(1);
			}
			break;
		}
		int idx = 0;
		while (idx < (int)a.size() && a[idx].x != (int)a.size()) {
			++idx;
		}
		if (idx < (int)a.size()) {
			if (idx < (int)a.size() - 1) {
				rev(idx + 1);
				rev(a.size());
			}
			a.pop_back();
		} else {
			for (int i = 0; i < (int)a.size(); ++i) {
				rev(a.size() - 1);
				rev(a.size());
			}
			break;
		}
	}
	if (a[0].x < 0) {
		rev(1);
	}

	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}