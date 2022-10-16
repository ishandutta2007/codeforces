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
template<class T> inline void uax(T &a, T b) {return a > b ? (a = b, true) : false;}
template<class T> inline void uin(T &a, T b) {return a < b ? (a = b, true) : false;}

vector<vector<int>> g;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int p = read();
		--p;
		g[p].push_back(i + 1);
	}
	bool leaf[n];
	for (int i = 0; i < n; ++i) {
		leaf[i] = (sz(g[i]) == 0);
	}
	bool ok = 1;
	for (int i = 0; i < n; ++i) {
		if (leaf[i]) continue;
		int cnt = 0;
		for (int x: g[i]) {
			cnt += leaf[x];
		}
		ok &= (cnt >= 3);
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}