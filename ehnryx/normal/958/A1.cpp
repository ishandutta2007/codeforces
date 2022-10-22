#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	string real[n], fake[n];
	for (int i = 0; i < n; i++) cin >> real[i];
	for (int i = 0; i < n; i++) cin >> fake[i];

	char flip[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flip[i][j] = fake[i][n-1-j];
		}
	}

	for (int rot = 0; rot < 4; rot++) {
		bool fake_same = true;
		bool flip_same = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a, b;
				switch (rot) {
					case 0: a = i, b = j; 
							break;
					case 1: a = n-1-j, b = i;
							break;
					case 2: a = n-1-i, b = n-1-j;
							break;
					case 3: a = j, b = n-1-i;
							break;
				}
				if (real[i][j] != fake[a][b]) fake_same = false;
				if (real[i][j] != flip[a][b]) flip_same = false;
			}
		}
		if (fake_same || flip_same) {
			cout << "Yes" << nl;
			return 0;
		}
	}

	cout << "No" << nl;

	return 0;
}