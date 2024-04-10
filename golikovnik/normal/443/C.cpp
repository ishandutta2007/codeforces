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

const int MAXN = 111;
pair<int, int> a[MAXN];

bool has(vector<int> &p, int k) {
	return find(all(p), k) != p.end();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	int MASK = 1 << 10;
	string clrs = "RGBYW";
	for (int i = 0; i < n; ++i) {
		string s = read<string>();
		a[i] = {clrs.find(s[0]), s[1] - '1'};
	}
	int res = 10;
	for (int mask = 0; mask < MASK; ++mask) {
		vector<int> knownColors, knownNumbers;
		for (int i = 0; i < 10; ++i) {
			if ((mask >> i) & 1) {
				if (i > 4) {
					knownNumbers.push_back(i % 5);
				} else knownColors.push_back(i);
			}
		}
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				bool okok = a[i].X == a[j].X && a[i].Y == a[j].Y;
				if (a[i].X != a[j].X) {
					okok |= (has(knownColors, a[i].X) || has(knownColors, a[j].X));
				}
				if (a[i].Y != a[j].Y) {
					okok |= (has(knownNumbers, a[i].Y) || has(knownNumbers, a[j].Y));
				}
				ok &= okok;
			}
		}
		if (ok) res = min(res, sz(knownNumbers) + sz(knownColors));
	}
	cout << res << endl;
	return 0;
}