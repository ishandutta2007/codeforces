// October 28, 2018
// http://codeforces.com/problemset/problem/1043/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXN = 300000;

struct comp {
	int id;
	int x, y;
};

bool cmp(const comp &a, const comp &b) {
	return a.x - a.y < b.x - b.y;
}

bool cmp_id(const comp &a, const comp &b) {
	return a.id < b.id;
}

int N, M;
vector<comp> c;
long long xpsa[MAXN + 1], ypsa[MAXN + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N >> M;
	c.resize(N);
	for (int i = 0; i < N; i++) {
		c[i].id = i;
		cin >> c[i].x >> c[i].y;
	}
	sort(c.begin(), c.end(), cmp);
	xpsa[0] = ypsa[0] = 0;
	for (int i = 0; i < N; i++) {
		xpsa[i + 1] = xpsa[i] + c[i].x;
		ypsa[i + 1] = ypsa[i] + c[i].y;
	}
	vector<long long> ans(N);
	for (int i = 0; i < N; i++) {
		ans[c[i].id] += (long long) i * c[i].y + xpsa[i];
		ans[c[i].id] += (long long) (N - 1 - i) * c[i].x + ypsa[N] - ypsa[i + 1];
	}
	sort(c.begin(), c.end(), cmp_id);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		int s = min(c[a].x + c[b].y, c[a].y + c[b].x);
		ans[a] -= s;
		ans[b] -= s;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i];
		if (i != N - 1) cout << ' ';
	}
	cout << '\n';


	return 0;
}