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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	int bad = 0;
	for (int i=0; i<p; i++) {
		map<char,int> cnt;
		int tot = 0;
		for (int j=0; i+j*p < n; j++) {
			cnt[s[i+j*p]]++;
			tot++;
		}
		if (cnt['.'] == 0 && (cnt['1'] == 0 || cnt['0'] == 0)) {
			assert(tot > 0);
			bad++;
		} else {
			if (tot == 1) bad++;
			for (int j=0; i+j*p < n; j++) {
				if (s[i+j*p] == '.') {
					s[i+j*p] = (cnt['0'] == 0 ? '0' : '1');
					cnt[s[i+j*p]]++;
				}
			}
		}
	}

	if (bad == p) cout << "No" << nl;
	else cout << s << nl;

	return 0;
}