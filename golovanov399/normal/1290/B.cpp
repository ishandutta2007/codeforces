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

const int N = 222222;
int cnt[26][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			cnt[j][i + 1] = cnt[j][i];
		}
		cnt[s[i] - 'a'][i + 1] += 1;
	}

	int q = nxt();
	while (q --> 0) {
		int l = nxt() - 1, r = nxt();
		if (r - l <= 1) {
			cout << "Yes\n";
		} else {
			int cnt_letters = 0;
			for (int i = 0; i < 26; ++i) {
				if (cnt[i][r] > cnt[i][l]) {
					++cnt_letters;
				}
			}
			if (cnt_letters <= 2 && s[l] == s[r - 1]) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
			}
		}
	}

	return 0;
}