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
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n;
	cin >> n;
	cout << "? " << 1 << " " << n << endl;
	multiset<string> S;
	for (int i = 0; i < n * (n + 1) / 2; ++i) {
		string s;
		cin >> s;
		sort(all(s));
		S.insert(s);
	}
	if (n == 1) {
		cout << "! " << *S.begin() << endl;
		return 0;
	}
	cout << "? " << 2 << " " << n << endl;
	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		string s;
		cin >> s;
		sort(all(s));
		S.erase(S.find(s));
	}
	string ans = "";
	vector<string> all_strs;
	for (auto s : S) {
		all_strs.push_back(s);
	}
	sort(all(all_strs), [](const string& s, const string& t) {
		return s.size() < t.size();
	});
	string last = "";
	for (auto s : all_strs) {
		int j = 0;
		while (j < (int)last.size() && last[j] == s[j]) {
			++j;
		}
		ans += s[j];
		last = s;
	}
	cout << "! " << ans << endl;

	return 0;
}