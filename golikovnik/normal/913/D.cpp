#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int) x.size()
#define X first
#define Y second
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

const int N = 2e5 + 10;
pair<int, int> a[N]; //{t, a}
int n, T;

bool can(int k) {
	vector<int> tasks;
	for (int i = 0; i < n; ++i) {
		if (a[i].Y >= k) tasks.push_back(a[i].X);
	}
	if (sz(tasks) < k) return 0;
	sort(all(tasks));
	return accumulate(tasks.begin(), tasks.begin() + k, 0) <= T; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	n = read(), T = read();
	for (int i = 0; i < n; ++i) cin >> a[i].Y >> a[i].X;
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (can(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	l = max(l, 0);
	cout << l << endl << l << endl;
	vector<pair<int, int>> tasks;
	for (int i = 0; i < n; ++i) {
		if (a[i].Y >= l) tasks.push_back({a[i].X, i + 1});
	}
	sort(all(tasks));
	for (int i = 0; i < l; ++i) {
		cout << tasks[i].Y << " ";
	}
	cout << endl;
	return 0;
}