#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> frac;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, W;
int X[MAXN], V[MAXN];
int cnt[2];

pair<int, int> be[MAXN];
vector<pair<int, int> > line[2];

inline bool eq(frac f1, frac f2) {
	return (LL) f1.first * f2.second == (LL) f1.second * f2.first;
}

int fen[2 * MAXN];
void upd(int x) {
	for (x++; x < 2 * MAXN; x += x & -x)
		fen[x]++;
}
int qry(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += fen[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> W;
	vector<pair<frac, pair<int, int> > > v;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> V[i];
		v.push_back({{abs(X[i]), abs(V[i]) + W}, {+1, i}});
		v.push_back({{abs(X[i]), abs(V[i]) - W}, {-1, i}});
	}

	sort(v.begin(), v.end(), [](pair<frac, pair<int, int> > p1, pair<frac, pair<int, int> > p2) {
		LL x1 = (LL) p1.first.first * p2.first.second;
		LL x2 = (LL) p2.first.first * p1.first.second;
		if (x1 == x2)
			return p1.second > p2.second;
		return x1 < x2;
	});

	LL ans = 0;
	frac pre;
	int idx = 0;

	for (auto p : v) {
		int m = p.second.first;
		int i = p.second.second;
		int sgn = X[i] > 0;
		if (m == 1) ans += cnt[!sgn];
		cnt[sgn] += m;

		if (!eq(p.first, pre))
			++idx;
		pre = p.first;

		if (m == 1)
			be[i].first = idx;
		else
			be[i].second = 2 * N + 1 - idx;
	}

	for (int i = 0; i < N; i++) {
		line[X[i] > 0].push_back(be[i]);
	}

	for (int m = 0; m < 2; m++) {
		memset(fen, 0, sizeof fen);
		sort(line[m].begin(), line[m].end());
		for (auto p : line[m]) {
			ans += qry(p.second);
			upd(p.second);
		}
	}

	cout << ans << endl;
	return 0;
}