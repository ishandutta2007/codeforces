#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<long long> degs = {1};
	if (abs(k) > 1) {
		while (llabs(degs.back()) < 1e15) {
			degs.push_back(degs.back() * k);
		}
	} else {
		if (k == -1) {
			degs.push_back(-1);
		}
	}

	long long cur = 0;
	map<long long, int> M;
	M[0] = 1;
	long long ans = 0;
	for (int x : a) {
		cur += x;
		for (auto y : degs) {
			if (M.count(cur - y)) {
				ans += M[cur - y];
			}
		}
		M[cur] += 1;
	}

	cout << ans << "\n";

	return 0;
}