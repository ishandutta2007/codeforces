#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int inline gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int N, K;
int a[200005], b[200005];
map<pair<int, int>, vector<int> > ps;
int id[200005];

double dist(int x, int y) {
	return sqrt(1ll * (a[x] - a[y]) * (a[x] - a[y]) + 1ll * (b[x] - b[y]) * (b[x] - b[y]));
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%d%d", a + i, b + i);
	for (int i = 2; i <= N; ++i) {
		int x = a[i] - a[1], y = b[i] - b[1];
		int g = gcd(x, y);
		x /= g; y /= g;
		if (y < 0 || (y == 0 && x < 0)) x *= -1, y *= -1;
		ps[make_pair(x, y)].push_back(i);
	}
	int kp;
	if (SZ(ps) == 1) kp = 1;
	else if (SZ(ps) == 2) {
		auto it = ps.begin();
		if (SZ(it->second) == 1) kp = it->second[0];
		else kp = (++it)->second[0];
	}
	else kp = 1;
	int ids = 0;
	for (int i = 1; i <= N; ++i) if (kp != i) id[++ids] = i;
	sort(id + 1, id + N, [&] (int x, int y) { return make_pair(a[x], b[x]) < make_pair(a[y], b[y]); });
	double ans;
	if (K == kp) {
		ans = dist(kp, id[1]) + dist(id[1], id[N - 1]);
		ans = min(ans, dist(kp, id[N - 1]) + dist(id[1], id[N - 1]));
	}
	else {
		int nid = 1;
		while (id[nid] != K) ++nid;
		ans = dist(K, id[1]) + dist(id[1], kp) + (nid == N - 1 ? 0 : dist(kp, id[nid + 1]) + dist(id[nid + 1], id[N - 1]));
		ans = min(ans, dist(K, id[N - 1]) + dist(id[N - 1], kp) + (nid == 1 ? 0 : dist(kp, id[nid - 1]) + dist(id[nid - 1], id[1])));
		ans = min(ans, dist(K, id[1]) + dist(id[1], kp) + (nid == N - 1 ? 0 : dist(kp, id[N - 1]) + dist(id[nid + 1], id[N - 1])));
		ans = min(ans, dist(K, id[N - 1]) + dist(id[N - 1], kp) + (nid == 1 ? 0 : dist(kp, id[1]) + dist(id[nid - 1], id[1])));
		ans = min(ans, dist(K, kp) + dist(kp, id[1]) + dist(id[1], id[N - 1]));
		ans = min(ans, dist(K, kp) + dist(kp, id[N - 1]) + dist(id[1], id[N - 1]));
		ans = min(ans, dist(K, id[N - 1]) + dist(id[N - 1], id[1]) + dist(id[1], kp));
		ans = min(ans, dist(K, id[1]) + dist(id[N - 1], id[1]) + dist(id[N - 1], kp));
		for (int nk = 2; nk <= nid; ++nk) ans = min(ans, dist(K, id[N - 1]) + dist(id[N - 1], id[nk]) + dist(id[nk], kp) + dist(kp, id[1]) + dist(id[1], id[nk - 1]));
		for (int nk = nid + 1; nk < N - 1; ++nk) ans = min(ans, dist(K, id[1]) + dist(id[1], id[nk]) + dist(id[nk], kp) + dist(kp, id[N - 1]) + dist(id[N - 1], id[nk + 1]));
		for (int nk = 2; nk <= nid; ++nk) ans = min(ans, dist(K, id[N - 1]) + dist(id[N - 1], id[nk]) + dist(id[nk], kp) + dist(kp, id[nk - 1]) + dist(id[1], id[nk - 1]));
		for (int nk = nid + 1; nk < N - 1; ++nk) ans = min(ans, dist(K, id[1]) + dist(id[1], id[nk]) + dist(id[nk], kp) + dist(kp, id[nk + 1]) + dist(id[N - 1], id[nk + 1]));
	}
	printf("%.10lf\n", ans);
	return 0;
}