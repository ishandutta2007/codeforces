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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	string s = read<string>();
	int n = sz(s);
	int k = read();
	int mx = max(2, k / 2 * 2);
	for (int start = 0; start < n; ++start) {
		for (int length = 2; length <= n + k - start; length += 2) {
			bool ok = 1;
			for (int i = start; i < start + length / 2; ++i) {
				int j = i + length / 2;
				if (j >= n || i >= n) break;
				ok &= s[i] == s[j];
			}
			if (ok) mx = max(mx, length);
		}
	}	
	cout << mx << endl;
	return 0;
}