#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;
	int n = s.size();

	vector<int> index[26];
	vector<int> freq(26, 0);
	for (int i = 0; i < n; i++) {
		index[s[i]-'a'].push_back(i);
		freq[s[i]-'a']++;
	}

	ld ans = 0;
	int letters[26];
	for (int c = 0; c < 26; c++) {
		ld res = 0;
		for (int shift = 1; shift < n; shift++) {
			memset(letters, 0, sizeof letters);
			for (int it : index[c]) {
				letters[s[(it + shift) % n] - 'a']++;
			}

			int good = 0;
			for (int i = 0; i < 26; i++) {
				if (letters[i] == 1)
					good++;
			}
			res = max(res, (ld) good / n);
		}
		ans += res;
	}
	cout << ans << nl;

	return 0;
}