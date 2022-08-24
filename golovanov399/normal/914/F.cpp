#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 100010;
using bs = bitset<N>;

const int L = 26;
bs a[L];

bs def;
bs tmp;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;

	for (int i = 0; i < N; ++i) {
		def.flip(i);
	}

	for (int i = 0; i < (int)s.length(); ++i) {
		a[s[i] - 'a'].flip(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			--pos;
			a[s[pos] - 'a'].flip(pos);
			s[pos] = c;
			a[s[pos] - 'a'].flip(pos);
		} else {
			int l, r;
			string y;
			cin >> l >> r >> y;
			--l;
			r = (r - (int)y.length() + 1);
			if (r <= l) {
				cout << 0 << "\n";
				continue;
			}
			int ans = 0;

			tmp = def;
			for (int i = 0; i < (int)y.length(); ++i) {
				tmp &= (a[y[i] - 'a'] >> (l + i));
			}
			ans += tmp.count();

			tmp = def;
			for (int i = 0; i < (int)y.length(); ++i) {
				tmp &= (a[y[i] - 'a'] >> (r + i));
			}
			ans -= tmp.count();

			cout << ans << "\n";
		}
	}

	return 0;
}