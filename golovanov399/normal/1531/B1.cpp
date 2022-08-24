#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	map<int, int> M;
	map<pair<int, int>, int> N;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		pair<int, int> p = {nxt(), nxt()};
		if (p.first > p.second) {
			swap(p.first, p.second);
		}
		ans += M[p.first];
		if (p.first != p.second) {
			ans += M[p.second];
			ans -= N[p];
		}
		M[p.first] += 1;
		if (p.first != p.second) {
			M[p.second] += 1;
			N[p] += 1;
		}
	}
	cout << ans << "\n";

	return 0;
}