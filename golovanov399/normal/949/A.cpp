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

void panic() {
	puts("-1");
	exit(0);
}

int main() {
	string s;
	cin >> s;

	int n = s.length();
	vector<int> nx(n, -1);
	vector<int> a[2];

	for (int i = 0; i < n; ++i) {
		char c = s[i] - '0';
		if (a[c ^ 1].empty()) {
			if (c == 0) {
				a[0].push_back(i);
			} else {
				panic();
			}
		} else {
			nx[a[c ^ 1].back()] = i;
			a[c ^ 1].pop_back();
			a[c].push_back(i);
		}
	}
	if (!a[1].empty()) {
		panic();
	}

	printf("%d\n", (int)a[0].size());
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> v;
		for (int j = i; j != -1; j = nx[j]) {
			used[j] = 1;
			v.push_back(j);
		}
		printf("%d", (int)v.size());
		for (int x : v) {
			printf(" %d", x + 1);
		}
		printf("\n");
	}

	return 0;
}