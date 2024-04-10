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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}

	int cnt = 0;
	vector<char> used(n);
	for (itn i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}

		int u = a[i];
		int v = a[u];
		// cerr << u + 1 << ", " << v + 1 << ": ";
		for (int j = i; j < n; ++j) {
			if (a[j] == u || a[j] == v) {
				assert(!used[j]);
				used[j] = 1;
				// cerr << j + 1 << " ";
			}
		}
		// cerr << "\n";
		++cnt;
	}

	printf("%d\n", cnt);

	return 0;
}