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

const string coh = "COH";

vector<int> ask(string s) {
	cout << "? " << s << endl;
	vector<int> res(nxt());
	generate(all(res), nxt);
	return res;
}

void solveIter(int n, string s, int pos) {
	while ((int)s.length() < n) {
		if (pos) {
			int i = 0;
			while (i < 2) {
				auto vec = ask(coh[i] + s);
				if (binary_search(all(vec), pos)) {
					break;
				} else {
					++i;
				}
			}
			s = coh[i] + s;
			--pos;
		} else {
			int i = 0;
			while (i < 2) {
				auto vec = ask(s + coh[i]);
				if (binary_search(all(vec), pos + 1)) {
					break;
				} else {
					++i;
				}
			}
			s += coh[i];
		}
	}
	cout << "! " << s << endl;
	assert(nxt());
}

void solve() {
	int n = nxt();
	for (auto s : vector<string>{"CO", "CH"}) {
		auto q = ask(s);
		if (!q.empty()) {
			solveIter(n, s, q[0] - 1);
			return;
		}
	}

	auto oh = ask("OH");
	auto ho = ask("HO");

	if (oh.empty() && ho.empty()) {
		auto q = ask("CCC");
		if (q.empty()) {
			q = ask("OOC");
			if (q.empty()) {
				q = ask("HHC");
				if (q.empty()) {
					if (ask(string(n, 'O')).empty()) {
						cout << "! " << string(n, 'H') << endl;
					} else {
						cout << "! " << string(n, 'O') << endl;
					}
					assert(nxt());
					return;
				}
				int pos = q[0];
				cout << "! " << string(pos + 1, 'H') + string(n - pos - 1, 'C') << endl;
				assert(nxt());
				return;
			} else {
				int pos = q[0];
				cout << "! " << string(pos + 1, 'O') + string(n - pos - 1, 'C') << endl;
				assert(nxt());
				return;
			}
		} else {
			q = ask("OCCC");
			if (q.empty()) {
				q = ask("HCCC");
				if (q.empty()) {
					cout << "! " << string(n, 'C') << endl;
					assert(nxt());
					return;
				}
				int pos = q[0];
				cout << "! " << string(pos, 'H') + string(n - pos, 'C') << endl;
				assert(nxt());
				return;
			} else {
				int pos = q[0];
				cout << "! " << string(pos, 'O') + string(n - pos, 'C') << endl;
				assert(nxt());
				return;
			}
		}
	} else {
		string s(n, 'C');
		vector<pair<int, char>> ev;
		for (auto i : oh) {
			ev.push_back({i - 1, 'O'});
		}
		for (auto i : ho) {
			ev.push_back({i - 1, 'H'});
		}
		sort(all(ev));
		char cur = ev[0].second;
		int j = 0;
		for (int i = 0; i < (int)ev.size(); ++i) {
			while (j <= ev[i].first) {
				s[j++] = cur;
			}
			cur = (cur == 'O' ? 'H' : 'O');
			s[j++] = cur;
		}
		while (true) {
			if (!ask(s).empty()) {
				cout << "! " << s << endl;
				assert(nxt());
				return;
			} else {
				s[j++] = cur;
			}
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	// vector<string> shit;
	// for (int i = 0; i < 81; ++i) {
	// 	shit.push_back("");
	// 	int mask = i;
	// 	for (int j = 0; j < 4; ++j) {
	// 		shit.back() += coh[mask % 3];
	// 		mask /= 3;
	// 	}
	// }

	// vector<string> qrs = {"CO", "CH", "OH", "HO"};
	// for (auto s : shit) {
	// 	bool ok = true;
	// 	for (auto q : qrs) {
	// 		if (s.find(q) != string::npos) {
	// 			ok = false;
	// 		}
	// 	}
	// 	if (ok) {
	// 		cout << s << "\n";
	// 	}
	// }

	return 0;
}