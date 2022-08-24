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
	cin >> x;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	int n = nxt();
	vector<char> sets(10, -1);
	vector<char> xors(10, 0);
	for (int i = 0; i < n; ++i) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '|') {
			for (int j = 0; j < 10; ++j) {
				if (x & (1 << j)) {
					sets[j] = 1;
					xors[j] = 0;
				}
			}
		} else if (c == '&') {
			for (int j = 0; j < 10; ++j) {
				if (x & (1 << j)) {
					continue;
				}
				sets[j] = 0;
				xors[j] = 0;
			}
		} else {
			for (int j = 0; j < 10; ++j) {
				if(x & (1 << j)) {
					xors[j] ^= 1;
				}
			}
		}
	}

	int and_num = 1023;
	int or_num = 0;
	int xor_num = 0;
	for (int i = 0; i < 10; ++i) {
		if (sets[i] == 0) {
			and_num ^= (1 << i);
		} else if (sets[i] == 1) {
			or_num ^= (1 << i);
		}
		if (xors[i]) {
			xor_num ^= (1 << i);
		}
	}
	cout << 3 << "\n& " << and_num << "\n| " << or_num << "\n^ " << xor_num << "\n";

	return 0;
}