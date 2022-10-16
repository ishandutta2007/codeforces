#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long infty = 1000000000000000ll;

/*input
7 3
1 1 3 3 3 2 1
*/
/*input
10 2
1 2 1 2 1 2 1 2 1 2
*/
/*input
13 3
1 2 2 2 1 2 1 1 1 2 2 1 1
*/

const int maxn = 100010, maxk = 20;
long long d[maxk + 1][maxn + 1];
int a[maxn];
int n, k;
int cnt[maxn] = {};
long long x = 0;
int mfr = 0;
int mto = 0;

void rek(int t, int fr, int to, int jmi, int jma) {
	if (fr > to) {
		return;
	}

	int mid = (fr + to) / 2;
	// debug(t, fr, to, jmi, jma, mid);
	int jjma = jma;

	if (jma > mid - 1) {
		jma = mid - 1;
	}

	while (mto < mid - 1) {
		mto++;
		x += cnt[a[mto]];
		cnt[a[mto]]++;
	}

	while (mfr <= jma) {
		cnt[a[mfr]]--;
		x -= cnt[a[mfr]];
		mfr++;
	}

	while (mto > mid - 1) {
		cnt[a[mto]]--;
		x -= cnt[a[mto]];
		mto--;
	}

	while (mfr > jma + 1) {
		mfr--;
		x += cnt[a[mfr]];
		cnt[a[mfr]]++;
	}

	// debug(t, mid, cnt, mfr, mto);

	int jopt = jma;

	for (int j = jma; j >= jmi; --j) {
		x += cnt[a[j]];
		cnt[a[j]]++;

		if (d[t][mid] > d[t - 1][j] + x) {
			d[t][mid] = d[t - 1][j] + x;
			jopt = j;
		}
	}

	mfr = jmi;
	mto = mid - 1;

	if (fr != to) {
		rek(t, fr,      mid - 1, jmi,  jopt);
		rek(t, mid + 1, to,      jopt, jjma);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	// n = 100000, k = 20;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		// a[i] = i % 50;
	}

	for (int t = 0; t <= k; ++t) {
		for (int i = 0; i <= n; ++i) {
			d[t][i] = infty;
		}
	}

	d[0][0] = 0;

	for (int t = 1; t <= k; ++t) {
		for (int i = 0; i < maxn; ++i) {
			cnt[i] = 0;
		}

		x = 0;
		mfr = 0;
		mto = -1;
		rek(t, 0, n, 0, n);
	}

	// for (int t = 0; t <= k; ++t) {
	// 	for (int i = 0; i <= n; ++i) {
	// 		cout << (d[t][i] >= infty ? -1 : d[t][i]) << " ";
	// 	}

	// 	cout << "\n";
	// }

	cout << d[k][n];
}