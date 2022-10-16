#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

const int MAXN = 66666;
int x[MAXN], v[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	for (int i = 0; i < n; ++i) {
		x[i] = read();
	}
	for (int i = 0; i < n; ++i) {
		v[i] = read();
	}
	double L = 0.0;
	double R = 1e9;
	for (int it = 0; it < 1000; ++it) {
		double M = (L + R) / 2;
		double left = -1e9;
		double right = 1e9;
		for (int i = 0; i < n; ++i) {
			left = max(left, 0.0 + x[i] - M * v[i]);
			right = min(right, 0.0 + x[i] + M * v[i]);
		}
		if (abs(left - right) < 1e-9 or left < right) {
			R = M;
		} else L = M;
	}
	cout << L << endl;
	return 0;
}