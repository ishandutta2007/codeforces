#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;
pair<int, int> P[MAXN];

const int S = 1 << 18;
int seg[2 * S];

void update(int x) {
	seg[S+x] = 1;
	for (int a = (S+x) / 2; a; a /= 2) {
		seg[a] = seg[2*a] + seg[2*a+1];
	}
}

// exclusive query
int query(int l, int r) {
	l++; // half-open query

	int ans = 0;
	for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			ans += seg[a];
			a++;
		}
		if (b & 1) {
			b--;
			ans += seg[b];
		}
	}
	return ans;
}

using ll = long long;
ll c2(ll a) {
	return a * (a+1) / 2;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		P[i] = {-y, x};
	}

	{ // do xs
		vector<int> xs;
		for (int i = 0; i < N; i++) {
			xs.push_back(P[i].second);
		}
		sort(xs.begin(), xs.end());
		xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
		for (int i = 0; i < N; i++) {
			P[i].second = int(lower_bound(xs.begin(), xs.end(), P[i].second) - xs.begin());
		}
	}

	sort(P, P + N);

	ll ans = 0;
	for (int st = 0; st < N; ) {
		int en = st;
		while (en < N && P[en].first == P[st].first) en++;

		cerr << "y = " << P[st].first << '\n';

		vector<int> pts;
		pts.push_back(-1);
		for (int i = st; i < en; i++) {
			int x = P[i].second;
			assert(-1 < x && x < N);
			pts.push_back(x);
			update(x);
		}
		pts.push_back(N);
		//sort(pts.begin(), pts.end());

		ans += c2(query(-1, N));
		for (int i = 0; i+1 < int(pts.size()); i++) {
			ans -= c2(query(pts[i], pts[i+1]));
		}

		st = en;
	}

	cout << ans << '\n';

	return 0;
}