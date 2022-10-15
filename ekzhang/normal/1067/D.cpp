#define NDEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXLG 34
#define EPS 1e-10
int N;
struct quest {
	int a, b;
	double p;
} Q[MAXN];
double K;
LL T;

typedef pair<double, double> line;
typedef vector<double> mat;

mat succ[MAXLG];

double intersect(const line& a, const line& b) {
	assert(abs(b.first - a.first) > EPS);
	return (a.second - b.second) / (b.first - a.first);
}

mat mul(mat a, mat b) { // 2x2
	return {
		a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3],
		a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]
	};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> Q[i].a >> Q[i].b >> Q[i].p;
		K = max(K, Q[i].b * Q[i].p);
	}

	sort(Q, Q + N, [](const quest& a, const quest& b) {
		return abs(a.p - b.p) > EPS ? a.p < b.p : a.a > b.a;
	});

	vector<line> cht;
	vector<double> xs;
	cht.emplace_back(Q[0].p, Q[0].p * Q[0].a);
	for (int i = 1; i < N; i++) {
		if (abs(Q[i].p - Q[i - 1].p) < EPS)
			continue;
		line cur = { Q[i].p, Q[i].p * Q[i].a };
		while (cht.size() >= 2 && intersect(cht.back(), cur)
				< intersect(cht.back(), cht[cht.size() - 2])) {
			cht.pop_back();
			xs.pop_back();
		}
		xs.push_back(intersect(cht.back(), cur));
		cht.push_back(cur);
	}
	xs.push_back(numeric_limits<double>::infinity());

	LL cur = 0; double val = 0;
	for (int i = 0; i < cht.size(); i++) {
		if (val > xs[i])
			continue;
		succ[0] = { 1 - cht[i].first, K - cht[i].second, 0, 1 };
		for (int j = 0; j < MAXLG - 1; j++)
			succ[j + 1] = mul(succ[j], succ[j]);

		for (int j = MAXLG - 1; j >= 0; j--) {
			if (cur + (1LL<<j) <= T) {
				double v2 = succ[j][0] * val + succ[j][1];
				if (v2 < xs[i]) {
					cur += (1LL<<j);
					val = v2;
				}
			}
		}

		if (cur == T)
			break;
		++cur, val = succ[0][0] * val + succ[0][1];
		assert(val > xs[i]);
	}

	assert(cur == T);
	cout << fixed << setprecision(10) << T * K - val << endl;
	return 0;
}