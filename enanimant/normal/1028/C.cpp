// August 27, 2018
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = (int) 1e9;
const int MAXN = 132674;

struct rect {
	long long l, r, b, t;
};

rect common_rect(rect &a, rect &b) {
	rect res;
	res.l = max(a.l, b.l);
	res.r = min(a.r, b.r);
	res.b = max(a.b, b.b);
	res.t = min(a.t, b.t);
	return res;
}

bool valid(rect r) {
	return r.l <= r.r && r.b <= r.t;
}

int N;
vector<rect> rects;
rect pca[MAXN + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> N;
	rects.resize(N);
	for (int i = 0; i < N; i++) {
		rect &r = rects[i];
		cin >> r.l >> r.b >> r.r >> r.t;
	}
	pca[0] = {-INF, INF, -INF, INF};
	for (int i = 1; i <= N; i++) {
		pca[i] = common_rect(pca[i - 1], rects[i - 1]);
	}

	rect common = {-INF, INF, -INF, INF};
	for (int i = N - 1; i >= 0; i--) {
		rect t = common_rect(pca[i], common);
		if (valid(t)) {
			cout << t.l << ' ' << t.b << '\n';
			return 0;
		}
		common = common_rect(common, rects[i]);
	}

	assert(0);


	return 0;
}