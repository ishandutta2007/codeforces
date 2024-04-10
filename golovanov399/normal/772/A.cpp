#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int p = nxt();
	vector<pair<int, int>> a(n);
	vector<pair<double, int>> times(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
		times[i] = {1.0 * a[i].second / a[i].first, i};
	}

	sort(all(times));

	long long sum_a = 0;
	long long sum_b = 0;
	for (int i = 0; i < n; ++i) {
		sum_a += a[i].first;
		sum_b += a[i].second;
	}

	if (sum_a <= p) {
		puts("-1");
		return 0;
	}

	vector<double> tms;
	for (int i = 0; i < n; ++i) {
		tms.push_back(times[i].first);
	}

	double t = 1e20;
	double sb = 0, sa = 0;
	for (int i = 0; i < n; ++i) {
		sb += a[times[i].second].second;
		sa += a[times[i].second].first;
		if (sa - p < 1e-9) {
			continue;
		}
		t = min(t, sb / (sa - p));
	}

	cout << setprecision(9) << fixed;
	cout << t << "\n";

	return 0;
}