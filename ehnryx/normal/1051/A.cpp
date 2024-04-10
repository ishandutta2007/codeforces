#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		int upper, lower, digit;
		upper = lower = digit = 0;
		for (char c : s) {
			digit += !!isdigit(c);
			upper += !!isupper(c);
			lower += !!islower(c);
		}

		if (!digit && !upper) {
			s[0] = 'A';
			s[1] = '9';
		} else if (!digit && !lower) {
			s[0] = 'a';
			s[1] = '9';
		} else if (!upper && !lower) {
			s[0] = 'A';
			s[1] = 'a';
		} else if (upper > 1) {
			for (char& c : s) {
				if (isupper(c)) {
					if (!digit) c = '1';
					if (!lower) c = 'a';
					break;
				}
			}
		} else if (lower > 1) {
			for (char& c : s) {
				if (islower(c)) {
					if (!digit) c = '1';
					if (!upper) c = 'A';
					break;
				}
			}
		} else if (digit > 1) {
			for (char& c : s) {
				if (isdigit(c)) {
					if (!upper) c = 'A';
					if (!lower) c = 'a';
					break;
				}
			}
		}

		cout << s << nl;
	}

	return 0;
}