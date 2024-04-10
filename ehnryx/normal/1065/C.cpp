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

	int n, k;
	cin >> n >> k;

	int goal = INF;
	int a[n];
	map<int,int> cnt;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		goal = min(a[i], goal);
	}

	ll ans = 0;
	ll cur = 0;
	ll vals = 0;
	for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
		if (it != cnt.rbegin()) {
			ll diff = prev(it)->first - it->first;
			ll allow = (k - cur) / vals;
			if (allow >= diff) {
				cur += diff * vals;
			} else {
				ans++;
				ll maxlen = k / vals;
				ans += (diff-allow) / maxlen;
				cur = vals * ((diff-allow) % maxlen);
			}
			//cerr << ans << nl;
		}
		vals += it->second;
	}
	if (cur > 0) ans++;

	cout << ans << nl;

	return 0;
}