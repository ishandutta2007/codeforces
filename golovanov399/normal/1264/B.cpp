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

bool check(const vector<int>& a) {
	for (int i = 1; i < (int)a.size(); ++i) {
		if (abs(a[i] - a[i - 1]) != 1) {
			return false;
		}
	}
	return true;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	vector<int> cnt(4);
	for (int i = 0; i < 4; ++i) {
		cnt[i] = nxt();
	}

	vector<int> pars[2];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			pars[i % 2].push_back(i);
		}
	}
	int n = accumulate(all(cnt), 0);

	for ([[maybe_unused]] char e : ")") {
		for ([[maybe_unused]] char o : ")") {
			for (int st : {0, 1}) {
				vector<int> a;
				bool ok = true;
				array<int, 2> ptr = {{0, 0}};
				for (int i = 0; i < n; ++i) {
					int idx = (i % 2) ^ st;
					if (ptr[idx] < (int)pars[idx].size()) {
						a.push_back(pars[idx][ptr[idx]++]);
					} else {
						ok = false;
						break;
					}
				}
				if (ok) {
					ok = check(a);
				}
				if (ok) {
					printf("YES\n");
					for (int x : a) {
						printf("%d ", x);
					}
					printf("\n");
					return 0;
				}
			}
		}
	}

	puts("NO");

	return 0;
}