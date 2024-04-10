#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N;
int A[MAXN];
pair<int, int> q[MAXN];
int occ[MAXN];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int s = N, e = N;
	for (int i = N - 1; i >= 0; i--) {
		int x = A[i];
		if (occ[x]) {
			int j = occ[x];
			bool popped = false;
			while (s != e && q[e - 1].first >= j) {
				popped = true, --e;
				if (q[e].second - q[e].first + i == 0)
					++ans;
			}
			if (popped)
				q[e++].first = j - 1;
		}
		occ[x] = i;

		int lim = i;
		while (s != e && q[s].second < x) {
			if (q[s].second - q[s].first + i == 0)
				++ans;
			lim = q[s++].first;
		}

		if (s == e || q[s].second > x)
			q[--s] = { lim, x };
	}

	while (s != e) {
		if (q[s].second - q[s].first == 1)
			++ans;
		++s;
	}

	cout << ans << endl;
	return 0;
}