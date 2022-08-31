#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

const int K = 42;
int cnts[K];
int needed[K];

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (auto x : a) {
		if (__builtin_popcountll(x) == 1) {
			cnts[__builtin_ctzll(x)] += 1;
		} else {
			needed[__builtin_clzll(1ll) - __builtin_clzll(x)] += 1;
		}
	}

	// for (int i = 0; i < K; ++i) {
	// 	cerr << cnts[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < K; ++i) {
	// 	cerr << needed[i] << " ";
	// }
	// cerr << "\n";

	bool atleastone = false;
	for (int c = 1; c <= cnts[0]; ++c) {
		vector<int> real_cnt(K);
		vector<int> real_needed(K);
		int cur = c;
		for (int i = 0; i < K; ++i) {
			cur = min(cur, cnts[i]);
			real_cnt[i] = cur;
			real_needed[i] += needed[i];
			real_needed[max(i - 1, 0)] += cnts[i] - cur;
		}
		// for (int i = 0; i < K; ++i) {
		// 	cerr << real_cnt[i] << " ";
		// }
		// cerr << "\n";
		// for (int i = 0; i < K; ++i) {
		// 	cerr << real_needed[i] << " ";
		// }
		// cerr << "\n\n";
		int ready = 0;
		bool ok = true;
		for (int i = K - 1; i >= 0; --i) {
			ready += real_cnt[i];
			if (i < K - 1) {
				ready -= real_cnt[i + 1];
			}
			if (ready < real_needed[i]) {
				ok = false;
				break;
			} else {
				ready -= real_needed[i];
			}
		}
		if (ok) {
			cout << c << " ";
			atleastone = true;
		}
	}
	if (!atleastone) {
		cout << "-1";
	}
	cout << "\n";

	return 0;
}