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

	string s;
	cin >> s;

	unordered_map<string, int> cnt;
	for (int i = 1; i < n; i++) {
		cnt[s.substr(i-1, 2)]++;
	}

	int best = 0;
	string ans;
	for (const pair<string,int>& it : cnt) {
		if (it.second > best) {
			best = it.second;
			ans = it.first;
		}
	}
	cout << ans << nl;

	return 0;
}