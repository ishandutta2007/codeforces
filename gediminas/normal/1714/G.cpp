#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
4
9
1 5 6
4 5 1
2 9 10
4 2 1
1 2 1
2 3 3
6 4 3
8 1 3
4
1 1 100
2 1 1
3 101 1
4
1 100 1
2 1 1
3 1 101
10
1 1 4
2 3 5
2 5 1
3 4 3
3 1 5
5 3 5
5 2 1
1 3 2
6 2 1
*/

const int maxn = 200010;
vector<int> gra[maxn];
int ans[maxn];
int a[maxn];
int b[maxn];
vector<long long> sums;

void dfs(int v, long long A, int p) {
	debug(v, A, p, sums);
	A += a[v];

	for (int i = 17; i >= 0;) {
		int pp = p + (1ll << i);

		if (pp < sums.size() and sums[pp] <= A) {
			p = pp;
		}
		else {
			--i;
		}
	}

	while (p < sums.size() and sums[p] <= A) {
		p++;
	}

	ans[v] = p - 1;

	for (auto &&i : gra[v]) {
		sums.push_back(sums.back() + b[i]);
		dfs(i, A, p);
		sums.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		sums.clear();
		sums.push_back(0);
		a[0] = b[0] = 0;

		int n;
		cin >> n;

		for (int i = 1; i < n; ++i) {
			int p;
			cin >> p >> a[i] >> b[i];
			p--;
			gra[p].push_back(i);
		}

		dfs(0, 0, 0);

		for (int i = 0; i < n; ++i) {
			gra[i].clear();
		}

		for (int i = 1; i < n; ++i) {
			cout << ans[i] << " ";
		}

		cout << "\n";
	}
}