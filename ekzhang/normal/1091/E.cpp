#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define INF (1LL<<60)
#define MAXN 500013
#define MAXSEG (1<<20)
int N;
int A[MAXN];
LL st[MAXSEG];
LL ps[MAXN], dp[MAXN], dp2[MAXN];
LL pre[MAXN], suf[MAXN];

void update(int i, LL x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) { st[node] = x; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

LL query(int s, int e, int lo=1, int hi=-1, int node=0) {
	if (hi == -1) hi = N;
	if (hi < s || lo > e) return INF;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1),
			query(s, e, mid + 1, hi, 2 * node + 2));
}

bool valid(int x) {
	int k = upper_bound(A + 1, A + N + 1, x, greater<int>()) - A - 1; // last guy, also overlap
	// cout << x << ' ' << k << endl;
	bool ok = true;
	if (k > x) {
		ok = ok && (pre[x] >= 0);
		ok = ok && (query(x + 1, k) + x >= 0);
	}
	else {
		ok = ok && (pre[k] >= 0);
	}

	// second half
	ok = ok && (suf[k] - x >= 0);

	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	int parity = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		parity = (parity + A[i]) % 2;
	}

	sort(A + 1, A + N + 1, greater<int>());

	for (int i = 1; i <= N; i++)
		ps[i] = ps[i - 1] + A[i];

	LL cur = 0;
	for (int i = 0; i <= N; i++) {
		if (i) {
			cur -= A[i];
			cur += 2 * (i - 1);

			int y = upper_bound(A + i + 1, A + N + 1, i, greater<int>()) - A;
			LL cc = cur;
			cc += (LL) i * (y - (i + 1));
			cc += ps[N] - ps[y - 1];
			update(i, cc);
			dp[i] = cc;
			// cout << i << ' ' << cc << endl;
			// cout << i << ' ' << A[i] << endl;
		}

		int y = upper_bound(A + i + 1, A + N + 1, i + 1, greater<int>()) - A;
		LL cc = cur;
		cc += (LL) (i + 1) * (y - (i + 1));
		cc += ps[N] - ps[y - 1];
		dp2[i] = cc;
	}

	pre[1] = dp[1] + 1;
	for (int i = 2; i <= N; i++)
		pre[i] = min(pre[i - 1], dp[i] + i);

	suf[N] = dp2[N] + 2 * N;
	for (int i = N - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], dp2[i] + 2 * i);
		// cout << i << ' ' << dp2[i] << ' ' << suf[i] << endl;
	}

	vector<int> ans;
	for (int x = parity; x <= N; x += 2) {
		if (valid(x))
			ans.push_back(x);
	}

	for (int x : ans)
		cout << x << ' ';
	if (ans.empty())
		cout << -1;

	cout << endl;
	return 0;
}