#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define INF 1000000013
int N;
int X[MAXN];
char C[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	vector<int> v;
	int miR = INF, miB = INF, maR = -INF, maB = -INF;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> C[i];
		if (C[i] == 'P')
			v.push_back(i);
		if (C[i] == 'R')
			miR = min(miR, X[i]), maR = max(maR, X[i]);
		if (C[i] == 'B')
			miB = min(miB, X[i]), maB = max(maB, X[i]);
	}
	LL ans = 0;

	if (v.empty()) {
		ans += max(maR - miR, 0);
		ans += max(maB - miB, 0);
	}
	else {
		ans += max(X[v[0]] - miR, 0);
		ans += max(X[v[0]] - miB, 0);
		ans += max(maR - X[v.back()], 0);
		ans += max(maB - X[v.back()], 0);
		for (int b = 0; b + 1 < v.size(); b++) {
			int x = v[b], y = v[b + 1];
			ans += X[y] - X[x];
			LL way1 = 0, way2 = 0;
			way1 += X[y] - X[x];
			
			int pr = X[x], pb = X[x];
			int mr = 0, mb = 0;
			for (int i = x + 1; i < y; i++) {
				if (C[i] == 'R')
					mr = max(mr, X[i] - pr), pr = X[i];
				else
					mb = max(mb, X[i] - pb), pb = X[i];
			}
			mr = max(mr, X[y] - pr);
			mb = max(mb, X[y] - pb);
			way2 += X[y] - X[x] - mr;
			way2 += X[y] - X[x] - mb;

			ans += min(way1, way2);
		}
	}

	cout << ans << endl;
	return 0;
}