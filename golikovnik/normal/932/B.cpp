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

const int MAXN = 1111111;
int g[MAXN], pref[MAXN][10];

int f(int x) {
	int res = 1;
	while (x) {
		if (x % 10) res *= (x % 10);
		x /= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	for (int i = 1; i < MAXN; ++i) {
		if (i < 10) {
			g[i] = i;
		} else {
			g[i] = g[f(i)];
		}
	}
	for (int i = 1; i < MAXN; ++i) {
		for (int k = 0; k < 10; ++k) {
			pref[i][k] = pref[i - 1][k];
			pref[i][k] += (g[i] == k);
		}
	}
	int q = read();
	while (q--) {
		int L = read() - 1, R = read(), k = read();
		cout << pref[R][k] - pref[L][k] << endl;
	}
	return 0;
}